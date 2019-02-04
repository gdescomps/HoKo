
#include "Interface/InterfacePrincipale.h"
#include "ui_InterfacePrincipale.h"
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


InterfacePrincipale::InterfacePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InterfacePrincipale)
{
    ui->setupUi(this);
}

InterfacePrincipale::~InterfacePrincipale()
{
    delete ui;
}
/*
void InterfacePrincipale::on_btnOpen_clicked()
{
    openImage();
}

void InterfacePrincipale::on_btnReset_clicked()
{
    ui->lblImage->clear();
}

void InterfacePrincipale::on_btnToGray_clicked()
{
    toGrayscaleImg();
}
*/