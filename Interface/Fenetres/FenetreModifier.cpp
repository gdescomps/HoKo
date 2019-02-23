#include "FenetreModifier.h"
#include "ui_FenetreModifier.h"

FenetreModifier::FenetreModifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreModifier)
{
    ui->setupUi(this);
}

FenetreModifier::~FenetreModifier()
{
    delete ui;
}
void FenetreModifier::on_validerBouton_clicked()
{
    this->~FenetreModifier();
}

void FenetreModifier::on_pushButton_clicked()
{
    this->~FenetreModifier();
}

void FenetreModifier::on_spinBoxLargeurNoyau_valueChanged(int largeurNoyau)
{
    
}

void FenetreModifier::on_spinBoxHauteurNoyau_valueChanged(int hauteurNoyau)
{
    
}

void FenetreModifier::on_doubleSpinBoxSigma_valueChanged(double sigma)
{
    
}