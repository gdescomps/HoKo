#ifndef INTERFACEPRINCIPALE_H
#define INTERFACEPRINCIPALE_H

#include <QMainWindow>
#include <opencv/cv.h>
#include <opencv/highgui.h>
namespace Ui {
class InterfacePrincipale;
}

class InterfacePrincipale : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit InterfacePrincipale(QWidget *parent = 0);
    ~InterfacePrincipale();
    
   
private slots:
	void importerUneImage();

private:
    Ui::InterfacePrincipale *ui;
    cv::Mat imageOriginale;
    bool imageImportee;
};

#endif // INTERFACEPRINCIPALE_H
