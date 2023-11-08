#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <tratamentoarquivos.h>
#include <pessoa.h>
#include <QMessageBox>
#include <QMainWindow>
#include <QStringList>

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
    void on_pushButtonGerar_clicked();
    void mostrarNaGrid();
    void on_pushButtonConsultar_clicked();

    void on_pushButtonAlterar_clicked();

    void on_pushButtonExcluir_clicked();

    void on_pushButtonInserir_clicked();

private:
    Ui::MainWindow *ui;
    TratamentoArquivos arquivo;
};
#endif // MAINWINDOW_H
