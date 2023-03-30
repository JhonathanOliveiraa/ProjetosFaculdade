#include "mainwindow.h"
#include "mudarbase.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButtonCalcular_clicked()
{   
    int pos = ui->comboBoxBase->currentIndex();
    int valor = ui->lineEditNumero->text().toInt();
    int base = 0;
    if (pos == 0) base = 2;
    if (pos == 1) base = 8;
    if (pos == 2) base = 16;

    jhone::MudarBase convert(valor, base);
    ui->textEditResultado->setText(convert.calcularMB());

}


