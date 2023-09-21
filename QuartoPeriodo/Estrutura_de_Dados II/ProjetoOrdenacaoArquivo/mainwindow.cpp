#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try {
        ui->tableWidget->setColumnWidth(0,90);
        ui->tableWidget->setColumnWidth(1,285);
        ui->tableWidget->setColumnWidth(2,95);
        ui->tableWidget->setColumnWidth(3,85);
        LeitorObjeto.buscarArquivos();
        objProf = LeitorObjeto.getArray();
        imprimirNaGrid(objProf);
        }

    catch (QString &erro) {
        QMessageBox::information(this, "ERRO", erro);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::imprimirNaGrid(std::vector<jhone::Professor> dados){
    try {
        ui->tableWidget->setRowCount(0);
        for (int i = 0; i < (int)dados.size(); i++) {
            int linha = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(linha);
            QTableWidgetItem *item1 = new QTableWidgetItem((dados[i].getMatricula()));
            ui->tableWidget->setItem(linha,0,item1);
            QTableWidgetItem *item2 = new QTableWidgetItem(dados[i].getNome());
            ui->tableWidget->setItem(linha,1,item2);
            QTableWidgetItem *item3 = new QTableWidgetItem((dados[i].getDepartamento()));
            ui->tableWidget->setItem(linha,2,item3);
            QTableWidgetItem *item4 = new QTableWidgetItem((dados[i].getTitulacao()));
            ui->tableWidget->setItem(linha,3,item4);
            QTableWidgetItem *item5 = new QTableWidgetItem((dados[i].getTipoDeContrato()));
            ui->tableWidget->setItem(linha,4,item5);
        }
    }
    catch (QString &erro) {
        QMessageBox::information(this, "ERRO", erro);
    }
}


void MainWindow::on_pushButtonOrdenar_clicked()
{
    try {
        if(ui->comboBox_ordenacao->currentIndex()==0){
        jhone::OrdenarMatricula objetoMatricula;
        std::vector<jhone::Professor> dadosMatricula = objetoMatricula.arraySelectionSort();
        imprimirNaGrid(dadosMatricula);
        }
        if(ui->comboBox_ordenacao->currentIndex()==1){
        jhone::OrdenarNome objetoNome;
        std::vector<jhone::Professor> dadosNome = objetoNome.arraySelectionSort();
        imprimirNaGrid(dadosNome);
        }
        if(ui->comboBox_ordenacao->currentIndex()==2){
        jhone::OrdenarDepartamentoNome objetoDepartamentoNome;
        std::vector<jhone::Professor> dadosDepartamento = objetoDepartamentoNome.arraySelectionSort();
        imprimirNaGrid(dadosDepartamento);
        }

        if(ui->comboBox_ordenacao->currentIndex()==3){
        jhone::OrdenarTitulacao objetoTitulacaoNome;
        std::vector<jhone::Professor> dadosTitulacao_Nome = objetoTitulacaoNome.arraySelectionSort();
        imprimirNaGrid(dadosTitulacao_Nome);
        }
        if(ui->comboBox_ordenacao->currentIndex()==4){
        jhone::OrdenarTipoDeContrato objetoTipoDeContratoNome;
        std::vector<jhone::Professor> dadosTipoDeContrato_Nome = objetoTipoDeContratoNome.arraySelectionSort();
        imprimirNaGrid(dadosTipoDeContrato_Nome);
        }
        if(ui->comboBox_ordenacao->currentIndex()==5){
        jhone::OrdenarDepartamento objetoDepartamento_Titulacao_Nome;
        std::vector<jhone::Professor> dadosDepartamento_Titulacao_Nome = objetoDepartamento_Titulacao_Nome.arraySelectionSort();
        imprimirNaGrid(dadosDepartamento_Titulacao_Nome);
        }
        if(ui->comboBox_ordenacao->currentIndex()==6){
        jhone::OrdenarDepartamentoTipoContratoNome objetoDepartamento_TipoDeContrato_Nome;
        std::vector<jhone::Professor> dadosDepartamento_TipoDeContrato_Nome = objetoDepartamento_TipoDeContrato_Nome.arraySelectionSort();
        imprimirNaGrid(dadosDepartamento_TipoDeContrato_Nome);
        }
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }

}


void MainWindow::on_pushButtonBuscar_clicked()
{
    try {
        if(ui->comboBox_busca->currentIndex()==0){
            if(ui->lineEditDado->text().isEmpty()) throw QString ("É necessário algum dado para a busca.");
            std::vector<jhone::Professor> dadosNome;
            jhone::BuscarNome objetoBuscaSequencialNome(LeitorObjeto.getArray());
            dadosNome.push_back(objetoBuscaSequencialNome.buscaSequencialMelhorada(ui->lineEditDado->text()));
            imprimirNaGrid(dadosNome);
        }
        if(ui->comboBox_busca->currentIndex()==1){
            if(ui->lineEditDado->text().isEmpty()) throw QString ("É necessário algum dado para a busca.");
            std::vector<jhone::Professor> dadosMatricula;
            jhone::BuscarMatricula objetoBuscaSequencialMatricula(LeitorObjeto.getArray());
            dadosMatricula.push_back(objetoBuscaSequencialMatricula.buscaSequencialMelhorada(ui->lineEditDado->text()));
            imprimirNaGrid(dadosMatricula);
        }
        if(ui->comboBox_busca->currentIndex()==2){
            if(ui->lineEditDado->text().isEmpty()) throw QString ("É necessário algum dado para a busca.");
            std::vector<jhone::Professor> dadosNome;
            jhone::BuscarNome objetoBuscaBinariaNome(LeitorObjeto.getArray());
            dadosNome.push_back(objetoBuscaBinariaNome.buscaBinaria(ui->lineEditDado->text()));
            imprimirNaGrid(dadosNome);
        }
        if(ui->comboBox_busca->currentIndex()==3){
            if(ui->lineEditDado->text().isEmpty()) throw QString ("É necessário algum dado para a busca.");
            std::vector<jhone::Professor> dadosMatricula;
            jhone::BuscarMatricula objetoBuscaBinariaMatricula(LeitorObjeto.getArray());
            dadosMatricula.push_back(objetoBuscaBinariaMatricula.buscaBinaria(ui->lineEditDado->text()));
            imprimirNaGrid(dadosMatricula);
        }
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }

}

