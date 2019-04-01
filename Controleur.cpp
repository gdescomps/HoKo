#include "Controleur.h"

Controleur::Controleur(){
	gestionImage = new GestionImage;
	gestionTraitement = new GestionTraitement(this);
	interface = new InterfacePrincipale(this);
	
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