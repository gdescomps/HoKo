#ifndef FENETREMODIFIER_H
#define FENETREMODIFIER_H

#include <QDialog>

namespace Ui {
class FenetreModifier;
}

class FenetreModifier : public QDialog
{
    Q_OBJECT

public:
    explicit FenetreModifier(QWidget *parent = nullptr);
    ~FenetreModifier();

private slots:
    void on_validerBouton_clicked();
    void on_pushButton_clicked();

	void on_spinBoxLargeurNoyau_valueChanged(int largeurNoyau);
    void on_spinBoxHauteurNoyau_valueChanged(int hauteurNoyau);
    void on_doubleSpinBoxSigma_valueChanged(double sigma);
private:
    Ui::FenetreModifier *ui;
    int largeurNoyau;
    int hauteurNoyau;
    double sigma;
};

#endif // FENETREMODIFIER_H
