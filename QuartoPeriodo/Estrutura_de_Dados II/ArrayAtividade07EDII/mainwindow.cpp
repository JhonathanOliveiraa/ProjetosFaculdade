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
    ui->textEdit->isReadOnly();
    ui->textEditOrdenadoInsertion->isReadOnly();
    ui->textEditOrdenadoSelection->isReadOnly();
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

        ui->textEditOrdenadoSelection->setText(vetor->getConjuntoOrdenadoSelectionSort());
        ui->textEditOrdenadoInsertion->setText(vetor->getConjuntoOrdenadoInsertionSort());

        ui->textEditTempoSS->setText(QString::number(vetor->medicaoSelectionSort()) + " Ms");
        ui->textEditTempoIS->setText(QString::number(vetor->medicaoInsertionSort()) + " Ms");

        ui->textEditExecOrdenSelection->setText(QString::number(vetor->getNumOrdenSelectionSort()));
        ui->textEditExecOrdenInsertion->setText(QString::number(vetor->getNumOrdenInsertionSort()));


    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO", erro);
    }

}


