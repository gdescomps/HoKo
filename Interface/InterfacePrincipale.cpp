#include "Interface/InterfacePrincipale.h"
#include "ui_InterfacePrincipale.h"
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>
#include <cmath>
#include <QResizeEvent>

using namespace cv;

InterfacePrincipale::InterfacePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InterfacePrincipale)
{
	imageImportee=false;
    ui->setupUi(this);
}

InterfacePrincipale::~InterfacePrincipale()
{
    delete ui;
}

void InterfacePrincipale::importerUneImage()
{
	QString nomImage = QFileDialog::getOpenFileName(this,tr("Open Image"),QDir::currentPath(),tr("Image Files [ *.jpg , *.jpeg , *.bmp , *.png , *.gif]"));
	char* cheminImage = nomImage.toLocal8Bit().data();

	imageOriginale = cv::imread(cheminImage);
	cv::Mat imageMat=imageOriginale;

	double largeurFinale = ui->label->width();
	double largeurInitiale = imageMat.cols;

	double echelle = largeurFinale/largeurInitiale;
	
	echelle = echelle-fmod(echelle,0.05);

	/*printf("largeurFinale : %f \n", largeurFinale);
	printf("largeurInitiale : %f \n", largeurInitiale);

	printf("echelle : %f \n", echelle);*/
	
	/*printf("Largeur 1 : %d \n", imageMat.cols);
	printf("Hauteur 1 : %d \n", imageMat.rows);*/

	cv::resize(imageMat, imageMat, cv::Size(), echelle, echelle);
	
	/*printf("Largeur 2 : %d \n", imageMat.cols);
	printf("Hauteur 2 : %d \n", imageMat.rows);*/

	QImage imageQ = QImage((const unsigned char*)imageMat.data,imageMat.cols,imageMat.rows,QImage::Format_RGB888).rgbSwapped();
	ui->label->setPixmap(QPixmap::fromImage(imageQ));
	ui->label_2->setPixmap(QPixmap::fromImage(imageQ));
	ui->label_3->setPixmap(QPixmap::fromImage(imageQ));
	ui->label_4->setPixmap(QPixmap::fromImage(imageQ));
	imageImportee=true;
}