#include "Controleur.h"

Controleur::Controleur(){
	this->gestionImage = new GestionImage;
	this->gestionTraitement = new GestionTraitement(this);
	this->interface = new InterfacePrincipale(this);
	
}

InterfacePrincipale* Controleur::getInterface(){
	return this->interface;
}

GestionImage* Controleur::getGestionImage(){
	return this->gestionImage;
}

GestionTraitement* Controleur::getGestionTraitement(){
	return this->gestionTraitement;
}

void Controleur::majImageTraitee(cv::Mat image){
	this->getInterface()->majImage3(image);
	this->getInterface()->majImage4(image);
}