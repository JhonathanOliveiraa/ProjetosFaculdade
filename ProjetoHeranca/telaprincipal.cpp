#include "telaprincipal.h"
#include "figurageometrica.h"
#include "ui_telaprincipal.h"

TelaPrincipal::TelaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TelaPrincipal)
{
    ui->setupUi(this);
    QPixmap sonic("C:/Users/jhone/OneDrive/Documentos/TÉCNICAS DE PROGRAMAÇÃO II - 2023/ProjetoHeranca/Arquivos/sonic.jpg");
    ui->z->setPixmap(sonic.scaled(1000,1200,Qt::KeepAspectRatio));
}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
}


void TelaPrincipal::on_pushButtonCalcular_clicked()
{
    try {
        int pos=ui->comboBoxTipoFigura->currentIndex();
        if(pos==0){
            float raio=ui->lineEditValorRaio->text().toFloat();
            jhone::Esfera teste(raio);
            QString saida = teste.toString();
            saida += "\n" + teste.obterTipoFigura();
            saida += "\nÁrea total: " + QString::number(teste.calcularAreaTotal());
            saida += "\nVolume total: " + QString::number(teste.calcularVolume());
            ui->textEditSaida->setText(saida);
        }
        if(pos==1){
            float raio=ui->lineEditValorRaio->text().toFloat();
            float altura=ui->lineEditValorAltura->text().toFloat();
            jhone::Cilindro teste(raio,altura);
            QString saida = teste.toString();
            saida += "\n" + teste.obterTipoFigura();
            saida += "\nÁrea lateral: " + QString::number(teste.calcularAreaLateral());
            saida += "\nArea total: " + QString::number(teste.calcularAreaTotal());
            saida += "\nVolume total: " + QString::number(teste.calcularVolume());
            ui->textEditSaida->setText(saida);
        }
        if(pos==2){
            float raio=ui->lineEditValorRaio->text().toFloat();
            float altura=ui->lineEditValorAltura->text().toFloat();
            jhone::Cone teste(raio,altura);
            QString saida = teste.toString();
            saida += "\n" + teste.obterTipoFigura();
            saida += "\nGeratriz: " + QString::number(teste.calcularGeratriz());
            saida += "\nÁrea lateral: " + QString::number(teste.calcularAreaLateral());
            saida += "\nÁrea total: " + QString::number(teste.calcularAreaTotal());
            saida += "\nVolume total: " + QString::number(teste.calcularVolume());
            ui->textEditSaida->setText(saida);
        }
       } catch (QString &erro) {
           QMessageBox::information(this, "ERRO DO SISTEMA" ,erro);
       }
   }


// Classe concreta : Pode ser instanciada pois todos os métodos tem código
// Classe abstrata : Não pode ser instanciada, pois não tem código dentro de método (um método abstrato)
