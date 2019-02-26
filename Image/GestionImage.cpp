#include "Image/GestionImage.h"

GestionImage::GestionImage(){
	importee=false;
}

bool GestionImage::isImportee(){
	return importee;
}

cv::Mat GestionImage::getImageOriginale(){
	return imageOriginale;

}

void GestionImage::setImageOriginale(cv::Mat image){
	imageOriginale=image;
	importee=true;
}