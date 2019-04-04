#include "Traitement.h"

Traitement::Traitement(GestionTraitement* gestionTraitement, cv::Mat imageEntree) {
	this->gestionTraitement=gestionTraitement;
	this->imageEntree=imageEntree;
	
	
	fenetre = new FenetreModifier(this);
	fenetre->show();
}

cv::Mat Traitement::getImageEntree(){
	return this->imageEntree;
}

cv::Mat Traitement::getImageTraitee(){
	return this->imageTraitee;
}

std::string Traitement::getNom(){
	return this->nom;
}

void Traitement::modifier(){
	fenetre = new FenetreModifier(this);
	fenetre->show();
}

void Traitement::validerModification(){
	gestionTraitement->majTraitements();
}