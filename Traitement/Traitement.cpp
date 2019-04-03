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