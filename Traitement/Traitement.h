#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;

#include <string>
using namespace std;

typedef union {
    int _int;
    double _double;
    bool _bool;
} Valeur;

enum type {_INT, _DOUBLE, _BOOL};

typedef struct {
	int type;
	string nom;
	Valeur valeur;
} Parametre;

#include "Interface/Fenetres/FenetreModifier.h"
#include "Traitement/GestionTraitement.h"


class FenetreModifier;
class GestionTraitement;


class Traitement {
	public:
		Traitement(GestionTraitement* gestionTraitement, Mat imageEntree);
		virtual ~Traitement();

		virtual void appliquer(list<Valeur> valeurs)=0;
		virtual Mat maj(Mat imageEntree)=0;
		virtual void modifier()=0;

		void majParametres(list<Valeur> valeurs);

		list<Parametre> getParametres(){return this->parametres;}

		list<Valeur> toValeurList(list<Parametre> parametres);

		Mat getImageEntree();
		Mat getImageTraitee();
		string getNom();

		

		void annulerAjout();
		void validerModification();

	protected:
		string nom;
		int id;
		
		Mat imageEntree;
		Mat imageTraitee;

		list<Parametre> parametres;

		FenetreModifier* fenetre;

		GestionTraitement* gestionTraitement;
};

#endif // TRAITEMENT_H