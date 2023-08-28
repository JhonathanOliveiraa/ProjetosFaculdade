#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegularExpressionValidator *validatorNumeros = new QRegularExpressionValidator(this);
    validatorNumeros->setRegularExpression(QRegularExpression("^\\d+$"));
    ui->lineEditTamanho->setValidator(validatorNumeros);
    ui->lineEditValor->setValidator(validatorNumeros);
    ui->textEdit->isReadOnly();
    ui->lineEditTamanho->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonGerar_clicked()
{
    try {

        if(ui->lineEditTamanho->text().isEmpty()) {
            ui->lineEditTamanho->setFocus();
            throw QString ("Digite um tamanho para o vetor");
        }
        vetor = new jhone::VetorAleatorio (ui->lineEditTamanho->text().toInt());
        ui->textEdit->setText(vetor->getConjunto());
        vetor->selectionSort();
        ui->textEditOrdenado->setText(vetor->getConjuntoOrdenado());
        ui->lineEditValor->setFocus();
    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO", erro);
    }

}
void MainWindow::on_pushButtonBuscar_clicked()
{
    try {
        if(ui->lineEditValor->text().isEmpty()) throw QString ("Digite um valor para a busca");
        QString posicao = QString::number(vetor->buscarNumeroMelhorado(ui->lineEditValor->text().toInt()));
        ui->lineEditResultado->setText("O número "+ ui->lineEditValor->text() + " existe na posição " + posicao );
        ui->lineEditValor->setFocus();

    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO", erro);
    }
}

