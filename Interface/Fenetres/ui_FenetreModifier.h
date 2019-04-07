/********************************************************************************
** Form generated from reading UI file 'FenetreModifier.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETREMODIFIER_H
#define UI_FENETREMODIFIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <list>
using namespace std;

QT_BEGIN_NAMESPACE

class Ui_FenetreModifier
{
public:
    QVBoxLayout *verticalLayout;

    list<QDoubleSpinBox*> champs;
    list<Parametre> parametres;
    
    QLabel *infoLabel;

    QHBoxLayout *horizontalLayout;
    
    QPushButton *validerBouton;
    QPushButton *appliquerBouton;
    QPushButton *annulerBouton;

    void setupUi(QDialog *FenetreModifier, list<Parametre> parametres)
    {
        this->parametres=parametres;

        if (FenetreModifier->objectName().isEmpty())
            FenetreModifier->setObjectName(QString::fromUtf8("FenetreModifier"));
        //FenetreModifier->resize(314, 218);
        verticalLayout = new QVBoxLayout(FenetreModifier);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        for(list<Parametre>::iterator it=this->parametres.begin(); it != this->parametres.end(); ++it){
            QLabel *label = new QLabel(FenetreModifier);
            label->setText(QString::fromStdString((*it).nom));
            verticalLayout->addWidget(label);

            QDoubleSpinBox *champ = new QDoubleSpinBox(FenetreModifier);
            champ->setMaximum(10000);
            switch((*it).type){
                case _INT :
                    champ->setDecimals(0);
                    champ->setValue((*it).valeur._int);
                    break;
                
                case _DOUBLE :
                    champ->setDecimals(2);
                    champ->setValue((*it).valeur._double);
                    break;

                default :
                    printf("ERREUR : Type de variable (%i) de paramètre non trouvé \n", (*it).type);
                    break;
            }
            
            verticalLayout->addWidget(champ);
            champs.push_back(champ);
        }
        
        infoLabel = new QLabel(FenetreModifier);
        infoLabel->setText("");
        verticalLayout->addWidget(infoLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        validerBouton = new QPushButton(FenetreModifier);
        validerBouton->setObjectName(QString::fromUtf8("validerBouton"));

        horizontalLayout->addWidget(validerBouton);

        appliquerBouton = new QPushButton(FenetreModifier);
        appliquerBouton->setObjectName(QString::fromUtf8("appliquerBouton"));

        horizontalLayout->addWidget(appliquerBouton);

        annulerBouton = new QPushButton(FenetreModifier);
        annulerBouton->setObjectName(QString::fromUtf8("annulerBouton"));

        horizontalLayout->addWidget(annulerBouton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FenetreModifier);

        QMetaObject::connectSlotsByName(FenetreModifier);
    } // setupUi

    void retranslateUi(QDialog *FenetreModifier)
    {
        FenetreModifier->setWindowTitle(QApplication::translate("FenetreModifier", "Param\303\250tres", nullptr));
        /*labelNoyauLargeur->setText(QApplication::translate("FenetreModifier", "Largeur du noyau", nullptr));
        labelNoyauHauteur->setText(QApplication::translate("FenetreModifier", "Hauteur du noyau", nullptr));
        labelSigma->setText(QApplication::translate("FenetreModifier", "Sigma", nullptr));*/
        validerBouton->setText(QApplication::translate("FenetreModifier", "Valider", nullptr));
        appliquerBouton->setText(QApplication::translate("FenetreModifier", "Appliquer", nullptr));
        annulerBouton->setText(QApplication::translate("FenetreModifier", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenetreModifier: public Ui_FenetreModifier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETREMODIFIER_H
