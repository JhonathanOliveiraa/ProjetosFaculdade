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


void MainWindow::on_button_nCubos_It_clicked()
{
    QString saida = "";
    int n = ui->lineEdit_numMax->text().toInt();
    if(n < 1) throw QMessageBox::information(this,"ERRO","Quantidade de elementos invalido, digite um numero maior do que 0");

    saida = aux.primeirosCubosIterativo(n);
    ui->textEditSaida->setText(saida);
    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();
}


void MainWindow::on_button_DecrecenteIterativo_clicked()
{
    QString saida = "";
    int n = ui->lineEdit_numMax->text().toInt();
    if(n < 1) throw QMessageBox::information(this,"ERRO","Quantidade de elementos invalido, digite um numero maior do que 0");

    saida = aux.numNaturaisDecrecenteIterativo(n);
    ui->textEditSaida->setText(saida);
    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();
}


void MainWindow::on_button_MenorVetor_clicked()
{
    QString saida = "";
    int n = ui->lineEdit_numMax->text().toInt();
    if(n < 1) throw QMessageBox::information(this,"ERRO","Quantidade de elementos invalido, digite um numero maior do que 0");

    saida = QString::number(aux.menorElementoVetorIterativo(n));
    ui->textEditSaida->setText(saida);
    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();
}


void MainWindow::on_button_nCubos_R_clicked()
{
    QString saida = "";
    int n = ui->lineEdit_numMax->text().toInt();
    if(n < 1) throw QMessageBox::information(this,"ERRO","Quantidade de elementos invalido, digite um numero maior do que 0");
    saida = QString::number(aux.primeirosCubosRecursivo(1, 0, n));
    ui->textEditSaida->setText(saida);
    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();
}

void MainWindow::on_button_DecrecenteRecurs_clicked()
{
    QString saida = "";
    int n = ui->lineEdit_numMax->text().toInt();
    if(n < 1) throw QMessageBox::information(this,"ERRO","Quantidade de elementos invalido, digite um numero maior do que 0");
    saida = aux.numNaturaisDecrescenteRecursivo(n, "");
    ui->textEditSaida->setText(saida);
    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();


}


void MainWindow::on_button_MenorVetorRecurs_clicked()
{
    int tamanho = ui->lineEdit_numMax->text().toInt();
    int vetor[tamanho];
    QString saida = "";
    {
    // Semente para geração de números aleatórios
    std::srand(std::time(nullptr));

    saida += "Vetor gerado{ ";
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = std::rand() % 101; // Gera um número aleatório entre 0 e 100
        saida += QString::number(vetor[i]) + " ";

    }
    saida += "}";
    saida += "\n";
    int x = vetor[0];

    int n = ui->lineEdit_numMax->text().toInt();
    if(n < 1) throw QMessageBox::information(this,"ERRO","Quantidade de elementos invalido, digite um numero maior do que 0");
    saida += QString::number(aux.menorElementoVetorRecursivo(n, vetor, 0, x));
    ui->textEditSaida->setText(saida);
    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();

}

}


void MainWindow::on_button_Conver_BI_It_clicked()
{
    int n = ui->lineEdit_numMax->text().toInt();
    if(n<=1)
    {
        QMessageBox::information(this,"","APENAS VALORES POSITIVOS PERMITIDOS");
        return;
        ui->lineEdit_numMax->clear();
        ui->lineEdit_numMax->setFocus();
    }
    QString saida = aux.imprimeNumeroBinarioIterativo(n, 0, 1, "");
    ui->textEditSaida->setText(saida);
    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();
}


void MainWindow::on_button_Conver_BI_RE_clicked()
{
    int n = ui->lineEdit_numMax->text().toInt();
    if(n<=1)
    {
        QMessageBox::information(this,"","APENAS VALORES POSITIVOS PERMITIDOS");
        return;
        ui->lineEdit_numMax->clear();
        ui->lineEdit_numMax->setFocus();
    }
    QString saida = aux.converterParaBinarioRecursivo(n, 0, 1, "");
    ui->textEditSaida->setText(saida);
    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();
}


void MainWindow::on_ButtonX_a_Y_It_clicked()
{
    QString saida = "Digite o Valor de X(Base):";
    ui->textEditSaida->setText(saida);

    QEventLoop loop;
    connect(ui->lineEdit_numMax, &QLineEdit::returnPressed, &loop, &QEventLoop::quit);
    loop.exec();

    int n1 = ui->lineEdit_numMax->text().toInt();

    if(n1<=1)
    {
        QMessageBox::information(this,"","APENAS VALORES POSITIVOS PERMITIDOS");
        ui->lineEdit_numMax->clear();
        ui->lineEdit_numMax->setFocus();
        return;
    }

    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();

    saida = "Digite o Valor de Y(Expoente):";
    ui->textEditSaida->setText(saida);

    connect(ui->lineEdit_numMax, &QLineEdit::returnPressed, &loop, &QEventLoop::quit);
    loop.exec();

    int n2 = ui->lineEdit_numMax->text().toInt();

    if(n2<=1)
    {
        QMessageBox::information(this,"","APENAS VALORES POSITIVOS PERMITIDOS");
        ui->lineEdit_numMax->clear();
        ui->lineEdit_numMax->setFocus();
        return;
    }

    QString saidaFinal = aux.imprimePotenciacaoIterativo(n1, n2, n1, "");

    ui->textEditSaida->setText(saidaFinal);

    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();
}


