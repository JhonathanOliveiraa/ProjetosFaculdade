#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpixmap.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    nomeDoArquivoNoDisco("")
{
    ui->setupUi(this);
    ui->lineEditNomeDoArquivo->setEnabled(false);
    ui->tableWidgetLista->setColumnWidth(0,150);
    ui->tableWidgetLista->setColumnWidth(1,150);
    ui->tableWidgetLista->setColumnWidth(2,150);
    ui->tableWidgetLista->setColumnWidth(3,198);
    QPixmap starwars("/home/puc/Área de Trabalho/ProjetoFormulaUm/Arquivos/STARWARS.png");
    QPixmap background("/home/puc/Área de Trabalho/ProjetoFormulaUm/Arquivos/ESPACO.jpg");
    QPixmap vader("/home/puc/Área de Trabalho/ProjetoFormulaUm/Arquivos/VADER.png");
    QPixmap anakin("/home/puc/Área de Trabalho/ProjetoFormulaUm/Arquivos/ANAKIN.png");
    ui->z->setPixmap(starwars.scaled(821,621,Qt::KeepAspectRatio));
    ui->z2->setPixmap(background.scaled(831,1200,Qt::KeepAspectRatio));
    ui->z3->setPixmap(vader.scaled(370,675,Qt::KeepAspectRatio));
    ui->z4->setPixmap(anakin.scaled(370,675,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonBuscar_clicked()
{
    try {

        // nomeDoArquivo - atributo da classe MainWindow
                //Buscando o arquivo no disco
        nomeDoArquivoNoDisco = QFileDialog::getOpenFileName(this,"Abrir Arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt *.*)");
        if(nomeDoArquivoNoDisco.isEmpty()) throw QString("Arquivo nao foi selecionado");
        ui->lineEditNomeDoArquivo->setText(nomeDoArquivoNoDisco);
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA",erro);
    }
}
void MainWindow::on_pushButtonCalcular_clicked()
{
    try {
        jhone::ManipularArquivos teste(this->nomeDoArquivoNoDisco);
        teste.buscarDadosNoArquivo();
        std::vector<jhone::Piloto> pilotosF1 = teste.getListaDePilotosF1();

        for (int i = 0; i < (int)pilotosF1.size(); i++) {
            int linha = ui->tableWidgetLista->rowCount();
            ui->tableWidgetLista->insertRow(linha);
            QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(pilotosF1[i].getCodigo()));
            ui->tableWidgetLista->setItem(linha,0,item1);
            QTableWidgetItem *item2 = new QTableWidgetItem(pilotosF1[i].getNome());
            ui->tableWidgetLista->setItem(linha,1,item2);
            QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(pilotosF1[i].getPontuacaoFinal()));
            ui->tableWidgetLista->setItem(linha,2,item3);
            QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(i+1));
            ui->tableWidgetLista->setItem(linha,3,item4);
        }
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }

}

