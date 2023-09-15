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
    ui->lineEditValorSequencial->setValidator(validatorNumeros);
    ui->lineEditValorBinaria->setValidator(validatorNumeros);
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
        ui->lineEditValorSequencial->setFocus();
    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO", erro);
    }

}
void MainWindow::on_pushButtonBuscar_clicked()
{
    try {
        if(ui->lineEditValorSequencial->text().isEmpty()) throw QString ("Digite um valor para a busca");
        QString posicao = QString::number(vetor->buscarNumeroMelhorado(ui->lineEditValorSequencial->text().toInt()));
        ui->lineEditResultadoSequencial->setText("O número "+ ui->lineEditValorSequencial->text() + " existe na posição " + posicao );
        ui->lineEditValorBinaria->setFocus();

    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButtonBuscarBinario_clicked()
{
    try {
        if(ui->lineEditValorBinaria->text().isEmpty()) throw QString ("Digite um valor para a busca");
        QString posicao = QString::number(vetor->buscarBinaria(ui->lineEditValorBinaria->text().toInt()));
        ui->lineEditResultadoBinaria->setText("O número "+ ui->lineEditValorBinaria->text() + " existe na posição " + posicao );
        ui->lineEditValorBinaria->setFocus();

    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO", erro);
    }
}
