#include "FenetreModifier.h"
#include "ui_FenetreModifier.h"
#include "Interface/InterfacePrincipale.h"
// #include "Traitement/FlouGaussien.cpp"

FenetreModifier::FenetreModifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreModifier)
{
    ui->setupUi(this);
}

FenetreModifier::FenetreModifier(Traitement* traitement, QWidget *parent) :
	QDialog(parent),
    ui(new Ui::FenetreModifier)
{
    ui->setupUi(this);

    traitement=traitement;

    // this->interface=interface;
    // interface->majImage3(flouGaussien(ui->spinBoxLargeurNoyau->value(),ui->spinBoxHauteurNoyau->value(),ui->doubleSpinBoxSigma->value()));

}
FenetreModifier::~FenetreModifier()
{
    delete ui;
}

void FenetreModifier::on_validerBouton_clicked()
{
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
    // interface->majImage3(flouGaussien(
    // 								ui->spinBoxLargeurNoyau->value(),
    // 								ui->spinBoxHauteurNoyau->value(),
    // 								ui->doubleSpinBoxSigma->value()
    								// ));
}

void FenetreModifier::on_spinBoxHauteurNoyau_valueChanged(int hauteurNoyau)
{
    if(hauteurNoyau%2!=1)//hauteurNoyau doit être impaire
    	ui->spinBoxHauteurNoyau->setValue(hauteurNoyau+1);
    // interface->majImage3(flouGaussien(
    //                                 ui->spinBoxLargeurNoyau->value(),
    //                                 ui->spinBoxHauteurNoyau->value(),
    // 								ui->doubleSpinBoxSigma->value()
    // 								));
}

void FenetreModifier::on_doubleSpinBoxSigma_valueChanged(double sigma)
{
    // interface->majImage3(flouGaussien(ui->spinBoxLargeurNoyau->value(),
    //                                 ui->spinBoxHauteurNoyau->value(),
    //                                 sigma));
}


cv::Mat FenetreModifier::flouGaussien(int largeurNoyau, int hauteurNoyau, double sigma){
	cv::Mat imageFloue;

    // Traitement* unTraitement;
   
    // unTraitement = new FlouGaussien;

    // imageFloue=static_cast<FlouGaussien*>(unTraitement)->appliquer(interface->controleur->getGestionImage()->getImageOriginale(), largeurNoyau, hauteurNoyau, sigma);

    return imageFloue;
}