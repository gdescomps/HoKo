#include "FenetreModifier.h"
#include "ui_FenetreModifier.h"
#include "Interface/InterfacePrincipale.h"
#include "Traitement/FlouGaussien.h"


FenetreModifier::FenetreModifier(Traitement* traitement, bool modification, QWidget *parent) :
	QDialog(parent),
    ui(new Ui::FenetreModifier)
{
    ui->setupUi(this);

    this->traitement=traitement;

    this->parametres=traitement->getParametres();

    list<Parametre>::iterator it=this->parametres.begin();
    ui->spinBoxLargeurNoyau->setValue((*it).valeur._int);

    ++it;
    ui->spinBoxHauteurNoyau->setValue((*it).valeur._int);

    ++it;
    ui->doubleSpinBoxSigma->setValue((*it).valeur._double);

    this->modification=modification;

    if(modification){
        this->sauvegardeValeurs=traitement->toValeurList(traitement->getParametres());
    }
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
    if(!modification){
        traitement->annulerAjout();
    }
    else{
        //flouGaussien(sauvLargeurNoyau,sauvHauteurNoyau,sauvSigma);
        majValeursChamps(sauvegardeValeurs);
        envoyerValeurs();
    }
    this->~FenetreModifier();
}

void FenetreModifier::on_spinBoxLargeurNoyau_valueChanged(int largeurNoyau)
{
    if(largeurNoyau%2!=1){//largeurNoyau doit être impaire
    	ui->spinBoxLargeurNoyau->setValue(largeurNoyau+1);
    }

    envoyerValeurs();
}

void FenetreModifier::on_spinBoxHauteurNoyau_valueChanged(int hauteurNoyau)
{
    if(hauteurNoyau%2!=1)//hauteurNoyau doit être impaire
        ui->spinBoxHauteurNoyau->setValue(hauteurNoyau+1);

    envoyerValeurs();
}

void FenetreModifier::on_doubleSpinBoxSigma_valueChanged(double sigma)
{
    envoyerValeurs();
}

void FenetreModifier::envoyerValeurs(){
    list<Valeur> valeurs;
    Valeur a ;
    a._int = ui->spinBoxLargeurNoyau->value();
    valeurs.push_back(a);
    a._int = ui->spinBoxHauteurNoyau->value();
    valeurs.push_back(a);
    a._double = ui->doubleSpinBoxSigma->value();
    valeurs.push_back(a);

    traitement->appliquer(valeurs);
}

void FenetreModifier::majValeursChamps(list<Valeur> valeurs){
    list<Valeur>::iterator it=valeurs.begin();
    ui->spinBoxLargeurNoyau->setValue((*it)._int);

    ++it;
    ui->spinBoxHauteurNoyau->setValue((*it)._int);

    ++it;
    ui->doubleSpinBoxSigma->setValue((*it)._double);
}