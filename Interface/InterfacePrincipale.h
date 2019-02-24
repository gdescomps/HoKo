#ifndef INTERFACEPRINCIPALE_H
#define INTERFACEPRINCIPALE_H

#include <QMainWindow>
#include "Image/GestionImage.h"

namespace Ui {
class InterfacePrincipale;
}

class InterfacePrincipale : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit InterfacePrincipale(GestionImage gestionImage, QWidget *parent = 0);
    
    ~InterfacePrincipale();
    void resizeEvent(QResizeEvent*);

   
private slots:
	void importerUneImage();
	void on_ajouterBouton_clicked();
    

private:
    Ui::InterfacePrincipale *ui;
    GestionImage gestionImage;
};

#endif // INTERFACEPRINCIPALE_H
