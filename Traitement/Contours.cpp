#ifndef CONTOURS_CPP
#define CONTOURS_CPP

#include "Traitement.h"
#include <opencv2/core/utility.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <string>
using namespace std;

using namespace cv;


class Contours : public Traitement{
	public:
		Contours(GestionTraitement* gestionTraitement, cv::Mat imageEntree) :
			Traitement(gestionTraitement, imageEntree)
		{
			this->nom="Détection de contours";
			this->id=4;

			this->parametres.push_back(Parametre {_INT, "Surface minimum", 0});
			this->parametres.push_back(Parametre {_INT, "Surface maximum", 100});
			this->parametres.push_back(Parametre {_DOUBLE, "Compacité minimum", 0});
			this->parametres.push_back(Parametre {_DOUBLE, "Compacité maximum", 2});

			
			fenetre = new FenetreModifier(this);
			fenetre->show();

			appliquer(toValeurList(this->parametres));
		}

		~Contours(){}

		virtual void appliquer(list<Valeur> valeurs){
			majParametres(valeurs);

			Mat imageGris;
			cvtColor(this->imageEntree, imageGris, COLOR_BGR2GRAY);
			
			list<Valeur>::iterator it=valeurs.begin();
			int surfaceMin = (*it)._int; ++it;
			int surfaceMax = (*it)._int; ++it;
			double compaciteMin = (*it)._double; ++it;
			double compaciteMax = (*it)._double;

			vector<vector<Point>> contoursTous, contoursSurface, contours;
			vector<Vec4i> hierarchy;

			findContours(imageGris, contoursTous, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);


			double contourAREA, contourLENGTH , compacityCA , contourAREAca , contourLENGTHca;

			for (unsigned int i = 0; i < contoursTous.size(); i++)
			{
				contourAREA =  contourArea(contoursTous[i]);

				if ( contourAREA <= surfaceMax && contourAREA >= surfaceMin)
				{
					contoursSurface.push_back(contoursTous[i]);
				}
			}

			

			for (unsigned int i = 0; i < contoursSurface.size(); i++)
			{		
				contourAREAca = contourArea(contoursSurface[i]);
				contourLENGTHca = arcLength(contoursSurface[i] , true); 
				compacityCA = ((4 * M_PI* contourAREAca) / (pow(contourLENGTHca ,2)));

				if (compacityCA <= compaciteMax && compacityCA >= compaciteMin)
				{
					contours.push_back(contoursSurface[i]);
				}
			}
			

			// cvtColor(imageGris, this->imageTraitee, COLOR_GRAY2BGR);
			gestionTraitement->getControleur()->getGestionImage()->getImageOriginale().copyTo(this->imageTraitee);
			
			for (unsigned int i = 0; i <  contours.size(); ++i)
			{
				Point2f points[4];
				Point2f center;
				float radius;
				Rect rect;
				RotatedRect rotate_rect;

				//COMPUTE THE BOUNDING RECT, ROTATED BOUNDING RECT , MINIMUM ENCLOSING CIRCLE.
				rect = boundingRect(contours[i]);
				rotate_rect = minAreaRect(contours[i]);
				minEnclosingCircle(contours[i], center, radius);

				rotate_rect.points(points);

				vector< vector< Point> > polylines;

				vector<Moments> mu(contours.size());;
				mu[i] = moments(contours[i], false);
				vector<Point2f> mc(contours.size());;
				mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);

				polylines.resize(1);
				for (int j = 0; j < 4; ++j)
					polylines[0].push_back(points[j]);

				//DRAW THYEM ON THE BOUNDING IMAGE ! 
				cv::rectangle(this->imageTraitee, rect, Scalar(0, 0, 255), 2);
				// cv::polylines(this->imageTraitee, polylines, true, Scalar(0, 255, 0), 2); // ====> just to try : optional dreawing 
				// cv::circle(this->imageTraitee, center, radius, Scalar(255, 0, 0), 2);  //=====> cool to use 
				cv::circle(this->imageTraitee, mc[i], 4, Scalar(0, 200, 100), -1, 8, 0);

			}
			
			fenetre->afficherInfo("Nombre de contours : "+to_string(contours.size()));

			gestionTraitement->imageTraitee(this->imageTraitee);
		}

		virtual cv::Mat maj(cv::Mat imageEntree){
			this->imageEntree=imageEntree;
			appliquer(toValeurList(this->parametres));
			return this->imageTraitee;
		}

		virtual void modifier(){
			fenetre = new FenetreModifier(this, true);
			fenetre->show();
			appliquer(toValeurList(this->parametres));
		}

};

#endif