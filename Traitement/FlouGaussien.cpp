#ifndef FLOUGAUSSIEN_H
#define FLOUGAUSSIEN_H

#include "Traitement.h"

class FlouGaussien : public Traitement{
	public:
		FlouGaussien() {}
		~FlouGaussien() {};

		cv::Mat appliquer(cv::Mat imageEntree, int largeurNoyau, int hauteurNoyau, double sigma){
		    cv::GaussianBlur(imageEntree, this->imageTraitee, cv::Size(largeurNoyau,hauteurNoyau), sigma);
		    return imageTraitee;
		}
};

#endif // FLOUGAUSSIEN_H