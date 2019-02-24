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
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox;
    QPushButton *pushButton_5;
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
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFrameShape(QFrame::StyledPanel);

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFrameShape(QFrame::StyledPanel);
        label_4->setFrameShadow(QFrame::Plain);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAutoFillBackground(false);
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Plain);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFrameShape(QFrame::StyledPanel);

        gridLayout_2->addWidget(label_3, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(centralWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(listWidget);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_3->addWidget(comboBox);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_3->addWidget(pushButton_5);


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
		QObject::connect(actionAide , SIGNAL(triggered()), InterfacePrincipale, SLOT(afficherGuide()));
		QObject::connect(actionVersion, SIGNAL(triggered()), InterfacePrincipale, SLOT(afficherApropos()));

        QMetaObject::connectSlotsByName(InterfacePrincipale);
    } // setupUi

    void retranslateUi(QMainWindow *InterfacePrincipale)







    {
        InterfacePrincipale->setWindowTitle(QApplication::translate("InterfacePrincipale", "HoKo", nullptr));
        actionCharger_une_configuration->setText(QApplication::translate("InterfacePrincipale", "Charger une configuration", nullptr));
        actionExporter_la_configuration->setText(QApplication::translate("InterfacePrincipale", "Exporter la configuration", nullptr));
        actionImporter_une_image->setText(QApplication::translate("InterfacePrincipale", "Importer une image", nullptr));
        actionSauvegarder_l_image_finale->setText(QApplication::translate("InterfacePrincipale", "Sauvegarder l'image finale", nullptr));
        actionAide->setText(QApplication::translate("InterfacePrincipale", "Guide d'utilisation", nullptr));
        actionVersion->setText(QApplication::translate("InterfacePrincipale", "\303\200 propos de HoKo", nullptr));
        label_2->setText(QString());
        label_4->setText(QString());
        label->setText(QString());
        label_3->setText(QString());

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("InterfacePrincipale", "Traitement 1", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("InterfacePrincipale", "Traitement 2", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("InterfacePrincipale", "Traitement 3", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("InterfacePrincipale", "Traitement 4", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("InterfacePrincipale", "Traitement 5", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("InterfacePrincipale", "Traitement 6", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        checkBox->setText(QApplication::translate("InterfacePrincipale", "Actif", nullptr));
        pushButton_2->setText(QApplication::translate("InterfacePrincipale", "^", nullptr));
        pushButton_3->setText(QApplication::translate("InterfacePrincipale", "v", nullptr));
        pushButton_4->setText(QApplication::translate("InterfacePrincipale", "Modifier", nullptr));
        pushButton->setText(QApplication::translate("InterfacePrincipale", "Supprimer", nullptr));
        comboBox->setItemText(0, QApplication::translate("InterfacePrincipale", "Traitement", nullptr));
        comboBox->setItemText(1, QApplication::translate("InterfacePrincipale", "Traitement", nullptr));
        comboBox->setItemText(2, QApplication::translate("InterfacePrincipale", "Traitement", nullptr));
        comboBox->setItemText(3, QApplication::translate("InterfacePrincipale", "Traitement", nullptr));
        comboBox->setItemText(4, QApplication::translate("InterfacePrincipale", "Traitement", nullptr));

        pushButton_5->setText(QApplication::translate("InterfacePrincipale", "Ajouter", nullptr));
        menuHoKo->setTitle(QApplication::translate("InterfacePrincipale", "Image", nullptr));
        menuCOnfiguration->setTitle(QApplication::translate("InterfacePrincipale", "Configuration", nullptr));
        menuAide->setTitle(QApplication::translate("InterfacePrincipale", "Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InterfacePrincipale: public Ui_InterfacePrincipale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // 