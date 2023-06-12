#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <no.h>
#include "llse.h"
#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QRegularExpressionValidator>

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
    void on_pushButtonIncluirInicio_clicked();

    void on_pushButtonRetirarInicio_clicked();

    void on_pushButtonAcessarInicio_clicked();

    void on_pushButtonIncluirFinal_clicked();

    void on_pushButtonAcessarFinal_clicked();

    void on_pushButtonRetirarFinal_clicked();

    void on_pushButtonAcessarPosicao_clicked();

    void on_pushButtonInserirPosicao_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QRegularExpressionValidator *validator;
};
#endif // MAINWINDOW_H
