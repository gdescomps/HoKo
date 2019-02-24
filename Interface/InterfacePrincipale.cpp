#include "Interface/InterfacePrincipale.h"
#include "ui_InterfacePrincipale.h"
#include "Fenetres/FenetreModifier.h"
#include "Image/GestionImage.h"

#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>
#include <cmath>
#include <QResizeEvent>

using namespace cv;

InterfacePrincipale::InterfacePrincipale(GestionImage gestionImage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InterfacePrincipale)
{
    ui->setupUi(this);
    gestionImage = gestionImage;
}

InterfacePrincipale::~InterfacePrincipale()
{
    delete ui;
}

void InterfacePrincipale::importerUneImage()
{
	QString nomImage = QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::currentPath(),tr("Image Files [ *.jpg , *.jpeg , *.bmp , *.png , *.gif]"));
	char* cheminImage = nomImage.toLocal8Bit().data();

	gestionImage.setImageOriginale(cv::imread(cheminImage));
	
	cv::Mat imageMat=gestionImage.getImageOriginale();

	majImage1(imageMat);
	majImage2(imageMat);
	majImage3(imageMat);
	majImage4(imageMat);
}

void InterfacePrincipale::resizeEvent(QResizeEvent* event)
{
	if(gestionImage.isImportee()){
		
		cv::Mat imageMat=gestionImage.getImageOriginale();

		majImage1(imageMat);
		majImage2(imageMat);
		majImage3(imageMat);
		majImage4(imageMat);
	}
}


void InterfacePrincipale::on_ajouterBouton_clicked()
{
    if(gestionImage.isImportee()){
	    FenetreModifier *fenMod = new FenetreModifier(this);
	    fenMod->show();
	}
}

void InterfacePrincipale::majImage1(cv::Mat image){
	image = redimensionner(image);
	QImage imageQ = QImage((const unsigned char*)image.data,image.cols,image.rows,QImage::Format_RGB888).rgbSwapped();
	ui->image1->setPixmap(QPixmap::fromImage(imageQ));
}

void InterfacePrincipale::majImage2(cv::Mat image){
	image = redimensionner(image);
	QImage imageQ = QImage((const unsigned char*)image.data,image.cols,image.rows,QImage::Format_RGB888).rgbSwapped();
	ui->image2->setPixmap(QPixmap::fromImage(imageQ));
}

void InterfacePrincipale::majImage3(cv::Mat image){
	image = redimensionner(image);
	QImage imageQ = QImage((const unsigned char*)image.data,image.cols,image.rows,QImage::Format_RGB888).rgbSwapped();
	ui->image3->setPixmap(QPixmap::fromImage(imageQ));
}

void InterfacePrincipale::majImage4(cv::Mat image){
	image = redimensionner(image);
	QImage imageQ = QImage((const unsigned char*)image.data,image.cols,image.rows,QImage::Format_RGB888).rgbSwapped();
	ui->image4->setPixmap(QPixmap::fromImage(imageQ));
}

cv::Mat InterfacePrincipale::redimensionner(cv::Mat image){

	double largeurFinale = ui->image1->width();
	double largeurInitiale = image.cols;

	double echelle = largeurFinale/largeurInitiale;
	echelle = echelle-fmod(echelle,0.05);

	cv::resize(image, image, cv::Size(), echelle, echelle);
	return image;
}