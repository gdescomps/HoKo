#include "FenetreModifier.h"
#include "ui_FenetreModifier.h"
#include "Interface/InterfacePrincipale.h"
#include "Traitement/FlouGaussien.h"

FenetreModifier::FenetreModifier(Traitement* traitement, bool modification, QWidget *parent) :
	QDialog(parent),
    ui(new Ui::FenetreModifier)
{
    this->traitement=traitement;

    this->parametres=traitement->getParametres();

    ui->setupUi(this, parametres);

    /*list<Parametre>::iterator it=this->parametres.begin();
    ui->spinBoxLargeurNoyau->setValue((*it).valeur._int);

    ++it;
    ui->spinBoxHauteurNoyau->setValue((*it).valeur._int);

    ++it;
    ui->doubleSpinBoxSigma->setValue((*it).valeur._double);*/

    this->modification=modification;

    if(modification){
        this->sauvegardeValeurs=traitement->toValeurList(traitement->getParametres());
    }
}

FenetreModifier::~FenetreModifier()
{
    delete ui;
}


list<Parametre> FenetreModifier::getParametres(){
    return this->parametres;
}

void FenetreModifier::on_validerBouton_clicked()
{
    envoyerValeurs();
    traitement->validerModification();
    this->~FenetreModifier();
}

void FenetreModifier::on_annulerBouton_clicked()
{
    if(!modification){
        traitement->annulerAjout();
    }
    else{
        majValeursChamps(sauvegardeValeurs);
        envoyerValeurs();
    }
    this->~FenetreModifier();
}

void FenetreModifier::on_appliquerBouton_clicked()
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