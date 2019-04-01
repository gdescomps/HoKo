#include "Traitement.h"

Traitement::Traitement(GestionTraitement* gestionTraitement) {
	gestionTraitement=gestionTraitement;

	fenetre = new FenetreModifier(this);
	fenetre->show();
}