#include "Traitement/GestionTraitement.h"
#include "Interface/Fenetres/FenetreModifier.h"
#include "Interface/InterfacePrincipale.h"

#include "Traitement/FlouGaussien.h"

GestionTraitement::GestionTraitement(Controleur* controleur){
	this->controleur=controleur;
}

void GestionTraitement::ajouterTraitementListe(Traitement* t){ 
	traitements.push_back(t);
	// controleur->getInterface()->ajouterTraitementListe(t->getNom()+" "+std::to_string(traitements.size())); 
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
	getTraitement(position)->modifier();
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

void GestionTraitement::intervertirTraitements(int pos1, int pos2){
	std::list<Traitement*>::iterator it1=traitements.begin();
	for(int i=0; i<pos1; i++){
		++it1;
	}

	std::list<Traitement*>::iterator it2=traitements.begin();
	for(int i=0; i<pos2; i++){
		++it2;
	}

	std::iter_swap(it1,it2);
	majTraitements();
}

void GestionTraitement::annulerAjout(){
	traitements.pop_back();
	controleur->getInterface()->annulerAjoutTraitementListe();
	majTraitements();
}

void GestionTraitement::majTraitements(){
	std::list<Traitement*>::iterator it;

	cv::Mat image = controleur->getGestionImage()->getImageOriginale();

	if(!traitements.empty()){
		for(it=traitements.begin(); it!=traitements.end(); ++it){
			image = (*it)->maj(image);
		}
	}
	else {
		controleur->getInterface()->majImage2(image);
		controleur->getInterface()->majImage3(image);
	}

	controleur->getInterface()->majImage4(image);
}