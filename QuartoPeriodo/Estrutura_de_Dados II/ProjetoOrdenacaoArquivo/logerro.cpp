#include "logerro.h"
#include "ui_logerro.h"

logErro::logErro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logErro)
{
    ui->setupUi(this);
    ui->textEdit->setText(Leitor->obterLogErro());
}

logErro::~logErro()
{
    delete ui;
}
