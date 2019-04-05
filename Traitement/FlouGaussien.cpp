#include "FlouGaussien.h"

FlouGaussien::FlouGaussien(GestionTraitement* gestionTraitement, cv::Mat imageEntree) : 
	Traitement(gestionTraitement, imageEntree)
{
	this->nom="Flou Gaussien";
	this->id=0;

	this->parametres.push_back(Parametre {_INT, "hauteurNoyau", 1});
	this->parametres.push_back(Parametre {_INT, "largeurNoyau", 1});
	this->parametres.push_back(Parametre {_DOUBLE, "sigma", 0});

	appliquer(toValeurList(this->parametres));

	fenetre = new FenetreModifier(this);
	fenetre->show();
}


void FlouGaussien::appliquer(list<Valeur> valeurs){
	majParametres(valeurs);

	list<Valeur>::iterator it=valeurs.begin();
	int largeurNoyau = (*it)._int;

	++it; // Passer au paramètre suivant
	int hauteurNoyau = (*it)._int;

	++it;
	double sigma = (*it)._double;

	cv::GaussianBlur(this->imageEntree, this->imageTraitee, cv::Size(largeurNoyau,hauteurNoyau), sigma);

	gestionTraitement->imageTraitee(this->imageTraitee);
}


cv::Mat FlouGaussien::maj(cv::Mat imageEntree){
	this->imageEntree=imageEntree;
	appliquer(toValeurList(this->parametres));
	return this->imageTraitee;
}

void FlouGaussien::modifier(){
	fenetre = new FenetreModifier(this, true);
	fenetre->show();
}