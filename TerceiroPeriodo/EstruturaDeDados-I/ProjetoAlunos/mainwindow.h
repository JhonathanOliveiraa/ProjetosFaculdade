#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <list>
#include <iterator>
#include <fstream>
#include <QFileDialog>
#include <QMessageBox>
#include <QComboBox>
#include <QLabel>
#include <QInputDialog>

#include "aluno.h"
#include "filtrar.h"

enum {
    LISTAR_POR_CURSO,
    LISTAR_POR_DISCIPLINA,
    LISTAR_POR_TURMA,
    MOSTRAR_DISCIPLINAS_ALUNO,
};
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

    void on_pushButtonOrganizar_clicked();

private:
    Ui::MainWindow *ui;
    std::list<Aluno*>listaAlunos;

    QString saida = "";

};
#endif // MAINWINDOW_H
