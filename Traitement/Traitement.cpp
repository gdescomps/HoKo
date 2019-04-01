#include "Traitement.h"

Traitement::Traitement() {
	fenetre = new FenetreModifier(this);
	fenetre->show();
}