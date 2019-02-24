#ifndef INTERFACEPRINCIPALE_H
#define INTERFACEPRINCIPALE_H

#include <QMainWindow>
#include "Image/GestionImage.h"

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>
#include <cmath>

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
    void majImage1(cv::Mat image);
    void majImage2(cv::Mat image);
    void majImage3(cv::Mat image);
    void majImage4(cv::Mat image);
    GestionImage gestionImage;
   
private slots:
	void importerUneImage();
	void on_ajouterBouton_clicked();
    

private:
    Ui::InterfacePrincipale *ui;
    cv::Mat redimensionner(cv::Mat image);
    
};

#endif // INTERFACEPRINCIPALE_H
