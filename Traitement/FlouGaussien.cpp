#include "FlouGaussien.h"

FlouGaussien::FlouGaussien(GestionTraitement* gestionTraitement, cv::Mat imageEntree) : 
	Traitement(gestionTraitement, imageEntree)
{
	this->nom="Flou Gaussien";
	this->id=0;
	appliquer(1,1,0);
}


cv::Mat FlouGaussien::appliquer(int largeurNoyau, int hauteurNoyau, double sigma)
{
	this->largeurNoyau=largeurNoyau;
	this->hauteurNoyau=hauteurNoyau;
	this->sigma=sigma;
    cv::GaussianBlur(this->imageEntree, this->imageTraitee, cv::Size(largeurNoyau,hauteurNoyau), sigma);
    gestionTraitement->imageTraitee(this->imageTraitee);
    return this->imageTraitee;
}

cv::Mat FlouGaussien::maj(cv::Mat imageEntree){
	this->imageEntree=imageEntree;
	cv::GaussianBlur(this->imageEntree, this->imageTraitee, cv::Size(this->largeurNoyau,this->hauteurNoyau), this->sigma);
	return this->imageTraitee;
}