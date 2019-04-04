#include "Traitement/GestionTraitement.h"
#include "Interface/Fenetres/FenetreModifier.h"
#include "Interface/InterfacePrincipale.h"

#include "Traitement/FlouGaussien.h"

GestionTraitement::GestionTraitement(Controleur* controleur){
	this->controleur=controleur;
}

void GestionTraitement::ajouterTraitementListe(Traitement* t){ 
	traitements.push_back(t);
	controleur->getInterface()->ajouterTraitementListe(t->getNom()); 
}

std::list<Traitement*> GestionTraitement::recupererTraitement(){
	return traitements;
}

void GestionTraitement::ajouterTraitement(int num){
	cv::Mat image;
	if(traitements.empty()){
		image = controleur->getGestionImage()->getImageOriginale();
	}
	else{
		image = traitements.back()->getImageTraitee();
	}

	if(num==0){
		Traitement* nouveauTraitement = new FlouGaussien(this, image);
		ajouterTraitementListe(nouveauTraitement);
	}
}

Controleur* GestionTraitement::getControleur(){
	return controleur;
}

void GestionTraitement::imageTraitee(cv::Mat image){
	this->controleur->majImageTraitee(image);
}

Traitement* GestionTraitement::getTraitement(int position){
	std::list<Traitement*>::iterator it=traitements.begin();
	for(int i=0; i<position; i++){
		++it;
	}
	return *it;
}

void GestionTraitement::modifierTraitement(int position){
	reinterpret_cast<FlouGaussien*>(getTraitement(position))->modifier();
}

void GestionTraitement::supprimerTraitement(int position){
	std::list<Traitement*>::iterator it=traitements.begin();
	for(int i=0; i<position; i++){
		++it;
	}
	delete *it;
	traitements.erase(it);
	majTraitements();
}

void GestionTraitement::annulerAjout(){
	traitements.pop_back();
	majTraitements();
	controleur->getInterface()->annulerAjoutTraitementListe();
}

void GestionTraitement::majTraitements(){
	std::list<Traitement*>::iterator it;

	cv::Mat image = controleur->getGestionImage()->getImageOriginale();

	if(!traitements.empty()){
		for(it=traitements.begin(); it!=traitements.end(); ++it){
			image = reinterpret_cast<FlouGaussien*>(*it)->maj(image);
		}
	}
	else {
		controleur->getInterface()->majImage2(image);
		controleur->getInterface()->majImage3(image);
	}

	controleur->getInterface()->majImage4(image);
}