#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "Interface/InterfacePrincipale.h"
#include "Image/GestionImage.h"
#include "Traitement/GestionTraitement.h"

class InterfacePrincipale;
class Controleur {

	private:
		GestionImage* gestionImage;
		GestionTraitement* gestionTraitement;
		InterfacePrincipale* interface;

	public:
		Controleur();

		InterfacePrincipale* getInterface();
		
	

};


#endif // CONTROLEUR_H