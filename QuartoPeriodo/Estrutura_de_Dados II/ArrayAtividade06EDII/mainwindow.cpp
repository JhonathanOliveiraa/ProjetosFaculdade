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
    ui->lineEditValorSequencialMelhorada->setValidator(validatorNumeros);
    ui->lineEditValorBinaria->setValidator(validatorNumeros);
    ui->textEdit->isReadOnly();
    ui->textEditExecBinaria->isReadOnly();
    ui->textEditExecSequencial->isReadOnly();
    ui->textEditExecSequencialMelhorada->isReadOnly();
    ui->textEditOrdenado->isReadOnly();
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
        ui->textEditExecOrden->setText(QString::number(vetor->getNumExec()));
        ui->textEditOrdenado->setText(vetor->getConjuntoOrdenado());
        ui->lineEditValorSequencial->setFocus();
    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO", erro);
    }

}
void MainWindow::on_pushButtonBuscarAleatorio_clicked()
{
    try {
        ui->textEditExecSequencial->clear();
        if(ui->lineEditValorSequencial->text().isEmpty()) throw QString ("Digite um valor para a busca");
        if(vetor->buscarNumero(ui->lineEditValorSequencial->text().toInt())==-1){
            ui->textEditExecSequencial->setText(QString::number(vetor->getNumExec()));
            ui->lineEditResultadoSequencial->clear();
            throw QString ("O número não existe.");
        }
        QString posicao = QString::number(vetor->buscarNumero(ui->lineEditValorSequencial->text().toInt()));
        ui->lineEditResultadoSequencial->setText("O número "+ ui->lineEditValorSequencial->text() + " existe na posição " + posicao );
        ui->textEditExecSequencial->setText(QString::number(vetor->getNumExec()));
        ui->lineEditValorSequencialMelhorada->setFocus();

    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButtonBuscarMelhorada_clicked()
{
    try {
        ui->textEditExecSequencialMelhorada->clear();

        if(ui->lineEditValorSequencialMelhorada->text().isEmpty()) throw QString ("Digite um valor para a busca");
        if(vetor->buscarNumeroMelhorado(ui->lineEditValorSequencialMelhorada->text().toInt())==-1){
            ui->textEditExecSequencialMelhorada->setText(QString::number(vetor->getNumExec()));
            ui->lineEditResultadoSequencialMelhorada->clear();
            throw QString ("O número não existe.");
        }
        QString posicao = QString::number(vetor->buscarNumeroMelhorado(ui->lineEditValorSequencialMelhorada->text().toInt()));
        ui->lineEditResultadoSequencialMelhorada->setText("O número "+ ui->lineEditValorSequencialMelhorada->text() + " existe na posição " + posicao );
        ui->textEditExecSequencialMelhorada->setText(QString::number(vetor->getNumExec()));
        ui->lineEditValorBinaria->setFocus();

    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButtonBuscarBinario_clicked()
{

    try {
        ui->textEditExecBinaria->clear();
        if(ui->lineEditValorBinaria->text().isEmpty()) throw QString ("Digite um valor para a busca");
        if(vetor->buscarBinaria(ui->lineEditValorBinaria->text().toInt())==-1){
            ui->textEditExecBinaria->setText(QString::number(vetor->getNumExec()));
            ui->lineEditResultadoBinaria->clear();
            throw QString ("O número não existe.");
        }
        QString posicao = QString::number(vetor->buscarBinaria(ui->lineEditValorBinaria->text().toInt()));
        ui->lineEditResultadoBinaria->setText("O número "+ ui->lineEditValorBinaria->text() + " existe na posição " + posicao );
        ui->textEditExecBinaria->setText(QString::number(vetor->getNumExec()));
        ui->lineEditValorBinaria->setFocus();

    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO", erro);
    }
}


