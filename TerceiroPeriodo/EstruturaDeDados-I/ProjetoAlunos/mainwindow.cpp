#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonBuscar_clicked()
{
    QString enderecoArquivo = QFileDialog::getOpenFileName(this,"Selecione o arquivo", QDir::homePath(), "Todos os arquivos(*.*)");
    ui->lineEdit->setText(enderecoArquivo);
    std::fstream arquivoRead;
    std::string linha;
    arquivoRead.open(enderecoArquivo.toStdString().c_str());
    if(arquivoRead.is_open())
    {
        Aluno* objetoAluno;
        while(std::getline(arquivoRead,linha))
        {
            QString linhaQt=QString::fromStdString(linha);
            try
            {
                objetoAluno = new Aluno(linhaQt);
            }
            catch(QString &erro)
            {
                QMessageBox::critical(this,"ERRO", erro);
            }
            listaAlunos.push_back(objetoAluno);
        }
    }
    else
    {
        QMessageBox::critical(this,"ERRO", "Não foi possível abrir o arquivo.");
    }

}


void MainWindow::on_pushButtonOrganizar_clicked()
{
    int selectedItem = ui->comboBox->currentIndex(); //Verifica valor da comboBox
    QString saida;    //QString contendo todos os dados a serem mostrados

    if(selectedItem == 0)
    {
        int curso = QInputDialog::getInt(this,"Entrada.", "Insira o código do curso desejado.");
        try
        {
            saida = Filtrar::filtrarPorCurso(listaAlunos, curso);
        }
        catch(QString &erro)
        {
            QMessageBox::critical(this,"ERRO NO CURSO.", erro);
        }
        ui->textEdit->setText(saida);
        ui->textEdit_referencia->setText(QString::number(curso));
    }

    if(selectedItem == 1)
    {
        QString disciplina = QInputDialog::getText(
            this,"Entrada.", "Insira o codigo da disciplina desejada.");
        try
        {
            saida = Filtrar::filtrarPorDisciplina(listaAlunos, disciplina);
        }
        catch(QString &erro)
        {
            QMessageBox::critical(this,"ERRO NA DISCIPLINA.", erro);
        }

        ui->textEdit->setText(saida);
        ui->textEdit_referencia->setText(disciplina);
    }
    if(selectedItem == 2)
    {
        QString turma = QInputDialog::getText(
            this,"Entrada.", "Insira o codigo e a turma desejados, por favor.");
        try
        {
            saida = Filtrar::filtrarPorDisciplinaTurma(listaAlunos, turma);
        }
        catch(QString &erro)
        {
            QMessageBox::critical(this,"ERRO NA TURMA.", erro);
        }
        ui->textEdit->setText(saida);
        ui->textEdit_referencia->setText(turma);
    }
    if(selectedItem == 3)
    {
        QString matricula = QInputDialog::getText(
            this,"Entrada.", "Insira a matrícula do aluno desejado, por favor.");
        try
        {
            saida = Filtrar::filtrarAluno(listaAlunos, matricula);
        }
        catch(QString &erro)
        {
            QString erro2 = "Certifique-se de digitar corretamente.\nExemplo: 2023.01.123.1234";
            QMessageBox::critical(this,"ERRO", erro + erro2);
        }
        ui->textEdit->setText(saida);
        ui->textEdit_referencia->setText(matricula);

    }
}

