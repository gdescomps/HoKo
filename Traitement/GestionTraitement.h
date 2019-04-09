#ifndef GESTIONTRAITEMENT_H
#define GESTIONTRAITEMENT_H

#include "Traitement/Traitement.h"
#include "Controleur.h"

#include <list>
	
	class Controleur;
	class Traitement;
	
	/**
	* Gestionnaire de traitement
	*/
	class GestionTraitement {
		private:
			/** Liste de pointeurs des traitements */
			std::list<Traitement*> traitements;
			
			/** Controleur de l'application */
			Controleur* controleur;

		public:

			GestionTraitement(Controleur* controleur);

			/** 
			* Ajoute un traitement dans la liste des traitements
			* \param t Traitement* pointeur vers un traitement à ajouter
			*/
			void ajouterTraitementListe(Traitement* t);
			
			/**
			* Renvoie la liste de traitements
			* \return list<Traitement*>
			*/
			std::list<Traitement*> recupererTraitement();
			
			/**
			* Renvoie le pointeur correspondant au traitement à la position voulue
			* \param position int position du traitement dans la liste
			* \return Traitement* pointeur vers le traitement
			*/
			Traitement* getTraitement(int position);

			/**
			* Ajoute un traitement en fonction de son id
			* \param id int identifiant du traitement, correspondant aux classes filles
			*/
			void ajouterTraitement(int id);

			/**
			* Déclenche la modification du traitement correspondant à la position dans la liste
			*/ 
			void modifierTraitement(int position);

			/**
			* Déclenche la suppression du traitement correspondant à la position dans la liste
			*/ 
			void supprimerTraitement(int position);

			/**
			* Intervertir deux traitement correspondant à leurs positions dans la liste
			*/ 
			void intervertirTraitements(int pos1, int pos2);

			/**
			* Annule l'ajout du dernier traitement
			*/
			void annulerAjout();

			/**
			* Applique le traitement correspondant à la position dans la liste
			*/
			void appliquerTraitement(int num);

			/**
			* Renvoie un pointeur vers le controleur
			*/
			Controleur* getControleur();

			/**
			* Demande la mise à jour de l'image traitée
			*/
			void imageTraitee(cv::Mat image);

			/**
			* Application de tous les traitements de la liste
			*/
			void majTraitements();

			/**
			* Exporte la liste des traitements dans le fichier choisi
			*/
			void exporterListeTraitement(char* nomFichier);

			/**
			* Importe la liste des traitements à partir du fichier choisi
			*/
			void importerListeTraitement(char* nomFichier);

	};

#endif // GESTIONTRAITEMENT_H