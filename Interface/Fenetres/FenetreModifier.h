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

private:
    Ui::FenetreModifier *ui;
};

#endif // FENETREMODIFIER_H
