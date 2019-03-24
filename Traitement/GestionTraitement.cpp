#include "Traitement/GestionTraitement.h"
#include "Interface/Fenetres/FenetreModifier.h"

GestionTraitement::GestionTraitement(Controleur* controleur){
	this->controleur=controleur;
}

void GestionTraitement::ajouterTraitementListe(Traitement* t){ 
	traitements.push_back(t); 
}
std::list<Traitement*> GestionTraitement::recupererTraitement(){
	return traitements;
}

void GestionTraitement::ajouterTraitement(int num){
	if(num==0){
		// Traitement* nouveauTraitement = new FlouGaussien;
		FenetreModifier *fenMod = new FenetreModifier();
	    fenMod->show();
	}
}