#ifndef INTERFACEPRINCIPALE_H
#define INTERFACEPRINCIPALE_H

#include <QMainWindow>

// #include "Image/GestionImage.h"
// #include "Traitement/GestionTraitement.h"
#include "Controleur.h"

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>
#include <cmath>

namespace Ui {


class InterfacePrincipale;
}

class Controleur;

/**
* Interface Principale de l'application
*/
class InterfacePrincipale : public QMainWindow
{
	Q_OBJECT

public:
/**
 * Constructeur d' InterfacePrincipale.
 * \param    gestionImage       GestionImage gestionnaire des images.
 * \param    parent             QWidget *
 */
    explicit InterfacePrincipale(Controleur *controleur,  QWidget *parent = 0);
    
    ~InterfacePrincipale();

    /**
    * Met à jour le label correspondant à l'image 1 dans l'interface principale.
    * \param image Image au format OpenCV Mat remplaçant l'ancienne.
    */
    void majImage1(cv::Mat image);

    /**
    * Met à jour le label correspondant à l'image 2 dans l'interface principale.
    * \param image Image au format OpenCV Mat remplaçant l'ancienne.
    */
    void majImage2(cv::Mat image);

    /**
    * Met à jour le label correspondant à l'image 3 dans l'interface principale.
    * \param image Image au format OpenCV Mat remplaçant l'ancienne.
    */
    void majImage3(cv::Mat image);

    /**
    * Met à jour le label correspondant à l'image 4 dans l'interface principale.
    * \param image Image au format OpenCV Mat remplaçant l'ancienne.
    */
    void majImage4(cv::Mat image);

    /** Gestionnaire des images */
    // GestionImage *gestionImage; 

    // GestionTraitement gestionTraitement;

    Controleur* controleur;
   
private slots:
    /**
    * Importe une image et déclenche la mise à jour de l'affichage.
    * Déclenchée lors de l'appui sur le bouton du menu Image/Importer une image.
    * Ouvre une fenêtre de sélection de fichier, importe l'image choisie, la définie dans gestionImage et met à jour les 4 labels de l'interface.
    */
	void importerUneImage();

    /**
    * Affiche le .pdf du Guide d'utilisation
    * Déclenchée lors de l'appui sur le bouton du menu Aide/Guide d'utilisation
    */
	void afficherGuide();

    /**
    * Affiche le .pdf "À Propos"
    * Déclenchée lors de l'appui sur le bouton du menu Aide/À Propos de HoKo
    */
	void afficherApropos();

    /**
    * Enregistre l'image finale.
    * Déclenchée lors de l'appui sur le bouton du menu Image/Sauvegarder une image.
    * Ouvre une fenêtre de sélection de fichier et enregistre l'image finale à l'emplacement choisi.
    */
	void sauvegarderImageFinale();

    /**
    * Ajoute un traitement à la liste des traitements.
    * Déclenchée lors de l'appui sur le bouton "Ajouter". 
    * Ouvre la fenêtre de modification du traitement sélectionné.
    */
	void on_ajouterBouton_clicked();

    /**
    * Met à jour l'affichage des images. Déclenchée lors d'un redimensionnement de la fenêtre principale.
    */
    void resizeEvent(QResizeEvent*);

    
private:
    Ui::InterfacePrincipale *ui;

    /**
    * Redimensionne une image en fonction de la taille des labels de l'interface principale.
    * \param image Image au format OpenCV Mat à redimensionner.
    * \return Image redimensionnée au format OpenCV Mat.
    */
    cv::Mat redimensionner(cv::Mat image);
    
};

#endif // INTERFACEPRINCIPALE_H