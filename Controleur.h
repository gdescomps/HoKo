#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "Interface/InterfacePrincipale.h"
#include "Image/GestionImage.h"
#include "Traitement/GestionTraitement.h"

class Controleur {

	private:
		GestionImage* gestionImage;
		GestionTraitement* gestionTraitement;
		InterfacePrincipale* interface;

	public:
		Controleur(){
			gestionImage = new GestionImage;
			gestionTraitement = new GestionTraitement;
			interface = new InterfacePrincipale(*gestionImage, *gestionTraitement);
			
		}

		InterfacePrincipale* getInterface(){
			return this->interface;
		}


};


#endif // CONTROLEUR_H