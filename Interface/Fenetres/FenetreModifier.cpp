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
        traitement->appliquer(sauvegardeValeurs);
    }
    this->~FenetreModifier();
}

void FenetreModifier::on_appliquerBouton_clicked()
{
    envoyerValeurs();
}

void FenetreModifier::envoyerValeurs(){
    list<Valeur> valeurs;
    list<QDoubleSpinBox*>::iterator itChamp=ui->champs.begin();

    for (list<Parametre>::iterator it=this->parametres.begin(); it != this->parametres.end(); ++it){
        Valeur v;
        switch((*it).type){
            case _INT :
                v._int = (*itChamp)->value();
                printf("int %i ",v._int);
                break;
            
            case _DOUBLE :
                v._double = (*itChamp)->value();
                printf("double %d ",v._double);
                break;

            default :
                printf("ERREUR : Type de variable (%i) de paramètre non trouvé \n", (*it).type);
                break;
        }
        valeurs.push_back(v);
        ++itChamp;
    }

    traitement->appliquer(valeurs);
}
