#include "mainwindow.h"
#include "ui_mainwindow.h"


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

void MainWindow::on_button_imprimirIt_clicked()
{
    QString saida="";
    int n = ui->lineEdit_numMax->text().toInt();
    if(n<=1){
        QMessageBox::information(this,"","VALOR INVÁLIDO, DIGITE UM VALOR POSITIVO MAIOR QUE 1");
        return;
    }
    saida = aux.imprimirIterativo(n);
    ui->textEdit->setText(saida);
}

void MainWindow::on_button_imprimitRecurs_clicked()
{
    QString saida="";
    int n = ui->lineEdit_numMax->text().toInt();
    if(n<=1){
        QMessageBox::information(this,"","VALOR INVÁLIDO, DIGITE UM VALOR POSITIVO MAIOR QUE 1");
        return;
    }
    saida = aux.imprimirRecursivo(n, 1, "");
    ui->textEdit->setText(saida);
}

void MainWindow::on_button_paresIt_clicked()
{
    QString saida="";
    int n = ui->lineEdit_numMax->text().toInt();
    if(n<=1){
        QMessageBox::information(this,"","VALOR INVÁLIDO, DIGITE UM VALOR POSITIVO MAIOR QUE 1");
        return;
    }
    saida = aux.imprimirParesIterativo(n);
    ui->textEdit->setText(saida);
}

void MainWindow::on_button_paresRecurs_clicked()
{
    QString saida="";
    int n = ui->lineEdit_numMax->text().toInt();
    if(n<=1){
        QMessageBox::information(this,"","VALOR INVÁLIDO, DIGITE UM VALOR POSITIVO MAIOR QUE 1");
        return;
    }
    saida = aux.imprimirParesRecursivo(n, 1, "");
    ui->textEdit->setText(saida);
}

void MainWindow::on_button_imparIt_clicked()
{
    QString saida="";
    int n = ui->lineEdit_numMax->text().toInt();
    if(n<=1){
        QMessageBox::information(this,"","VALOR INVÁLIDO, DIGITE UM VALOR POSITIVO MAIOR QUE 1");
        return;
    }
    saida = aux.imprimirImparesIterativo(n);
    ui->textEdit->setText(saida);
}

void MainWindow::on_button_imparRecurs_clicked()
{
    QString saida="";
    int n = ui->lineEdit_numMax->text().toInt();
    if(n<=1){
        QMessageBox::information(this,"","VALOR INVÁLIDO, DIGITE UM VALOR POSITIVO MAIOR QUE 1");
        return;
    }
    saida = aux.imprimirImparesRecursivo(n, 1, "");
    ui->textEdit->setText(saida);
}

void MainWindow::on_button_imparIt_2_clicked()
{
    QString saida="";
    int n = ui->lineEdit_numMax->text().toInt();
    if(n<=1){
        QMessageBox::information(this,"","VALOR INVÁLIDO, DIGITE UM VALOR POSITIVO MAIOR QUE 1");
        return;
    }
    saida = aux.somarIterativo(n);
    ui->textEdit->setText(saida);
}


void MainWindow::on_button_imparRecurs_2_clicked()
{
    QString saida="";
    int n = ui->lineEdit_numMax->text().toInt();
    if(n<=1){
        QMessageBox::information(this,"","VALOR INVÁLIDO, DIGITE UM VALOR POSITIVO MAIOR QUE 1");
        return;
    }
    saida = aux.somarRecursivo(n, 1, 0, "");
    ui->textEdit->setText(saida);
}

void MainWindow::on_button_imparIt_3_clicked()
{
    QString saida="";
    saida = aux.piPrecisaoIterativo();
    std::cout<<std::fixed<<std::setprecision(4);
    ui->textEdit->setText(saida);
}


void MainWindow::on_button_imparRecurs_3_clicked()
{
    QString saida="";
    saida = QString::number(aux.piPrecisaoRecursivo(0, 1, 1));
    std::cout<<std::fixed<<std::setprecision(4);
    ui->textEdit->setText(saida);
}

