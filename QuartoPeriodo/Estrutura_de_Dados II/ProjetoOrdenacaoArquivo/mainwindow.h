#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <tratamentodearquivos.h>
#include <QMessageBox>
#include <ordenarnome.h>
#include <ordenarmatricula.h>
#include <ordenardepartamento.h>
#include <ordenartipodecontrato.h>
#include <ordenartitulacao.h>
#include <ordenardepartamentotipocontratonome.h>
#include <templateordenacao.h>
#include <templatebusca.h>
#include <buscarmatricula.h>
#include <ordenardepartamentonome.h>
#include <buscarnome.h>
#include <logerro.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void imprimirNaGrid(std::vector<jhone::Professor> dados);

    void on_pushButtonOrdenar_clicked();

    void on_pushButtonBuscar_clicked();

    void on_pushButtonLogErro_clicked();

private:
    Ui::MainWindow *ui;
    logErro *formularioLogErro;
    jhone::TratamentoDeArquivos LeitorObjeto;
    std::vector<jhone::Professor> objProf;
};
#endif // MAINWINDOW_H
