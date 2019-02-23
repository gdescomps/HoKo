#include "FenetreModifier.h"
#include "ui_FenetreModifier.h"

FenetreModifier::FenetreModifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreModifier)
{
    ui->setupUi(this);
}

FenetreModifier::~FenetreModifier()
{
    delete ui;
}
