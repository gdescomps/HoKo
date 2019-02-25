#ifndef GESTIONIMAGE_H
#define GESTIONIMAGE_H

#include <opencv/cv.h>
#include <opencv/highgui.h>

class GestionImage 
{

private:
	bool importee;
	cv::Mat imageOriginale;
public:
	GestionImage();
	bool isImportee();
	cv::Mat getImageOriginale();
	void setImageOriginale(cv::Mat image);
};

#endif // GESTIONIMAGE_H