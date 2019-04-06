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

    list<Parametre> getParametres();

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
    Ui::FenetreModifier *ui;

    Traitement* traitement;

    list<Parametre> parametres;
    list<Valeur> sauvegardeValeurs;

    bool modification;

    void envoyerValeurs();
    void majValeursChamps(list<Valeur> valeurs);
    
};

#endif // FENETREMODIFIER_H
