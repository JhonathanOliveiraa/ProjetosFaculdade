#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap fila("C:/Users/jhone/OneDrive/Documentos/ProjetoFila/Arquivos/fila.jpg");
    ui->z->setPixmap(fila.scaled(811,1000,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
   delete objetoArray;
   objetoArray = nullptr;
   delete ui;
}

void MainWindow::on_pushButtonCriar_clicked()
{
    try {
        objetoArray = new jhone::OrdenacaoVetor(ui->lineEditQuantidadeElementos->text().toInt());
        ui->textEditVetorOriginal->setText(objetoArray->mostrarResultado());
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButtonExecutar_clicked()
{
    try
       {
           if (ui->comboBox->currentText() == "Crescente")
           {
               objetoArray->ordenarCrescente();
           }
           else
           {
               objetoArray->ordenarDecrescente();
           }
           ui->textEditVetorOrdenado->setText(objetoArray->mostrarResultado());
       }
       catch (QString &erro)
       {
           QMessageBox::critical(this, "Erro ", erro);
       }
   }

