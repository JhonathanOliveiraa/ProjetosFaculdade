#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    try {
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
void MainWindow::imprimirNaGrid(std::vector<Professor> dados){
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
        if(ui->comboBox_ordenacao->currentIndex()==0){
        OrdenarMatricula objetoMatricula;
        std::vector<Professor> dadosMatricula = objetoMatricula.arraySelectionSort();
        imprimirNaGrid(dadosMatricula);
        }
        if(ui->comboBox_ordenacao->currentIndex()==1){
        OrdenarNome objetoNome;
        std::vector<Professor> dadosNome = objetoNome.arraySelectionSort();
        imprimirNaGrid(dadosNome);
        }
        if(ui->comboBox_ordenacao->currentIndex()==2){
        OrdenarDepartamento objetoDepartamentoNome;
        std::vector<Professor> dadosDepartamento = objetoDepartamentoNome.arraySelectionSort();
        imprimirNaGrid(dadosDepartamento);
        }

        if(ui->comboBox_ordenacao->currentIndex()==3){
        OrdenarTitulacao objetoTitulacaoNome;
        std::vector<Professor> dadosTitulacao_Nome = objetoTitulacaoNome.arraySelectionSort();
        imprimirNaGrid(dadosTitulacao_Nome);
        }
        if(ui->comboBox_ordenacao->currentIndex()==4){
        OrdenarTipoDeContrato objetoTipoDeContratoNome;
        std::vector<Professor> dadosTipoDeContrato_Nome = objetoTipoDeContratoNome.arraySelectionSort();
        imprimirNaGrid(dadosTipoDeContrato_Nome);
        }
        if(ui->comboBox_ordenacao->currentIndex()==5){
        OrdenarDepartamento objetoDepartamento_Titulacao_Nome;
        std::vector<Professor> dadosDepartamento_Titulacao_Nome = objetoDepartamento_Titulacao_Nome.arraySelectionSort();
        imprimirNaGrid(dadosDepartamento_Titulacao_Nome);
        }
        if(ui->comboBox_ordenacao->currentIndex()==6){
        OrdenarDepartamento objetoDepartamento_TipoDeContrato_Nome;
        std::vector<Professor> dadosDepartamento_TipoDeContrato_Nome = objetoDepartamento_TipoDeContrato_Nome.arraySelectionSort();
        imprimirNaGrid(dadosDepartamento_TipoDeContrato_Nome);
        }
}