void MainWindow::on_Button_X_a_Y_RE_clicked()
{
    QString saida = "Digite o Valor de X(Base):";
    ui->textEditSaida->setText(saida);

    QEventLoop loop;
    connect(ui->lineEdit_numMax, &QLineEdit::returnPressed, &loop, &QEventLoop::quit);
    loop.exec();

    int n1 = ui->lineEdit_numMax->text().toInt();

    if(n1<=1)
    {
        QMessageBox::information(this,"","APENAS VALORES POSITIVOS PERMITIDOS");
        ui->lineEdit_numMax->clear();
        ui->lineEdit_numMax->setFocus();
        return;
    }

    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();

    saida = "Digite o Valor de Y(Expoente):";
    ui->textEditSaida->setText(saida);

    connect(ui->lineEdit_numMax, &QLineEdit::returnPressed, &loop, &QEventLoop::quit);
    loop.exec();

    int n2 = ui->lineEdit_numMax->text().toInt();

    if(n2<=1)
    {
        QMessageBox::information(this,"","APENAS VALORES POSITIVOS PERMITIDOS");
        ui->lineEdit_numMax->clear();
        ui->lineEdit_numMax->setFocus();
        return;
    }

    QString saidaFinal = aux.imprimePotenciacaoRecursivo(n1, n2, n1, 1, "");

    ui->textEditSaida->setText(saidaFinal);

    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();
}


void MainWindow::on_button_N1N2_It_clicked()
{
    QString saida = "Digite o Valor de N1:";
    ui->textEditSaida->setText(saida);

    QEventLoop loop;
    connect(ui->lineEdit_numMax, &QLineEdit::returnPressed, &loop, &QEventLoop::quit);
    loop.exec();

    int n1 = ui->lineEdit_numMax->text().toInt();

    if(n1<=1)
    {
        QMessageBox::information(this,"","APENAS VALORES POSITIVOS PERMITIDOS");
        ui->lineEdit_numMax->clear();
        ui->lineEdit_numMax->setFocus();
        return;
    }

    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();

    saida = "Digite o Valor de Y(Expoente)";
    ui->textEditSaida->setText(saida);

    connect(ui->lineEdit_numMax, &QLineEdit::returnPressed, &loop, &QEventLoop::quit);
    loop.exec();

    int n2 = ui->lineEdit_numMax->text().toInt();

    if(n2<=1)
    {
        QMessageBox::information(this,"","APENAS VALORES POSITIVOS PERMITIDOS");
        ui->lineEdit_numMax->clear();
        ui->lineEdit_numMax->setFocus();
        return;
    }

    QString saidaFinal = aux.imprimeProdutoIterativo(n1, n2, 0, "");

    ui->textEditSaida->setText(saidaFinal);

    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();
}


void MainWindow::on_button_N1N2_RE_clicked()
{
    QString saida = "Digite o Valor de N1:";
    ui->textEditSaida->setText(saida);

    QEventLoop loop;
    connect(ui->lineEdit_numMax, &QLineEdit::returnPressed, &loop, &QEventLoop::quit);
    loop.exec();

    int n1 = ui->lineEdit_numMax->text().toInt();

    if(n1<=1)
    {
        QMessageBox::information(this,"","APENAS VALORES POSITIVOS PERMITIDOS");
        ui->lineEdit_numMax->clear();
        ui->lineEdit_numMax->setFocus();
        return;
    }

    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();

    saida = "Digite o Valor de Y(Expoente)";
    ui->textEditSaida->setText(saida);

    connect(ui->lineEdit_numMax, &QLineEdit::returnPressed, &loop, &QEventLoop::quit);
    loop.exec();

    int n2 = ui->lineEdit_numMax->text().toInt();

    if(n2<=1)
    {
        QMessageBox::information(this,"","APENAS VALORES POSITIVOS PERMITIDOS");
        ui->lineEdit_numMax->clear();
        ui->lineEdit_numMax->setFocus();
        return;
    }

    QString saidaFinal = aux.imprimeProdutoRecursivo(n1, n2, 0, 1, "");

    ui->textEditSaida->setText(saidaFinal);

    ui->lineEdit_numMax->clear();
    ui->lineEdit_numMax->setFocus();
}

