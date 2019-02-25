#ifndef INTERFACEPRINCIPALE_H
#define INTERFACEPRINCIPALE_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
namespace Ui {
class InterfacePrincipale;
}

class InterfacePrincipale : public QMainWindow
{
	Q_OBJECT

public:
	explicit InterfacePrincipale(QWidget *parent = 0);
	~InterfacePrincipale();
	void resizeEvent(QResizeEvent*);

private slots:
	void importerUneImage();
	void afficherGuide();
	void afficherApropos();
	void sauvegarderImageFinale();

private:
	Ui::InterfacePrincipale *ui;
	cv::Mat imageOriginale;
	bool imageImportee;
};

#endif // INTERFACEPRINCIPALE_H