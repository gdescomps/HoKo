#include "Traitement/GestionTraitement.h"

void GestionTraitement::ajouterTraitement(Traitement* t){ 
	traitements.push_back(t); 
}
std::list<Traitement*> GestionTraitement::recupererTraitement(){
	return traitements;
}