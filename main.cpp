#include "Interface/InterfacePrincipale.h"
#include "Image/GestionImage.h"
#include "Traitement/GestionTraitement.h"
#include "Controleur.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionImage gestionImage;
    GestionTraitement gestionTraitement;
    
    Controleur controleur;

	controleur.getInterface()->showMaximized();
    
    return a.exec();
}