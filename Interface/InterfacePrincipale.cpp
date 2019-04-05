#include "Interface/InterfacePrincipale.h"
#include "ui_InterfacePrincipale.h"
// #include "Fenetres/FenetreModifier.h"
// #include "Image/GestionImage.h"
// #include "Traitement/GestionTraitement.h"

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
	QString nomImage = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::currentPath(),tr("Images (*.png *.jpg *.jpeg)"));
	
	if(nomImage!=""){
		ui->ajouterBouton->setEnabled(true);

		char* cheminImage = nomImage.toLocal8Bit().data();

		controleur->getGestionImage()->setImageOriginale(cv::imread(cheminImage));
		
		cv::Mat imageMat=controleur->getGestionImage()->getImageOriginale();

		majImage1(imageMat);
		majImage2(imageMat);
		majImage3(imageMat);
		majImage4(imageMat);
	}
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

			if(filename!=""){
				//Sauvegarde de l'image à l'emplacement souhaité
				monImage.save(filename);
			}
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
	if(controleur->getGestionImage()->isImportee()){
		controleur->getGestionTraitement()->ajouterTraitement(0);
	}
}


void InterfacePrincipale::majImage1(cv::Mat image){
	// image = redimensionner(image);
	QImage imageQ = QImage((const unsigned char*)image.data,image.cols,image.rows,QImage::Format_RGB888).rgbSwapped();
	ui->image1->setPixmap(QPixmap::fromImage(imageQ.scaled(ui->image2->size(), Qt::KeepAspectRatio)));
}

void InterfacePrincipale::majImage2(cv::Mat image){
	//image = redimensionner(image);
	QImage imageQ = QImage((const unsigned char*)image.data,image.cols,image.rows,QImage::Format_RGB888).rgbSwapped();
	ui->image2->setPixmap(QPixmap::fromImage(imageQ.scaled(ui->image2->size(), Qt::KeepAspectRatio)));
}

void InterfacePrincipale::majImage3(cv::Mat image){
	// image = redimensionner(image);
	QImage imageQ = QImage((const unsigned char*)image.data,image.cols,image.rows,QImage::Format_RGB888).rgbSwapped();
	ui->image3->setPixmap(QPixmap::fromImage(imageQ.scaled(ui->image2->size(), Qt::KeepAspectRatio)));
}

void InterfacePrincipale::majImage4(cv::Mat image){
	// image = redimensionner(image);
	QImage imageQ = QImage((const unsigned char*)image.data,image.cols,image.rows,QImage::Format_RGB888).rgbSwapped();
	ui->image4->setPixmap(QPixmap::fromImage(imageQ.scaled(ui->image2->size(), Qt::KeepAspectRatio)));
}


void InterfacePrincipale::ajouterTraitementListe(std::string nom){
	ui->listeTraitements->addItem(QString::fromStdString(nom));
	ui->listeTraitements->setCurrentRow(ui->listeTraitements->count()-1);
}

void InterfacePrincipale::annulerAjoutTraitementListe(){
	ui->listeTraitements->takeItem(ui->listeTraitements->count()-1);
}

cv::Mat InterfacePrincipale::redimensionner(cv::Mat image){

	double largeurFinale = ui->image1->width();
	double largeurInitiale = image.cols;

	double echelle = largeurFinale/largeurInitiale;
	echelle = echelle-fmod(echelle,0.05);

	cv::resize(image, image, cv::Size(), echelle, echelle);
	return image;
}

void InterfacePrincipale::afficherTraitement(int position){
	if(position>=0){
		majImage2(controleur->getGestionTraitement()->getTraitement(position)->getImageEntree());
		majImage3(controleur->getGestionTraitement()->getTraitement(position)->getImageTraitee());
	}
}

void InterfacePrincipale::majActivationControles(){
	int position = ui->listeTraitements->currentRow();
	int nombre = ui->listeTraitements->count();

	if(position!=-1){ // Un traitement est sélectionné
		ui->modifierBouton->setEnabled(true);
		// ui->actifCheckBox->setEnabled(true);
		ui->supprimerBouton->setEnabled(true);

		if(position==0){ // Premier traitement
			ui->hautBouton->setEnabled(false);
		}
		else{
			ui->hautBouton->setEnabled(true);
		}

		if(position==nombre-1){ // Dernier traitement
			ui->basBouton->setEnabled(false);
		}
		else{
			ui->basBouton->setEnabled(true);
		}
	}
	else{ // Sinon tout désactiver
		ui->modifierBouton->setEnabled(false);
		// ui->actifCheckBox->setEnabled(false);
		ui->supprimerBouton->setEnabled(false);
	}
}

void InterfacePrincipale::on_listeTraitements_currentRowChanged(int currentRow){
	afficherTraitement(currentRow);
	majActivationControles();
}

void InterfacePrincipale::on_supprimerBouton_clicked(){
	int position = ui->listeTraitements->currentRow();
	ui->listeTraitements->takeItem(position);
	controleur->getGestionTraitement()->supprimerTraitement(position);
	
	if(ui->listeTraitements->count()>0)
		afficherTraitement(ui->listeTraitements->currentRow());

	majActivationControles();
}

void InterfacePrincipale::on_modifierBouton_clicked(){
	int position = ui->listeTraitements->currentRow();
	controleur->getGestionTraitement()->modifierTraitement(position);
}

void InterfacePrincipale::on_hautBouton_clicked(){
	int position = ui->listeTraitements->currentRow();
	controleur->getGestionTraitement()->intervertirTraitements(position, position-1);

	QString tmp = ui->listeTraitements->currentItem()->text();
	ui->listeTraitements->currentItem()->setText(ui->listeTraitements->item(position-1)->text());
	ui->listeTraitements->item(position-1)->setText(tmp);

	ui->listeTraitements->setCurrentRow(position-1);
}

void InterfacePrincipale::on_basBouton_clicked(){
	int position = ui->listeTraitements->currentRow();
	controleur->getGestionTraitement()->intervertirTraitements(position, position+1);

	QString tmp = ui->listeTraitements->currentItem()->text();
	ui->listeTraitements->currentItem()->setText(ui->listeTraitements->item(position+1)->text());
	ui->listeTraitements->item(position+1)->setText(tmp);

	ui->listeTraitements->setCurrentRow(position+1);
}