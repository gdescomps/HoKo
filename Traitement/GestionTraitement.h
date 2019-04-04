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
			
			Controleur* controleur;

		public:

			GestionTraitement(Controleur* controleur);

			void ajouterTraitementListe(Traitement* t);
			std::list<Traitement*> recupererTraitement();
			Traitement* getTraitement(int position);

			void ajouterTraitement(int num);

			void modifierTraitement(int position);
			void supprimerTraitement(int position);

			void annulerAjout();

			void appliquerTraitement(int num);

			Controleur* getControleur();

			void imageTraitee(cv::Mat image);

			void majTraitements();

	};

#endif // GESTIONTRAITEMENT_H