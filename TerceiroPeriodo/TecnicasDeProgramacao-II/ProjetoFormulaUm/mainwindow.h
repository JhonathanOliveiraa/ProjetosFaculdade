#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
//Biblioteca de manipulação de arquivos
#include <QFileDialog>
#include <piloto.h>
#include <manipulararquivos.h>
#include <QTableWidgetItem>
#include <QTableWidget>
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
    void on_pushButtonBuscar_clicked();

    void on_pushButtonCalcular_clicked();

private:
    Ui::MainWindow *ui;
    QString nomeDoArquivoNoDisco;
};
#endif // MAINWINDOW_H
