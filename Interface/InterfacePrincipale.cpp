#include "Interface/InterfacePrincipale.h"
#include "ui_InterfacePrincipale.h"
#include "Fenetres/FenetreModifier.h"
#include "Image/GestionImage.h"
#include "Traitement/GestionTraitement.h"

#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>
#include <cmath>
#include <QResizeEvent>

#include <qdesktopservices.h>
#include <QtWidgets/qtwidgetsglobal.h>
#include <string>
#include <qmessagebox.h>
#include <iostream>

#if defined(Q_OS_WIN32) // Includes pour la compilation sous Windows
	#include <windows.h>
	#include <libloaderapi.h>

	#include <qpainter.h>
#endif // Fin des includes pour Windows


using namespace std;
using namespace cv;


InterfacePrincipale::InterfacePrincipale(Controleur *controleur, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InterfacePrincipale)
{
    ui->setupUi(this);
    this->controleur=controleur;
    
    // gestionImage = controleur->getGestionImage();
    
    // gestionTraitement = gestionTraitement;
}

InterfacePrincipale::~InterfacePrincipale()
{
	delete ui;
}


void InterfacePrincipale::importerUneImage()
{
	QString nomImage = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::currentPath(), tr("Image Files [ *.jpg , *.jpeg , *.bmp , *.png , *.gif]"));
	
	char* cheminImage = nomImage.toLocal8Bit().data();

	controleur->getGestionImage()->setImageOriginale(cv::imread(cheminImage));
	
	cv::Mat imageMat=controleur->getGestionImage()->getImageOriginale();

	majImage1(imageMat);
	majImage2(imageMat);
	majImage3(imageMat);
	majImage4(imageMat);
}


void InterfacePrincipale::resizeEvent(QResizeEvent* event)
{
	if(controleur->getGestionImage()->isImportee()){
		
		cv::Mat imageMat=controleur->getGestionImage()->getImageOriginale();

		majImage1(imageMat);
		majImage2(imageMat);
		majImage3(imageMat);
		majImage4(imageMat);
	}
}


void InterfacePrincipale::sauvegarderImageFinale()
{
	if (controleur->getGestionImage()->isImportee()) {
			//On recupere la dernière image (label4) au format Qpixmap
			const QPixmap *imageQ = ui->image4->pixmap();
			//Conversion du Qpixmap en Qimage
			QImage monImage = imageQ->toImage();
			//Choix de l'emplacement de la photo
			QString filename = QFileDialog::getSaveFileName(this, tr("Sauvegarder l'image"), QDir::currentPath());
			//Sauvegarde de l'image à l'emplacement souhaité
			monImage.save(filename);
		}
	else
		{
			//Si aucune image n'a été importé
			QMessageBox::critical(this, tr("Erreur"), tr("Importez d'abord une image"));
			importerUneImage();
		}


}

void InterfacePrincipale::afficherGuide()
{
#if defined(Q_OS_WIN32)
	char buffer[MAX_PATH];
	//récupere le nom du exe avec son chemin aboslue
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	//récupere le nom du exe avec son chemin absolue et coupe le nom de l'executable pour garder que le chemin absolue vers le fichier
	string::size_type pos = string(buffer).find_last_of("\\/");
	//Conversion d'une chaine string en qstring
	QString qpath = QString::fromStdString(string(buffer).substr(0, pos));

#elif defined(Q_OS_UNIX)
	QString qpath = QCoreApplication::applicationDirPath();
#endif

	if (!QDesktopServices::openUrl(QUrl::fromLocalFile(qpath + "/GuideHoko.pdf")))
	{
		//En cas d'erreur un fenetre d'erreur s'ouvre
		QMessageBox::critical(this, tr("Erreur"), tr("Impossible d'ouvrir le fichier..."));
	}

}

void InterfacePrincipale::afficherApropos()
{
#if defined(Q_OS_WIN32)
	char buffer[MAX_PATH];
	//récupere le nom du exe avec son chemin aboslue
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	//récupere le nom du exe avec son chemin absolue et coupe le nom de l'executable pour garder que le chemin absolue vers le fichier
	string::size_type pos = string(buffer).find_last_of("\\/");
	//Conversion d'une chaine string en qstring
	QString qpath = QString::fromStdString(string(buffer).substr(0, pos));
	
#elif defined(Q_OS_UNIX)
	QString qpath = QCoreApplication::applicationDirPath();
#endif
	if (!QDesktopServices::openUrl(QUrl::fromLocalFile(qpath + "/Apropos.pdf")))
	{
		//En cas d'erreur un fenetre d'erreur s'ouvre
		QMessageBox::critical(this, tr("Erreur"), tr("Impossible d'ouvrir le fichier..."));
	}
}

void InterfacePrincipale::on_ajouterBouton_clicked()
{
	

	
 //    if(controleur->getGestionImage()->isImportee()){
	//     FenetreModifier *fenMod = new FenetreModifier(this);
	//     fenMod->show();
	// }
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
