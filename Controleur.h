#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "Interface/InterfacePrincipale.h"
#include "Image/GestionImage.h"
#include "Traitement/GestionTraitement.h"

class InterfacePrincipale;
class GestionTraitement;

/** Controleur de l'application, fait le lien entre les classes de la Vue et du Modele */
class Controleur {

	private:
		/** Gestionnaire d'image de l'application */
		GestionImage* gestionImage;

		/** Gestionnaire de traitement de l'application */
		GestionTraitement* gestionTraitement;

		/** Interface principale de l'application */
		InterfacePrincipale* interface;

	public:
		/**
		* Contructeur du controleur, crée le gestionnaire d'image, de traitements et l'interface principale
		*/
		Controleur();

		/*
		* Retourne un pointeur vers l'interface principale
		* \return InterfacePrincipale* pointant vers l'interface principale
		*/
		InterfacePrincipale* getInterface();

		/**
		* Retourne un pointeur vers le gestionnaire d'image
		* \return GestionImage* pointant vers le gestionnaire d'image 
		*/
		GestionImage* getGestionImage();

		/**
		* Retourne un pointeur vers le gestionnaire de traitement
		* \return GestionTraitement* pointant vers le gestionnaire de traitement
		*/
		GestionTraitement* getGestionTraitement();

		/**
		* Met à jour l'image 3 dans l'interface
		* \param image Image au format OpenCV Mat remplaçant l'ancienne.
		*/
		void majImageTraitee(cv::Mat image);
};


#endif // CONTROLEUR_H