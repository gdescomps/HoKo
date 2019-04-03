#include "FlouGaussien.h"

cv::Mat FlouGaussien::appliquer(int largeurNoyau, int hauteurNoyau, double sigma)
{
	this->largeurNoyau=largeurNoyau;
	this->hauteurNoyau=hauteurNoyau;
	this->sigma=sigma;
    cv::GaussianBlur(this->imageEntree, this->imageTraitee, cv::Size(largeurNoyau,hauteurNoyau), sigma);
    gestionTraitement->imageTraitee(this->imageTraitee);
    return this->imageTraitee;
}