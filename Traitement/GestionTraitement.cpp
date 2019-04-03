#include "Traitement/GestionTraitement.h"
#include "Interface/Fenetres/FenetreModifier.h"

#include "Traitement/FlouGaussien.h"

GestionTraitement::GestionTraitement(Controleur* controleur){
	this->controleur=controleur;
}

void GestionTraitement::ajouterTraitementListe(Traitement* t){ 
	traitements.push_back(t); 
}

std::list<Traitement*> GestionTraitement::recupererTraitement(){
	return traitements;
}

void GestionTraitement::ajouterTraitement(int num){
	if(num==0){
		Traitement* nouveauTraitement = new FlouGaussien(this, controleur->getGestionImage()->getImageOriginale());
		ajouterTraitementListe(nouveauTraitement);
	}
}

Controleur* GestionTraitement::getControleur(){
	return controleur;
}

void GestionTraitement::imageTraitee(cv::Mat image){
	this->controleur->majImageTraitee(image);
}