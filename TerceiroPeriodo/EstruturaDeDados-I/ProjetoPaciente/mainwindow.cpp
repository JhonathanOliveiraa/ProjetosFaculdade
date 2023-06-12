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


void MainWindow::on_BotaoExecutar_clicked()
{
    try {
            Jhone::Paciente pessoa;
            pessoa.setNome(ui->lineEditNome->text());
            pessoa.setPeso(ui->lineEditPeso->text().toInt());
            pessoa.setAltura(ui->lineEditAltura->text().toFloat());
            pessoa.setSexo(ui->comboBoxSexo->currentText());

            QString saida = "Clinica Los Pollos Hermanos\n";
            saida += "Dados do paciente\n";
            saida += "Nome: " + pessoa.getNome() + '\n';
            saida += "Peso: " + QString::number(pessoa.getPeso()) + '\n';
            saida += "Altura: " + QString::number(pessoa.getAltura()) + '\n';
            saida += "Sexo: " + pessoa.getSexo() + '\n';
            saida += "IMC: " + QString::number(pessoa.calcularIMC()) + '\n';
            saida += "Faixa de peso: " + pessoa.calcularFaixaRisco() + '\n';
            saida += "Peso ideal: " + QString::number(pessoa.calcularPesoIdeal()) + '\n';
            ui->textEditSaida->setText(saida);
            ui->lineEditNome->clear();
            ui->lineEditPeso->clear();
            ui->lineEditAltura->clear();
        } catch (QString &error) {
            QMessageBox::critical(this, "ERRO ", error);
        }
    }



