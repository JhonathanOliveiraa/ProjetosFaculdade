#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <exercicios.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    gft::Exercicios aux;

private slots:

    void on_button_nCubos_It_clicked();

    void on_button_DecrecenteIterativo_clicked();

    void on_button_MenorVetor_clicked();

    void on_button_nCubos_R_clicked();

    void on_button_DecrecenteRecurs_clicked();

    void on_button_MenorVetorRecurs_clicked();

    void on_button_Conver_BI_It_clicked();

    void on_button_Conver_BI_RE_clicked();

    void on_ButtonX_a_Y_It_clicked();

    void on_Button_X_a_Y_RE_clicked();

    void on_button_N1N2_It_clicked();

    void on_button_N1N2_RE_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
