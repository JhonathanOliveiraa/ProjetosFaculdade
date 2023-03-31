#include "telaprincipal.h"
#include "figurageometrica.h"
#include "ui_telaprincipal.h"

TelaPrincipal::TelaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TelaPrincipal)
{
    ui->setupUi(this);
    if(ui->comboBoxTipoFigura->currentIndex() == 0) ui->lineEditValorAltura->setEnabled(false);
}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
}

void TelaPrincipal::on_comboBoxTipoFigura_currentIndexChanged(int aux)
{
    if(aux==0) ui->lineEditValorAltura->setEnabled(false);
    else{
        ui->lineEditValorAltura->setEnabled(true);
    }
}

void TelaPrincipal::on_pushButtonCalcular_clicked()
{
    try {
        if(ui->comboBoxTipoFigura->currentIndex()==0){
            float raio=ui->lineEditValorRaio->text().toFloat();
            jhone::Esfera teste(raio);
            QString saida = teste.toString();
            saida += "\n" + teste.obterTipoFigura();
            saida += "\nÁrea total: " + QString::number(teste.calcularAreaTotal());
            saida += "\nVolume total: " + QString::number(teste.calcularVolume());
            ui->textEditSaida->setText(saida);
        }
        if(ui->comboBoxTipoFigura->currentIndex()==1){
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
        if(ui->comboBoxTipoFigura->currentIndex()==2){
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


