#include "Interface/InterfacePrincipale.h"
#include "Image/GestionImage.h"
#include "Traitement/GestionTraitement.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionImage gestionImage;
    GestionTraitement gestionTraitement;

    InterfacePrincipale interfacePrincipale(gestionImage, gestionTraitement);
    
    interfacePrincipale.showMaximized();
    
    return a.exec();
}