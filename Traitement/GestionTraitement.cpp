#include "Traitement/GestionTraitement.h"
#include "Interface/Fenetres/FenetreModifier.h"
#include "Interface/InterfacePrincipale.h"

#include "Traitement/FlouGaussien.h"
#include "Traitement/Masque.cpp"
#include "Traitement/SegmentationTSV.cpp"
#include "Traitement/FiltreCanny.cpp"
#include "Traitement/Contours.cpp"

#include <QFile>
#include <QXmlStreamWriter>


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

void GestionTraitement::ajouterTraitement(int id){
	cv::Mat image;
	if(traitements.empty()){
		image = controleur->getGestionImage()->getImageOriginale();
	}
	else{
		image = traitements.back()->getImageTraitee();
	}

	switch(id){
		case 0 : {
			Traitement* nouveauTraitement = new FlouGaussien(this, image);
			ajouterTraitementListe(nouveauTraitement);
		}break;

		case 1 : {
			Traitement* nouveauTraitement = new Masque(this, image);
			ajouterTraitementListe(nouveauTraitement);
		}break;

		case 2 : {
			Traitement* nouveauTraitement = new SegmentationTSV(this, image);
			ajouterTraitementListe(nouveauTraitement);
		}break;

		case 3 : {
			Traitement* nouveauTraitement = new FiltreCanny(this, image);
			ajouterTraitementListe(nouveauTraitement);
		}break;

		case 4 : {
			Traitement* nouveauTraitement = new Contours(this, image);
			ajouterTraitementListe(nouveauTraitement);
		}break;
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

void GestionTraitement::exporterListeTraitement(QString nomFichier){

	if(!traitements.empty()){

		QFile file(nomFichier+".hoklm");
		file.open(QIODevice::WriteOnly);

		
		QXmlStreamWriter stream(&file);
	    stream.setAutoFormatting(true);
	    stream.writeStartDocument();
	    
	    std::list<Traitement*>::iterator it;
		stream.writeStartElement("Configuration");
		for(it=traitements.begin(); it!=traitements.end(); ++it){
			
			
			stream.writeStartElement("Traitement");

			stream.writeAttribute( "id", QString::number((*it)->getId()));
			stream.writeAttribute( "nom", (*it)->getNom().c_str());

			list<Parametre> parametres = (*it)->getParametres();

			for (list<Parametre>::iterator itParam=parametres.begin(); itParam != parametres.end(); ++itParam){
				Valeur v;
				stream.writeStartElement("Parametre");
				stream.writeAttribute( "nom", (*itParam).nom.c_str() );
				switch((*itParam).type){
					case _INT :
						stream.writeAttribute( "type", QString::number(0) );
						stream.writeAttribute( "valeur", QString::number((*itParam).valeur._int));
						break;
					
					case _DOUBLE :
						stream.writeAttribute( "type", QString::number(1) );
						stream.writeAttribute( "valeur", QString::number((*itParam).valeur._double));
						break;

					default :
						printf("ERREUR : Type de variable (%i) de paramètre non trouvé \n", (*itParam).type);
						break;
				}
				stream.writeEndElement(); // Parametre
			}
			
			stream.writeEndElement(); // Traitement
			
		}
		stream.writeEndElement(); // Configuration
		stream.writeEndDocument();
		file.close();
	}

}
void GestionTraitement::importerListeTraitement(QString nomFichier){
	QFile file(nomFichier);

	if(file.open(QFile::ReadOnly | QFile::Text)){
		
    	QXmlStreamReader reader(&file);

	    if (reader.readNextStartElement()) {
	        if (reader.name() == "Configuration"){

	    		while(reader.readNextStartElement()){ // Traitements
	    	
		    		QString s = reader.attributes().value("id").toString();
		    		printf(s.toStdString().c_str());

		    		s = reader.attributes().value("nom").toString();
		    		printf(s.toStdString().c_str());

		    		printf("\n");

		    		while(reader.readNextStartElement()){ // Parametres
	    				
	    				printf("nom=");
			    		QString s = reader.attributes().value("nom").toString();
			    		printf(s.toStdString().c_str());

			    		printf(" type=");
			    		s = reader.attributes().value("type").toString();
			    		printf(s.toStdString().c_str());

			    		printf(" valeur=");
			    		s = reader.attributes().value("valeur").toString();
			    		printf(s.toStdString().c_str());

			    		printf("\n");
		    			reader.skipCurrentElement();
		    		}
	    			printf("\n");
	    		}
		    }
		}

	}
}