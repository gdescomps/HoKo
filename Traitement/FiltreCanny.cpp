#ifndef FILTRECANNY_CPP
#define FILTRECANNY_CPP

#include "Traitement.h"
#include <opencv2/core/utility.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;


class FiltreCanny : public Traitement{
	public:
		FiltreCanny(GestionTraitement* gestionTraitement, cv::Mat imageEntree, bool ouvrirFenetre=true) :
			Traitement(gestionTraitement, imageEntree)
		{
			this->nom="Filtre de Canny";
			this->id=3;

			this->parametres.push_back(Parametre {_INT, "Seuil 1", 100});
			this->parametres.push_back(Parametre {_INT, "Seuil 2", 200});
			this->parametres.push_back(Parametre {_INT, "Ouverture", 3});

			appliquer(toValeurList(this->parametres));
			
			if(ouvrirFenetre){
				fenetre = new FenetreModifier(this);
				fenetre->show();
			}
		}

		~FiltreCanny(){}

		virtual void appliquer(list<Valeur> valeurs){
			majParametres(valeurs);

			Mat imageGris;
			cvtColor(this->imageEntree, imageGris, COLOR_BGR2GRAY);
			
			list<Valeur>::iterator it=valeurs.begin();
			int seuil1 = (*it)._int; ++it;
			int seuil2 = (*it)._int; ++it;
			int ouverture = (*it)._int%3 * 2 + 3;


			Canny(imageGris, imageGris, seuil1, seuil2, ouverture);

			cvtColor(imageGris, this->imageTraitee, COLOR_GRAY2BGR);

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
		}

};

#endif