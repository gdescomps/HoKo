#include "Traitement.h"

Traitement::Traitement(GestionTraitement* gestionTraitement, Mat imageEntree) {
	this->gestionTraitement=gestionTraitement;
	this->imageEntree=imageEntree;
}

Traitement::~Traitement(){
	~imageEntree;
	~imageTraitee;
}

void Traitement::majParametres(list<Valeur> valeurs){
	list<Valeur>::iterator itVal=valeurs.begin();
	for (list<Parametre>::iterator it=this->parametres.begin(); it != this->parametres.end(); ++it){
		switch((*it).type){
			case _INT :
				(*it).valeur._int = (*itVal)._int;
				break;
			
			case _DOUBLE :
				(*it).valeur._double = (*itVal)._double;
				break;

			default :
				printf("ERREUR : Type de variable (%i) de paramètre non trouvé \n", (*it).type);
				break;
		}
		++itVal;
	}
}

list<Valeur> Traitement::toValeurList(list<Parametre> parametres){
	list<Valeur> valeurs;
	for (list<Parametre>::iterator it=parametres.begin(); it != parametres.end(); ++it){
		Valeur v;
		switch((*it).type){
			case _INT :
				v._int = (*it).valeur._int;
				break;
			
			case _DOUBLE :
				v._double = (*it).valeur._double;
				break;

			default :
				printf("ERREUR : Type de variable (%i) de paramètre non trouvé \n", (*it).type);
				break;
		}
		valeurs.push_back(v);
	}
	return valeurs;
}

cv::Mat Traitement::getImageEntree(){
	return this->imageEntree;
}

cv::Mat Traitement::getImageTraitee(){
	return this->imageTraitee;
}

std::string Traitement::getNom(){
	return this->nom;
}

void Traitement::annulerAjout(){
	gestionTraitement->annulerAjout();
}

void Traitement::validerModification(){
	gestionTraitement->majTraitements();
}