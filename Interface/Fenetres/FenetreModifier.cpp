#include "FenetreModifier.h"
#include "ui_FenetreModifier.h"
#include "Interface/InterfacePrincipale.h"
#include "Traitement/FlouGaussien.h"


FenetreModifier::FenetreModifier(Traitement* traitement, int largeurNoyau, int hauteurNoyau, double sigma, QWidget *parent) :
	QDialog(parent),
    ui(new Ui::FenetreModifier)
{
    ui->setupUi(this);

    this->traitement=traitement;
    ui->spinBoxLargeurNoyau->setValue(largeurNoyau);
    ui->spinBoxHauteurNoyau->setValue(hauteurNoyau);
    ui->doubleSpinBoxSigma->setValue(sigma);
}

FenetreModifier::~FenetreModifier()
{
    delete ui;
}

void FenetreModifier::on_validerBouton_clicked()
{
    traitement->validerModification();
    this->~FenetreModifier();
}

void FenetreModifier::on_annulerBouton_clicked()
{
    this->~FenetreModifier();
}

void FenetreModifier::on_spinBoxLargeurNoyau_valueChanged(int largeurNoyau)
{
    if(largeurNoyau%2!=1){//largeurNoyau doit être impaire
    	ui->spinBoxLargeurNoyau->setValue(largeurNoyau+1);
    }

    flouGaussien(ui->spinBoxLargeurNoyau->value(),
                ui->spinBoxHauteurNoyau->value(),
                ui->doubleSpinBoxSigma->value()
                );
}

void FenetreModifier::on_spinBoxHauteurNoyau_valueChanged(int hauteurNoyau)
{
    if(hauteurNoyau%2!=1)//hauteurNoyau doit être impaire
        ui->spinBoxHauteurNoyau->setValue(hauteurNoyau+1);

    flouGaussien(ui->spinBoxLargeurNoyau->value(),
                ui->spinBoxHauteurNoyau->value(),
				ui->doubleSpinBoxSigma->value()
				);
}

void FenetreModifier::on_doubleSpinBoxSigma_valueChanged(double sigma)
{
    flouGaussien(ui->spinBoxLargeurNoyau->value(),
                ui->spinBoxHauteurNoyau->value(),
                sigma);
}


void FenetreModifier::flouGaussien(int largeurNoyau, int hauteurNoyau, double sigma){
	// cv::Mat imageFloue;

 //    Traitement* unTraitement;
   
     // unTraitement = new FlouGaussien;
    // printf("traitement %d", traitement);
    reinterpret_cast<FlouGaussien*>(traitement)->appliquer(largeurNoyau, hauteurNoyau, sigma);

    // return imageFloue;
}