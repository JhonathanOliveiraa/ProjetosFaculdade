#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vetoraleatorio.h>
#include <QRegularExpressionValidator>
#include <QMainWindow>
#include <QMessageBox>

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

    void on_pushButtonBuscar_clicked();

    void on_pushButtonBuscarBinario_clicked();

private:
    Ui::MainWindow *ui;
    jhone::VetorAleatorio *vetor;
};
#endif // MAINWINDOW_H
