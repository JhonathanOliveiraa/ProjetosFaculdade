#include "telaprincipal.h"
#include "ui_telaprincipal.h"

TelaPrincipal::TelaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TelaPrincipal)
{
    ui->setupUi(this);
    validator = new QRegularExpressionValidator(this);
    validator->setRegularExpression(QRegularExpression("^\\d+$"));
    ui->lineEditAdicionar->setValidator(validator);
    ui->lineEditPosicao->setValidator(validator);
    ui->textEditSaida->setReadOnly(true);
}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
}
jhone::LLDE lista;

void TelaPrincipal::on_pushButtonInserirInicio_clicked()
{
    try {
        int dado=0;
        if(ui->lineEditAdicionar->text().isEmpty()) throw QString ("Insira um valor para preencher a lista");
        dado = ui->lineEditAdicionar->text().toInt();
        lista.inserirInicio(dado);
        ui->textEditSaida->setText(lista.obterLista());
        ui->lineEditAdicionar->clear();
        ui->lineEditAdicionar->setFocus();
    } catch (QString &erro ) {
        QMessageBox::critical(this, "ERRO DO SISTEMA", erro);
    }

}
void TelaPrincipal::on_pushButtonInserirPosicao_clicked()
{
    try {
        int dado=0;
        int posicao=0;
        if(ui->lineEditPosicao->text().isEmpty()) throw QString ("Insira uma posição para continuar");
        if(ui->lineEditAdicionar->text().isEmpty()) throw QString ("Insira um valor para preencher a lista");
        posicao = ui->lineEditPosicao->text().toInt();
        dado = ui->lineEditAdicionar->text().toInt();
        lista.inserirPosicao(dado, posicao);
        ui->textEditSaida->setText((lista.obterLista()));
        ui->lineEditAdicionar->clear();
        ui->lineEditAdicionar->setFocus();
    } catch (QString &erro) {
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}
void TelaPrincipal::on_pushButtonInserirFinal_clicked()
{
    try {
        int dado=0;
        if(ui->lineEditAdicionar->text().isEmpty()) throw QString ("Insira um valor para preencher a lista");
        dado = ui->lineEditAdicionar->text().toInt();
        lista.inserirFinal(dado);
        ui->textEditSaida->setText(lista.obterLista());
        ui->lineEditAdicionar->clear();
        ui->lineEditAdicionar->setFocus();
    } catch (QString &erro ) {
        QMessageBox::critical(this, "ERRO DO SISTEMA", erro);
    }
}
void TelaPrincipal::on_pushButtonAcessarInicio_clicked()
{
    try {
        ui->lineEditAdicionar->setText(QString::number(lista.acessarInicio()));
    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO DO SISTEMA",erro);
    }
}
void TelaPrincipal::on_pushButtonAcessarPosicao_clicked()
{
    try {
        int posicao=0;
        if(ui->lineEditPosicao->text().isEmpty()) throw QString ("Insira uma posição para continuar");
        posicao=ui->lineEditPosicao->text().toInt();
        ui->lineEditAdicionar->setText(QString::number(lista.acessarPosicao(posicao)));
    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO DO SISTEMA", erro);
    }
}
void TelaPrincipal::on_pushButtonAcessarFinal_clicked()
{
    try {
        ui->lineEditAdicionar->setText(QString::number(lista.acessarFinal()));
    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO DO SISTEMA",erro);
    }
}
void TelaPrincipal::on_pushButtonRetirarInicio_clicked()
{
    try {
        ui->lineEditAdicionar->setText(QString::number(lista.retirarInicio()));
        ui->textEditSaida->setText(lista.obterLista());
    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO DO SISTEMA", erro);
    }
}
void TelaPrincipal::on_pushButtonRetirarPosicao_clicked()
{
    try {
        QString resultado = "";
        int posicao=0;
        if(ui->lineEditPosicao->text().isEmpty()) throw QString ("Insira uma posição para continuar");
        posicao = ui->lineEditPosicao->text().toInt();
        resultado += QString::number(lista.retirarPosicao(posicao));
        ui->lineEditAdicionar->setText(resultado);
        ui->textEditSaida->setText(lista.obterLista());
    } catch (QString &erro) {
        QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
    }
}
void TelaPrincipal::on_pushButtonRetirarFinal_clicked()
{
    try {
        ui->lineEditAdicionar->setText(QString::number(lista.retirarFinal()));
        ui->textEditSaida->setText(lista.obterLista());
    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO DO SISTEMA", erro);
    }
}
void TelaPrincipal::on_pushButtonInserirOrdenado_clicked()
{
        try {
            int dado = 0;
            if(ui->lineEditAdicionar->text().isEmpty()){
                ui->lineEditAdicionar->setFocus();
                throw QString ("Por favor insira algum numero inteiro");
            }
            dado = ui->lineEditAdicionar->text().toInt();
            lista.inserirOrdenado(dado);
            ui->textEditSaida->setText((lista.obterLista()));
            ui->lineEditAdicionar->clear();
            ui->lineEditAdicionar->setFocus();
        } catch (QString &erro) {
            QMessageBox::critical(this,"ERRO DO SISTEMA",erro);
        }
}

