#ifndef FENETREMODIFIER_H
#define FENETREMODIFIER_H

#include <QDialog>
#include "Interface/InterfacePrincipale.h"
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
    FenetreModifier(Traitement* traitement, int largeurNoyau=1, int hauteurNoyau=1, double sigma=0, bool modification=false, QWidget *parent = nullptr);

    ~FenetreModifier();

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
    * Déclenchée lors de la modification de la valeur du spinBoxLargeurNoyau.
    */
	void on_spinBoxLargeurNoyau_valueChanged(int largeurNoyau);

    /**
    * Applique le traitement avec les nouveaux paramètres et provoque la mise à jour de l'image dans l'interface principale.
    * Déclenchée lors de la modification de la valeur du spinBoxHauteurNoyau.
    */
    void on_spinBoxHauteurNoyau_valueChanged(int hauteurNoyau);

    /**
    * Applique le traitement avec les nouveaux paramètres et provoque la mise à jour de l'image dans l'interface principale.
    * Déclenchée lors de la modification de la valeur du doubleSpinBoxSigma.
    */
    void on_doubleSpinBoxSigma_valueChanged(double sigma);
private:
    Ui::FenetreModifier *ui;

    /** L'interface principale de l'application */
    // InterfacePrincipale *interface;

    Traitement* traitement;

    int largeurNoyau;
    int hauteurNoyau;
    double sigma;
    bool modification;
    
    /**
    * Applique un flou gaussien (fonction OpenCV GaussianBlur)
    * \param largeurNoyau Hauteur du noyau du flou gaussien
    * \param hauteurNoyau Largeur du noyau du flou gaussien
    * \param sigma Sigma du flou gaussien
    * \return Image traitée au format OpenCV Mat
    */
    void flouGaussien(int largeurNoyau, int hauteurNoyau, double sigma);
};

#endif // FENETREMODIFIER_H
