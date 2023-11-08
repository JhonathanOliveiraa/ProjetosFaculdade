#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arquivo.buscarArquivo();
    ui->tableWidget->setColumnWidth(0,662);
    arquivo.excluir(1);
    ui->tableWidget->setStyleSheet("background-color: rgba(255, 255, 255, 128);");
    mostrarNaGrid();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mostrarNaGrid()
{
    try {
        ui->tableWidget->setRowCount(0);
        for (int i = 0; i < 1000; i++) {
            int linha = ui->tableWidget->rowCount();

            ui->tableWidget->insertRow(linha);
            QTableWidgetItem *item1 = new QTableWidgetItem(arquivo.getVetor()[i].getNome());
            ui->tableWidget->setItem(linha,0,item1);
        }
    } catch(QString &erro){
         QMessageBox::information(this,"ERRO",erro);
    }
}
void MainWindow::on_pushButtonGerar_clicked()
{
    try {
        mostrarNaGrid();
    } catch (QString &erro){
         QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonConsultar_clicked()
{
    try {
        if(ui->lineEditIndice->text().isEmpty()) throw QString("Adicione a matrícula para a consulta");
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->insertRow(0);
        QTableWidgetItem *item = new QTableWidgetItem(arquivo.consultar(ui->lineEditIndice->text().toInt()).getNome());
        ui->tableWidget->setItem(0,0,item);
    } catch (QString &erro) {
         QMessageBox::information(this,"ERRO",erro);
    }

}


void MainWindow::on_pushButtonAlterar_clicked()
{
    try {
        if(ui->lineEditIndice->text().isEmpty()) throw QString("Adicione a matrícula para a alteração");
        arquivo.alterar(ui->lineEditIndice->text().toInt(),ui->lineEditNome->text());
        mostrarNaGrid();
    } catch (QString &erro) {
         QMessageBox::information(this,"ERRO",erro);
    }

}


void MainWindow::on_pushButtonExcluir_clicked()
{
    try {
        if(ui->lineEditIndice->text().isEmpty()) throw QString("Adicione a matrícula para a exclusão");
        arquivo.excluir(ui->lineEditIndice->text().toInt());
        mostrarNaGrid();
    } catch (QString &erro) {
         QMessageBox::information(this,"ERRO",erro);
    }

}


void MainWindow::on_pushButtonInserir_clicked()
{
    try {
        if(ui->lineEditIndice->text().isEmpty()) throw QString("Adicione a matrícula para a inserção");
        if(ui->lineEditNome->text().isEmpty()) throw QString("Adicione o nome para a inserção");
        arquivo.inserir(ui->lineEditIndice->text().toInt(),ui->lineEditNome->text());
        mostrarNaGrid();
    } catch (QString &erro) {
         QMessageBox::information(this,"ERRO",erro);
    }
}

