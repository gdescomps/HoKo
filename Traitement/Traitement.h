#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;

#include <string>
using namespace std;

/** Valeur d'un paramètre */
typedef union {
    int _int;
    double _double;
    bool _bool;
} Valeur;

/** Types de valeurs d'un paramètre */
enum type {_INT, _DOUBLE, _BOOL};

/** Paramètre de traitement */
typedef struct {
	int type;
	string nom;
	Valeur valeur;
} Parametre;

#include "Interface/Fenetres/FenetreModifier.h"
#include "Traitement/GestionTraitement.h"


class FenetreModifier;
class GestionTraitement;

/**
* Classe abstraite de traitement d'image
*/
class Traitement {
	public:
		/**
		* Initialise gestionTraitement et imageEntree.
		* Dans les classes filles, ajout des paramètres, application avec les paramètres initiaux,
		* création et affichage de la fenêtre de modification.
		* \param gestionTraitement GestionTraitement* gestionnaire de traitement
		* \param imageEntree Mat image à traiter
		*/
		Traitement(GestionTraitement* gestionTraitement, Mat imageEntree);

		/**
		* Détruit l'image entrée et traitée.
		*/
		virtual ~Traitement();

		/**
		* Applique le traitement à l'imageEntree dans l'imageTraitee.
		* Méthode virtuelle pure définie dans les classes filles.
		*/
		virtual void appliquer(list<Valeur> valeurs)=0;

		/**
		* Met à jour le traitement avec ses paramètres et une nouvelle imageEntree.
		* Méthode virtuelle pure définie dans les classes filles.
		* \param imageEntree Mat image à traiter
		*/
		virtual Mat maj(Mat imageEntree)=0;

		/**
		* Crée et affiche la fenetre de modification du traitement.
		* Méthode virtuelle pure définie dans les classes filles.
		*/
		virtual void modifier()=0;

		/**
		* \param valeurs list<Valeur> valeurs dans le même ordre que les paramètres
		* Met à jour les valeurs des paramètres du traitement.
		*/
		void majParametres(list<Valeur> valeurs);

		/**
		* Renvoit les paramètres du traitement.
		* \return list<Parametre> paramètres du traitement, dans l'ordre d'ajout dans le constructeur
		*/
		list<Parametre> getParametres(){return this->parametres;}

		/**
		* Renvoie les valeurs contenues par les paramètres entrés.
		* \return valeurs list<Parametre> paramètres du traitement, dans l'ordre d'ajout dans le constructeur
		*/
		list<Valeur> toValeurList(list<Parametre> parametres);

		/**
		* Renvoie l'imageEntree du traitement.
		* \return imageEntree Mat image à traiter
		*/
		Mat getImageEntree();

		/**
		* Renvoie l'imageTraitee du traitement.
		* \return imageTraitee Mat image traitée
		*/
		Mat getImageTraitee();

		/**
		* Revoie le nom du traitement.
		* \return nom du traitement
		*/
		string getNom();

		/**
		* Appel au gestionnaire de traitement pour annuler l'ajout du traitement.
		*/
		void annulerAjout();

		/**
		* Appel au gestionnaire de traitement pour mettre à jour tous les traitements.
		*/
		void validerModification();

	protected:
		/** Nom du traitement */
		string nom;

		/** Identifiant du traitement, défini dans les classes filles */
		int id;
		
		/** Image à traiter */
		Mat imageEntree;

		/** Image sur laquelle le traitement est appliquée */
		Mat imageTraitee;

		/** Liste des paramètres */
		list<Parametre> parametres;

		/** Fenetre de modification des paramètres */
		FenetreModifier* fenetre;

		/** Gestionnaire de traitements */
		GestionTraitement* gestionTraitement;
};

#endif // TRAITEMENT_H