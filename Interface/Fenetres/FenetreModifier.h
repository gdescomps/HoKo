#ifndef FENETREMODIFIER_H
#define FENETREMODIFIER_H

#include <QDialog>
// #include "Interface/InterfacePrincipale.h"
#include "Traitement/Traitement.h"

namespace Ui {

class FenetreModifier;
}

class Traitement;

/**
* Fenêtre de modification des paramètres d'un traitement.
*/
class FenetreModifier : public QDialog
{
    Q_OBJECT

public:
    
    /**
    * Constructeur de FenetreModifier
    * \param interface L'interface principale de l'application
    * \param parent QWidget*
    */
    FenetreModifier(Traitement* traitement, bool modification=false, QWidget *parent = nullptr);

    ~FenetreModifier();

    /**
    * Renvoie la liste des paramètres
    * \return list<Parametre> liste des paramètres
    */
    list<Parametre> getParametres();

    /**
    * Affiche un texte dans un label situé entre les paramètres et les boutons
    * \param texte string texte à afficher
    */
    void afficherInfo(string texte);

private slots:
    /**
    * Enregistre les paramètres et ferme la fenêtre.
    * Déclenchée lors de l'appui sur le bouton "Valider".
    */
    void on_validerBouton_clicked();

    /**
    * Ferme la fenêtre sans enregistrer les paramètres, si le traitement viens d'être ajouté, il est supprimé.
    * Déclenchée lors de l'appui sur le bouton "Annuler".
    */
    void on_annulerBouton_clicked();

    /**
    * Applique le traitement avec les nouveaux paramètres et provoque la mise à jour de l'image dans l'interface principale.
    * Déclenchée lors de l'appui sur le bouton "Appliquer".
    */
    void on_appliquerBouton_clicked();

    
private:
    /**
    * Interface Qt
    */
    Ui::FenetreModifier *ui;

    /**
    * Traitement correspondant à la fenêtre
    */
    Traitement* traitement;

    /**
    * Liste des paramètres du traitement 
    */
    list<Parametre> parametres;


    /**
    * Liste des valeurs sauvegardées dans le cas de la modification d'un traitement déjà créé
    */
    list<Valeur> sauvegardeValeurs;

    /** Indicateur d'état : modification(vrai) ou création(false) */
    bool modification;

    /** Envoi des valeurs des paramètres au traitement */ 
    void envoyerValeurs();
    
};

#endif // FENETREMODIFIER_H
