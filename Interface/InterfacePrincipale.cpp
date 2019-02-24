#include "Interface/InterfacePrincipale.h"
#include "ui_InterfacePrincipale.h"
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>
#include <cmath>
#include <QResizeEvent>
#include "InterfacePrincipale.h"
#include "ui_InterfacePrincipale.h"


#include <qdesktopservices.h>
#include <QtWidgets/qtwidgetsglobal.h>
#include <string>
#include <qmessagebox.h>
#include <iostream>
#include <windows.h>
#include <libloaderapi.h>
#include <qpainter.h>
using namespace std;
using namespace cv;



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
	QString nomImage = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::currentPath(), tr("Image Files [ *.jpg , *.jpeg , *.bmp , *.png , *.gif]"));
	
	char* cheminImage = nomImage.toLocal8Bit().data();

	 imageOriginale = cv::imread(cheminImage);
	cv::Mat imageMat = imageOriginale;

	double largeurFinale = ui->label->width();
	double largeurInitiale = imageMat.cols;

	double echelle = largeurFinale / largeurInitiale;
	


	echelle = echelle - fmod(echelle, 0.05);
	

	/*printf("largeurFinale : %f \n", largeurFinale);
	printf("largeurInitiale : %f \n", largeurInitiale);
	printf("echelle : %f \n", echelle);*/

	/*printf("Largeur 1 : %d \n", imageMat.cols);
	printf("Hauteur 1 : %d \n", imageMat.rows);*/

	cv::resize(imageMat, imageMat, cv::Size(), echelle, echelle);

	/*printf("Largeur 2 : %d \n", imageMat.cols);
	printf("Hauteur 2 : %d \n", imageMat.rows);*/

	QImage imageQ = QImage((const unsigned char*)imageMat.data, imageMat.cols, imageMat.rows, QImage::Format_RGB888).rgbSwapped();
	ui->label->setPixmap(QPixmap::fromImage(imageQ));
	ui->label_2->setPixmap(QPixmap::fromImage(imageQ));
	ui->label_3->setPixmap(QPixmap::fromImage(imageQ));
	ui->label_4->setPixmap(QPixmap::fromImage(imageQ));
	 imageImportee = true;
}
void InterfacePrincipale::sauvegarderImageFinale()
{
	if (ui->label_4->pixmap()) {
			//On recupere la dernière image (label4) au format Qpixmap
			const QPixmap *imageQ = ui->label_4->pixmap();
			//Conversion du Qpixmap en Qimage
			QImage monImage = imageQ->toImage();
			//Choix de l'emplacement de la photo
			QString filename = QFileDialog::getSaveFileName(this, tr("Sauvegarder l'inmage"), QDir::currentPath());
			//Sauvegarde de l'image à l'emplacement souhaité
			monImage.save(filename);
		}
	else
		{
			//Si aucune image n'a été importé
			QMessageBox::critical(this, tr("Erreur"), tr("Importez d'abord une Image"));
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

	if (!QDesktopServices::openUrl(QUrl::fromLocalFile(qpath + "/GuideHoko.pdf")))
	{
		//En cas d'erreur un fenetre d'erreur s'ouvre
		QMessageBox::critical(this, tr("Erreur"), tr("Impossible d'ouvrir le fichier...."));
	}
	//Sous windows la commande por ouvrir une cmd et ouvrir le pdf
	//system("start C:\CheminAbsolue\GuideHoko.pdf");
#elif defined(Q_OS_UNIX)
#endif

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
	if (!QDesktopServices::openUrl(QUrl::fromLocalFile(qpath + "/Apropos.pdf")))
		{
			//En cas d'erreur un fenetre d'erreur s'ouvre
			QMessageBox::critical(this, tr("Erreur"), tr("Impossible d'ouvrir le fichier...."));
		}
	//Sous windows la commande por ouvrir une cmd et ouvrir le pdf
	//system("start C:\CheminAbsolue\GuideHoko.pdf");
#elif defined(Q_OS_UNIX)
#endif

}


/*void InterfacePrincipale::resizeEvent(QResizeEvent* event)
{
	//printf("Resize \n");
	if (imageImportee) {
		cv::Mat imageMat = imageOriginale;
		double largeurFinale = ui->label->width();
		double largeurInitiale = imageMat.cols;

		double echelle = largeurFinale / largeurInitiale;
		echelle = echelle - fmod(echelle, 0.05);

		cv::resize(imageMat, imageMat, cv::Size(), echelle, echelle);

		QImage imageQ = QImage((const unsigned char*)imageMat.data, imageMat.cols, imageMat.rows, QImage::Format_RGB888).rgbSwapped();
		ui->label->setPixmap(QPixmap::fromImage(imageQ));
		ui->label_2->setPixmap(QPixmap::fromImage(imageQ));
		ui->label_3->setPixmap(QPixmap::fromImage(imageQ));
		ui->label_4->setPixmap(QPixmap::fromImage(imageQ));
	}
}*/


