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
    ui->lineEditPosicao->setValidator(validator);
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
        ui->textEditQuantidadeElementos->setText(QString::number(lista.getQuantidadeElementos()));
        ui->textEditSaida->setText((lista.obterDadosLLSE()));
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
    } catch (QString &erro) {
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}
void MainWindow::on_pushButtonRetirarInicio_clicked()
{
    try {
        QString saida = "";
        saida += QString::number(lista.retirarInicio());
        ui->textEditQuantidadeElementos->setText(QString::number(lista.getQuantidadeElementos()));
        ui->lineEditValor->setText(saida);
        ui->textEditSaida->setText(lista.obterDadosLLSE());
    } catch (QString &erro) {
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
        ui->textEditQuantidadeElementos->setText(QString::number(lista.getQuantidadeElementos()));
        ui->lineEditValor->setText(resultado);
        ui->textEditSaida->setText(lista.obterDadosLLSE());
    } catch (QString &erro) {
        ui->textEditSaida->setText("{ A fila está vazia }");
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}
void MainWindow::on_pushButtonAcessarPosicao_clicked()
{
    try {
        int posicao=0;
        if(ui->lineEditPosicao->text().isEmpty()) throw QString ("Insira uma posição para continuar");
        posicao=ui->lineEditPosicao->text().toInt();
        ui->lineEditValor->setText(QString::number(lista.acessarPosicao(posicao)));
    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO DO SISTEMA", erro);
    }
}

void MainWindow::on_pushButtonInserirPosicao_clicked()
{
    try {
        int dado=0;
        int posicao=0;
        if(ui->lineEditPosicao->text().isEmpty()) throw QString ("Insira uma posição para continuar");
        if(ui->lineEditValor->text().isEmpty()) throw QString ("Insira um valor para preencher a lista");
        posicao = ui->lineEditPosicao->text().toInt();
        dado = ui->lineEditValor->text().toInt();
        lista.inserirPosicao(dado, posicao);
        ui->textEditQuantidadeElementos->setText(QString::number(lista.getQuantidadeElementos()));
        ui->textEditSaida->setText((lista.obterDadosLLSE()));
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
    } catch (QString &erro) {
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}
void MainWindow::on_pushButton_clicked()
{
    try {
        QString resultado = "";
        int posicao=0;
        if(ui->lineEditPosicao->text().isEmpty()) throw QString ("Insira uma posição para continuar");
        posicao = ui->lineEditPosicao->text().toInt();
        resultado += QString::number(lista.retirarPosicao(posicao));
        ui->textEditQuantidadeElementos->setText(QString::number(lista.getQuantidadeElementos()));
        ui->lineEditValor->setText(resultado);
        ui->textEditSaida->setText(lista.obterDadosLLSE());
    } catch (QString &erro) {
        ui->textEditSaida->setText("{ A fila está vazia }");
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}


