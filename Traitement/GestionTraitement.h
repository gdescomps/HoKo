#ifndef GESTIONTRAITEMENT_H
#define GESTIONTRAITEMENT_H

#include "Traitement/Traitement.h"
#include <list>

	class GestionTraitement {
		private:
			std::list<Traitement*> traitements;

		public:
			void ajouterTraitement(Traitement* t){ 
				traitements.push_back(t); 
			}
			std::list<Traitement*> recupererTraitement(){
				return traitements;
			}

	};

#endif // GESTIONTRAITEMENT_H