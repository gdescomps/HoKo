#ifndef GESTIONTRAITEMENT_H
#define GESTIONTRAITEMENT_H

#include "Traitement/Traitement.h"
#include <list>

	class GestionTraitement {
		private:
			std::list<Traitement*> traitements;

		public:
			void ajouterTraitement(Traitement* t);
			std::list<Traitement*> recupererTraitement();

	};

#endif // GESTIONTRAITEMENT_H