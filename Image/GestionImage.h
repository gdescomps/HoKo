#ifndef GESTIONIMAGE_H
#define GESTIONIMAGE_H

#include <opencv/cv.h>
#include <opencv/highgui.h>
/**
* Gestionnaire des images
*/
class GestionImage 
{

private:
	/** Booléen vrai si une image a été importée par l'utilisateur, faux sinon */
	bool importee;

	/** L'image importée, non modifiée*/
	cv::Mat imageOriginale;
public:
	/**
	* Constructeur de la classe, initialise importee à false. 
	*/
	GestionImage();

	/**
	* Teste si une image à été importée par l'utilisateur.
	* /return True si une image a été importée par l'utilisateur, False sinon.
	*/
	bool isImportee();

	/**
	* Retourne l' imageOriginale.
	* \return imageOriginale, l'image importée, non modifiée.
	*/
	cv::Mat getImageOriginale();

	/**
	* Définit l'imageOriginale.
	* \param image Image au format OpenCV Mat
	*/
	void setImageOriginale(cv::Mat image);
};

#endif // GESTIONIMAGE_H