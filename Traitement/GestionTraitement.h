#ifndef GESTIONTRAITEMENT_H
#define GESTIONTRAITEMENT_H

#include "Traitement/Traitement.h"
#include "Controleur.h"

#include <list>
	
	class Controleur;
	
	class GestionTraitement {
		private:
			std::list<Traitement*> traitements;
			Controleur* controleur;

		public:
			GestionTraitement(Controleur* controleur);

			void ajouterTraitementListe(Traitement* t);
			std::list<Traitement*> recupererTraitement();

			void ajouterTraitement(int num);

	};

#endif // GESTIONTRAITEMENT_H