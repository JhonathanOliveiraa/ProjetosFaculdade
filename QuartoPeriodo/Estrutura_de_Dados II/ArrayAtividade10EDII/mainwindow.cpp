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

        clock_t tempoInicialSS = clock();
        ui->textEditOrdenadoSelection->setText(vetor->getConjuntoOrdenadoSelectionSort()); // manda ordenar pelo SelectionSort
        clock_t tempoFinalSS = clock();
        double tempoDeRespostaSS = (tempoFinalSS - tempoInicialSS) / static_cast<double>(CLOCKS_PER_SEC) * 1000;
        ui->textEditTempoSS->setText(QString::number(tempoDeRespostaSS) + " Ms");

        clock_t tempoInicialIS = clock();
        ui->textEditOrdenadoInsertion->setText(vetor->getConjuntoOrdenadoInsertionSort()); // manda ordenar pelo InsertionSort
        clock_t tempoFinalIS = clock();
        double tempoDeRespostaIS = (tempoFinalIS - tempoInicialIS) / static_cast<double>(CLOCKS_PER_SEC) * 1000;
        ui->textEditTempoIS->setText(QString::number(tempoDeRespostaIS) + " Ms");

        clock_t tempoInicialBS = clock();
        ui->textEditOrdenadoBubble->setText(vetor->getConjuntoOrdenadoBubbleSort()); // manda ordenar pelo BubbleSort
        clock_t tempoFinalBS = clock();
        double tempoDeRespostaBS = (tempoFinalBS - tempoInicialBS) / static_cast<double>(CLOCKS_PER_SEC) * 1000;
        ui->textEditTempoBS->setText(QString::number(tempoDeRespostaBS) + " Ms");

        clock_t tempoInicialMS = clock();
        ui->textEditOrdenadoMerge->setText(vetor->getConjuntoOrdenadoMergeSort()); // manda ordenar pelo BubbleSort
        clock_t tempoFinalMS = clock();
        double tempoDeRespostaMS = (tempoFinalMS - tempoInicialMS) / static_cast<double>(CLOCKS_PER_SEC) * 1000;
        ui->textEditTempoMS->setText(QString::number(tempoDeRespostaMS) + " Ms");

        clock_t tempoInicialHS = clock();
        ui->textEditOrdenadoHeap->setText(vetor->getConjuntoOrdenadoHeapSort()); // manda ordenar pelo BubbleSort
        clock_t tempoFinalHS = clock();
        double tempoDeRespostaHS = (tempoFinalHS - tempoInicialHS) / static_cast<double>(CLOCKS_PER_SEC) * 1000;
        ui->textEditTempoHS->setText(QString::number(tempoDeRespostaHS) + " Ms");

        ui->textEditExecOrdenBubble->setText(QString::number(vetor->getNumOrdenBubbleSort()));
        ui->textEditExecOrdenSelection->setText(QString::number(vetor->getNumOrdenSelectionSort()));
        ui->textEditExecOrdenInsertion->setText(QString::number(vetor->getNumOrdenInsertionSort()));
    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO", erro);
    }

}


