#include "Controleur.h"

Controleur::Controleur(){
	gestionImage = new GestionImage;
	gestionTraitement = new GestionTraitement;
	interface = new InterfacePrincipale(this);
	
}

InterfacePrincipale* Controleur::getInterface(){
	return this->interface;
}

GestionImage* Controleur::getGestionImage(){
	return this->gestionImage;
}