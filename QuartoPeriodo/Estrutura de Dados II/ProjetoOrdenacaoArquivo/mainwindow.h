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
#include <templateordenacao.h>
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
    void imprimirNaGrid(std::vector<Professor> dados);
    void on_pushButtonOrdenar_clicked();

private:
    Ui::MainWindow *ui;
    TratamentoDeArquivos LeitorObjeto;
    std::vector<Professor> p;
};
#endif // MAINWINDOW_H
