#ifndef MASQUE_CPP
#define MASQUE_CPP

#include "Traitement.h"
#include <opencv2/core/utility.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;


class Masque : public Traitement{
	public:
		Masque(GestionTraitement* gestionTraitement, cv::Mat imageEntree) :
			Traitement(gestionTraitement, imageEntree)
		{
			this->nom="Masque";
			this->id=1;

			this->parametres.push_back(Parametre {_INT, "CAM", 3});

			appliquer(toValeurList(this->parametres));
			
			/*fenetre = new FenetreModifier(this);
			fenetre->show();*/
		}

		~Masque(){}

		virtual void appliquer(list<Valeur> valeurs){
			majParametres(valeurs);

			Mat imageMasquee;
			// this->imageEntree.copyTo(imageMasquee);
			this->imageEntree.copyTo(this->imageTraitee);
			
			// cv::rectangle(image, Point(420,205), Point(595,385), Scalar(255, 255, 255), -1);

			Point rook_points[1][9];
			rook_points[0][0]  = Point(0, 0);
			rook_points[0][1]  = Point(1920, 0);
			rook_points[0][2]  = Point(1920,450);
			rook_points[0][3]  = Point(734, 450);
			rook_points[0][4]  = Point(135, 660);
			rook_points[0][5]  = Point(135, 729);
			rook_points[0][6]  = Point(1920, 808);
			rook_points[0][7]  = Point(1920, 1080);
			rook_points[0][8]  = Point(0, 1080);
			  
			const Point* ppt[1] = { rook_points[0] };
			int npt[] = { 9 };

			fillPoly(this->imageTraitee, ppt, npt, 1, Scalar(0, 0, 0));

			//addWeighted(this->imageEntree, 0.5, masque3, 0.5, 0.0, image);
			// bitwise_and(this->imageEntree, masque3, image);
			//masque3.copyTo(image);

			//this->imageTraitee=imageMasquee;

			gestionTraitement->imageTraitee(this->imageTraitee);
		}

		virtual cv::Mat maj(cv::Mat imageEntree){
			this->imageEntree=imageEntree;
			appliquer(toValeurList(this->parametres));
			return this->imageTraitee;
		}

		virtual void modifier(){
			/*fenetre = new FenetreModifier(this, true);
			fenetre->show();*/
		}

};

#endif