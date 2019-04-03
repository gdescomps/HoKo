#ifndef FLOUGAUSSIEN_H
#define FLOUGAUSSIEN_H

#include "Traitement.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class FlouGaussien : public Traitement{
	private:
		int largeurNoyau;
		int hauteurNoyau;
		double sigma;


	public:
		FlouGaussien(GestionTraitement* gestionTraitement, cv::Mat imageEntree) : Traitement(gestionTraitement, imageEntree) {}
		~FlouGaussien() {}

		// void setLargeurNoyau(int largeurNoyau){
		// 	this->largeurNoyau=largeurNoyau;
		// }

		// void appliquer(int _largeurNoyau, int _hauteurNoyau, double _sigma)
		// {
			// cv::Mat image = gestionTraitement->getControleur()->getGestionImage()->getImageOriginale();
			//cv::Mat image1(this->getImageEntree());
			// gestionTraitement->ajouterTraitement(1);
			//cv::Mat image1(gestionTraitement->getControleur()->getGestionImage()->getImageOriginale());
			// cv::Mat imageSortie;
			// printf("largeurNoyau : %i ", _largeurNoyau);
			// printf("hauteurNoyau : %i ", _hauteurNoyau);
			// printf("sigma : %f \n", _sigma);

			// setLargeurNoyau(_largeurNoyau);
			// this->hauteurNoyau=hauteurNoyau;
			// this->sigma=sigma;
		    
		    // cv::GaussianBlur(image1, imageSortie, cv::Size(_largeurNoyau,_hauteurNoyau), _sigma);

		    // this->imageTraitee=imageSortie;

		    // return imageTraitee;
		    // gestionTraitement->getControleur()->getInterface()->majImage3(imageTraitee);

		cv::Mat appliquer(int largeurNoyau, int hauteurNoyau, double sigma);
		

};

#endif // FLOUGAUSSIEN_H