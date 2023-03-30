#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    validator = new QRegularExpressionValidator(this);
    validator->setRegularExpression(QRegularExpression("^\\d+$"));
    ui->lineEditValor->setValidator(validator);
}
MainWindow::~MainWindow()
{
    delete ui;
}

Jhone::LLSE lista;

void MainWindow::on_pushButtonIncluirInicio_clicked()
{
    try {
        int dado=0;
        if(ui->lineEditValor->text().isEmpty()) throw QString ("Insira um valor para preencher a lista");
        dado = ui->lineEditValor->text().toInt();
        lista.inserirInicio(dado);
        ui->textEditSaida->setText((lista.obterDadosLLSE()));
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
        ui->textEditQuantidadeElementos->setText(QString::number(lista.getQuantidadeElementos()));
    } catch (QString &erro) {
        ui->textEditQuantidadeElementos->setText("0");
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}
void MainWindow::on_pushButtonRetirarInicio_clicked()
{
    try {
        QString saida = "";
        saida += QString::number(lista.retirarInicio());
        ui->lineEditValor->setText(saida);
        ui->textEditSaida->setText(lista.obterDadosLLSE());
        ui->textEditQuantidadeElementos->setText(QString::number(lista.getQuantidadeElementos()));
    } catch (QString &erro) {
        ui->textEditQuantidadeElementos->setText("0");
        ui->textEditSaida->setText("{ A fila está vazia }");
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}
void MainWindow::on_pushButtonAcessarInicio_clicked()
{
    try {
        QString saida = "";
        saida += QString::number(lista.acessarInicio());
        ui->lineEditValor->setText(saida);
    } catch (QString &erro) {
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}
void MainWindow::on_pushButtonIncluirFinal_clicked()
{
    try {
        int dado = 0;
        if(ui->lineEditValor->text().isEmpty()) throw QString ("Insira um valor para preencher a lista");
        dado = ui->lineEditValor->text().toInt();
        lista.inserirFinal(dado);
        ui->textEditSaida->setText((lista.obterDadosLLSE()));
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
        ui->textEditQuantidadeElementos->setText(QString::number(lista.getQuantidadeElementos()));
    }
    catch (QString &erro) {
        ui->textEditQuantidadeElementos->setText("0");
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}
void MainWindow::on_pushButtonAcessarFinal_clicked()
{
    try {
            QString saida = "";
            saida += QString::number(lista.acessarFinal());
            ui->lineEditValor->setText(saida);
        } catch (QString &erro) {
            QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
        }
}
void MainWindow::on_pushButtonRetirarFinal_clicked()
{
    try {
        QString resultado = "";
        resultado += QString::number(lista.retirarFinal());
        ui->lineEditValor->setText(resultado);
        ui->textEditSaida->setText(lista.obterDadosLLSE());
        ui->textEditQuantidadeElementos->setText(QString::number(lista.getQuantidadeElementos()));
    } catch (QString &erro) {
        ui->textEditQuantidadeElementos->setText("0");
        ui->textEditSaida->setText("{ A fila está vazia }");
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}

