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
 /*   
private slots:
    void on_btnOpen_clicked();
    void on_btnReset_clicked();
    void on_btnToGray_clicked();
*/
private:
    Ui::InterfacePrincipale *ui;

};

#endif // INTERFACEPRINCIPALE_H
