#ifndef GESTIONTRAITEMENT_H
#define GESTIONTRAITEMENT_H

#include "Traitement/Traitement.h"
#include "Controleur.h"

#include <list>
	
	class Controleur;
	class Traitement;
	
	class GestionTraitement {
		private:
			std::list<Traitement*> traitements;
			

		public:
			Controleur* controleur;

			GestionTraitement(Controleur* controleur);

			void ajouterTraitementListe(Traitement* t);
			std::list<Traitement*> recupererTraitement();
			Traitement* getTraitement(int position);

			void ajouterTraitement(int num);
			void appliquerTraitement(int num);

			Controleur* getControleur();

			void imageTraitee(cv::Mat image);

	};

#endif // GESTIONTRAITEMENT_H