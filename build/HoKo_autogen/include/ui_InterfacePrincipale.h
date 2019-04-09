/********************************************************************************
** Form generated from reading UI file 'InterfacePrincipale.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACEPRINCIPALE_H
#define UI_INTERFACEPRINCIPALE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfacePrincipale
{
public:
    QAction *actionCharger_une_configuration;
    QAction *actionExporter_la_configuration;
    QAction *actionImporter_une_image;
    QAction *actionSauvegarder_l_image_finale;
    QAction *actionAide;
    QAction *actionVersion;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QLabel *image2;
    QLabel *image3;
    QLabel *image1;
    QLabel *image4;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QListWidget *listeTraitements;
    QCheckBox *actifCheckBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *hautBouton;
    QPushButton *basBouton;
    QPushButton *modifierBouton;
    QPushButton *supprimerBouton;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *choixTraitement;
    QPushButton *ajouterBouton;
    QMenuBar *menuBar;
    QMenu *menuHoKo;
    QMenu *menuCOnfiguration;
    QMenu *menuAide;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InterfacePrincipale)
    {
        if (InterfacePrincipale->objectName().isEmpty())
            InterfacePrincipale->setObjectName(QString::fromUtf8("InterfacePrincipale"));
        InterfacePrincipale->resize(965, 500);
        InterfacePrincipale->setMinimumSize(QSize(964, 500));
        QIcon icon;
        icon.addFile(QString::fromUtf8("logo/hoko-logo-500.png"), QSize(), QIcon::Normal, QIcon::Off);
        InterfacePrincipale->setWindowIcon(icon);
        InterfacePrincipale->setToolButtonStyle(Qt::ToolButtonTextOnly);
        actionCharger_une_configuration = new QAction(InterfacePrincipale);
        actionCharger_une_configuration->setObjectName(QString::fromUtf8("actionCharger_une_configuration"));
        actionExporter_la_configuration = new QAction(InterfacePrincipale);
        actionExporter_la_configuration->setObjectName(QString::fromUtf8("actionExporter_la_configuration"));
        actionImporter_une_image = new QAction(InterfacePrincipale);
        actionImporter_une_image->setObjectName(QString::fromUtf8("actionImporter_une_image"));
        actionSauvegarder_l_image_finale = new QAction(InterfacePrincipale);
        actionSauvegarder_l_image_finale->setObjectName(QString::fromUtf8("actionSauvegarder_l_image_finale"));
        actionAide = new QAction(InterfacePrincipale);
        actionAide->setObjectName(QString::fromUtf8("actionAide"));
        actionVersion = new QAction(InterfacePrincipale);
        actionVersion->setObjectName(QString::fromUtf8("actionVersion"));
        centralWidget = new QWidget(InterfacePrincipale);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        image2 = new QLabel(centralWidget);
        image2->setObjectName(QString::fromUtf8("image2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(image2->sizePolicy().hasHeightForWidth());
        image2->setSizePolicy(sizePolicy);
        image2->setFrameShape(QFrame::StyledPanel);

        gridLayout_2->addWidget(image2, 0, 1, 1, 1);

        image3 = new QLabel(centralWidget);
        image3->setObjectName(QString::fromUtf8("image3"));
        sizePolicy.setHeightForWidth(image3->sizePolicy().hasHeightForWidth());
        image3->setSizePolicy(sizePolicy);
        image3->setFrameShape(QFrame::StyledPanel);
        image3->setFrameShadow(QFrame::Plain);

        gridLayout_2->addWidget(image3, 1, 0, 1, 1);

        image1 = new QLabel(centralWidget);
        image1->setObjectName(QString::fromUtf8("image1"));
        sizePolicy.setHeightForWidth(image1->sizePolicy().hasHeightForWidth());
        image1->setSizePolicy(sizePolicy);
        image1->setAutoFillBackground(false);
        image1->setFrameShape(QFrame::StyledPanel);
        image1->setFrameShadow(QFrame::Plain);

        gridLayout_2->addWidget(image1, 0, 0, 1, 1);

        image4 = new QLabel(centralWidget);
        image4->setObjectName(QString::fromUtf8("image4"));
        sizePolicy.setHeightForWidth(image4->sizePolicy().hasHeightForWidth());
        image4->setSizePolicy(sizePolicy);
        image4->setFrameShape(QFrame::StyledPanel);

        gridLayout_2->addWidget(image4, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listeTraitements = new QListWidget(centralWidget);
        listeTraitements->setObjectName(QString::fromUtf8("listeTraitements"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listeTraitements->sizePolicy().hasHeightForWidth());
        listeTraitements->setSizePolicy(sizePolicy1);
        listeTraitements->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(listeTraitements);

        actifCheckBox = new QCheckBox(centralWidget);
        actifCheckBox->setObjectName(QString::fromUtf8("actifCheckBox"));
        actifCheckBox->setEnabled(false);
        actifCheckBox->setChecked(true);

        verticalLayout->addWidget(actifCheckBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        hautBouton = new QPushButton(centralWidget);
        hautBouton->setObjectName(QString::fromUtf8("hautBouton"));
        hautBouton->setEnabled(false);

        horizontalLayout_2->addWidget(hautBouton);

        basBouton = new QPushButton(centralWidget);
        basBouton->setObjectName(QString::fromUtf8("basBouton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(basBouton->sizePolicy().hasHeightForWidth());
        basBouton->setSizePolicy(sizePolicy2);
        basBouton->setEnabled(false);

        horizontalLayout_2->addWidget(basBouton);

        modifierBouton = new QPushButton(centralWidget);
        modifierBouton->setObjectName(QString::fromUtf8("modifierBouton"));
        modifierBouton->setEnabled(false);

        horizontalLayout_2->addWidget(modifierBouton);

        supprimerBouton = new QPushButton(centralWidget);
        supprimerBouton->setObjectName(QString::fromUtf8("supprimerBouton"));
        supprimerBouton->setEnabled(false);

        horizontalLayout_2->addWidget(supprimerBouton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        choixTraitement = new QComboBox(centralWidget);
        choixTraitement->addItem(QString());
        choixTraitement->addItem(QString());
        choixTraitement->addItem(QString());
        choixTraitement->addItem(QString());
        choixTraitement->addItem(QString());
        choixTraitement->setObjectName(QString::fromUtf8("choixTraitement"));

        horizontalLayout_3->addWidget(choixTraitement);

        ajouterBouton = new QPushButton(centralWidget);
        ajouterBouton->setObjectName(QString::fromUtf8("ajouterBouton"));
        ajouterBouton->setEnabled(false);

        horizontalLayout_3->addWidget(ajouterBouton);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        InterfacePrincipale->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(InterfacePrincipale);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 20));
        menuHoKo = new QMenu(menuBar);
        menuHoKo->setObjectName(QString::fromUtf8("menuHoKo"));
        menuCOnfiguration = new QMenu(menuBar);
        menuCOnfiguration->setObjectName(QString::fromUtf8("menuCOnfiguration"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        InterfacePrincipale->setMenuBar(menuBar);
        statusBar = new QStatusBar(InterfacePrincipale);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        InterfacePrincipale->setStatusBar(statusBar);

        menuBar->addAction(menuHoKo->menuAction());
        menuBar->addAction(menuCOnfiguration->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuHoKo->addAction(actionImporter_une_image);
        menuHoKo->addAction(actionSauvegarder_l_image_finale);
        menuCOnfiguration->addAction(actionCharger_une_configuration);
        menuCOnfiguration->addAction(actionExporter_la_configuration);
        menuAide->addAction(actionAide);
        menuAide->addAction(actionVersion);

        retranslateUi(InterfacePrincipale);
        QObject::connect(actionImporter_une_image, SIGNAL(triggered()), InterfacePrincipale, SLOT(importerUneImage()));
        QObject::connect(actionSauvegarder_l_image_finale, SIGNAL(triggered()), InterfacePrincipale, SLOT(sauvegarderImageFinale()));
        QObject::connect(actionExporter_la_configuration, SIGNAL(triggered()), InterfacePrincipale, SLOT(exporterConfiguration()));
        QObject::connect(actionCharger_une_configuration, SIGNAL(triggered()), InterfacePrincipale, SLOT(chargerConfiguration()));
        QObject::connect(actionAide, SIGNAL(triggered()), InterfacePrincipale, SLOT(afficherGuide()));
        QObject::connect(actionVersion, SIGNAL(triggered()), InterfacePrincipale, SLOT(afficherApropos()));

        QMetaObject::connectSlotsByName(InterfacePrincipale);
    } // setupUi

    void retranslateUi(QMainWindow *InterfacePrincipale)
    {
        InterfacePrincipale->setWindowTitle(QApplication::translate("InterfacePrincipale", "HoKo", nullptr));
        actionCharger_une_configuration->setText(QApplication::translate("InterfacePrincipale", "Charger une configuration", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCharger_une_configuration->setShortcut(QApplication::translate("InterfacePrincipale", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionExporter_la_configuration->setText(QApplication::translate("InterfacePrincipale", "Exporter la configuration", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExporter_la_configuration->setShortcut(QApplication::translate("InterfacePrincipale", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionImporter_une_image->setText(QApplication::translate("InterfacePrincipale", "Importer une image", nullptr));
#ifndef QT_NO_SHORTCUT
        actionImporter_une_image->setShortcut(QApplication::translate("InterfacePrincipale", "Ctrl+I", nullptr));
#endif // QT_NO_SHORTCUT
        actionSauvegarder_l_image_finale->setText(QApplication::translate("InterfacePrincipale", "Sauvegarder l'image finale", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSauvegarder_l_image_finale->setShortcut(QApplication::translate("InterfacePrincipale", "Ctrl+Alt+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionAide->setText(QApplication::translate("InterfacePrincipale", "Guide d'utilisation", nullptr));
#ifndef QT_NO_SHORTCUT
        actionAide->setShortcut(QApplication::translate("InterfacePrincipale", "Ctrl+G", nullptr));
#endif // QT_NO_SHORTCUT
        actionVersion->setText(QApplication::translate("InterfacePrincipale", "\303\200 propos de HoKo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionVersion->setShortcut(QApplication::translate("InterfacePrincipale", "Ctrl+H", nullptr));
#endif // QT_NO_SHORTCUT
        image2->setText(QString());
        image3->setText(QString());
        image1->setText(QString());
        image4->setText(QString());
        actifCheckBox->setText(QApplication::translate("InterfacePrincipale", "Actif", nullptr));
#ifndef QT_NO_SHORTCUT
        actifCheckBox->setShortcut(QApplication::translate("InterfacePrincipale", "Shift+A", nullptr));
#endif // QT_NO_SHORTCUT
        hautBouton->setText(QApplication::translate("InterfacePrincipale", "\311\205", nullptr));
#ifndef QT_NO_SHORTCUT
        hautBouton->setShortcut(QApplication::translate("InterfacePrincipale", "Ctrl+Up", nullptr));
#endif // QT_NO_SHORTCUT
        basBouton->setText(QApplication::translate("InterfacePrincipale", "V", nullptr));
#ifndef QT_NO_SHORTCUT
        basBouton->setShortcut(QApplication::translate("InterfacePrincipale", "Ctrl+Down", nullptr));
#endif // QT_NO_SHORTCUT
        modifierBouton->setText(QApplication::translate("InterfacePrincipale", "Modifier", nullptr));
#ifndef QT_NO_SHORTCUT
        modifierBouton->setShortcut(QApplication::translate("InterfacePrincipale", "M", nullptr));
#endif // QT_NO_SHORTCUT
        supprimerBouton->setText(QApplication::translate("InterfacePrincipale", "Supprimer", nullptr));
#ifndef QT_NO_SHORTCUT
        supprimerBouton->setShortcut(QApplication::translate("InterfacePrincipale", "Del", nullptr));
#endif // QT_NO_SHORTCUT
        choixTraitement->setItemText(0, QApplication::translate("InterfacePrincipale", "Flou Gaussien", nullptr));
        choixTraitement->setItemText(1, QApplication::translate("InterfacePrincipale", "Masque CAM3", nullptr));
        choixTraitement->setItemText(2, QApplication::translate("InterfacePrincipale", "Segmentation TSV", nullptr));
        choixTraitement->setItemText(3, QApplication::translate("InterfacePrincipale", "Filtre de Canny", nullptr));
        choixTraitement->setItemText(4, QApplication::translate("InterfacePrincipale", "D\303\251tection de contours", nullptr));

        ajouterBouton->setText(QApplication::translate("InterfacePrincipale", "Ajouter", nullptr));
#ifndef QT_NO_SHORTCUT
        ajouterBouton->setShortcut(QApplication::translate("InterfacePrincipale", "A", nullptr));
#endif // QT_NO_SHORTCUT
        menuHoKo->setTitle(QApplication::translate("InterfacePrincipale", "Image", nullptr));
        menuCOnfiguration->setTitle(QApplication::translate("InterfacePrincipale", "Configuration", nullptr));
        menuAide->setTitle(QApplication::translate("InterfacePrincipale", "Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InterfacePrincipale: public Ui_InterfacePrincipale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACEPRINCIPALE_H
