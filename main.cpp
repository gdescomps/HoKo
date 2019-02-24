#include "Interface/InterfacePrincipale.h"
#include "Image/GestionImage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionImage gestionImage;

    InterfacePrincipale interfacePrincipale(gestionImage);
    
    interfacePrincipale.showMaximized();
    
    return a.exec();
}