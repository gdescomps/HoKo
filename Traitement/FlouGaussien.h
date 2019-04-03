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
		FlouGaussien(GestionTraitement* gestionTraitement, cv::Mat imageEntree);
		~FlouGaussien() {}

		cv::Mat appliquer(int largeurNoyau, int hauteurNoyau, double sigma);
		cv::Mat maj(cv::Mat imageEntree);

};

#endif // FLOUGAUSSIEN_H