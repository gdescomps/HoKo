#include "Interface/InterfacePrincipale.h"
#include "ui_InterfacePrincipale.h"
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


InterfacePrincipale::InterfacePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InterfacePrincipale)
{
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

	cv::Mat imageMat = cv::imread(cheminImage);

	//hauteurFinale = hauteurInitiale * largeurFinale / largeurInitiale
	int hauteurFinale = imageMat.rows * ui->label->width() / imageMat.cols;
	
	cv::resize(imageMat, imageMat, cv::Size(ui->label->width(),hauteurFinale));

	QImage imageQ = QImage((const unsigned char*)imageMat.data,imageMat.cols,imageMat.rows,QImage::Format_RGB888).rgbSwapped();
	ui->label->setPixmap(QPixmap::fromImage(imageQ));
	ui->label_2->setPixmap(QPixmap::fromImage(imageQ));
	ui->label_3->setPixmap(QPixmap::fromImage(imageQ));
	ui->label_4->setPixmap(QPixmap::fromImage(imageQ));
}