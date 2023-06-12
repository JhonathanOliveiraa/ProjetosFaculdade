#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H
#include <no.h>
#include <llde.h>
#include <QRegularExpressionValidator>
#include <QMessageBox>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TelaPrincipal; }
QT_END_NAMESPACE

class TelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    TelaPrincipal(QWidget *parent = nullptr);
    ~TelaPrincipal();

private slots:

    void on_pushButtonInserirInicio_clicked();

    void on_pushButtonRetirarInicio_clicked();

    void on_pushButtonAcessarInicio_clicked();

    void on_pushButtonInserirFinal_clicked();

    void on_pushButtonAcessarFinal_clicked();

    void on_pushButtonRetirarFinal_clicked();

    void on_pushButtonAcessarPosicao_clicked();

    void on_pushButtonInserirPosicao_clicked();

    void on_pushButtonRetirarPosicao_clicked();

    void on_pushButtonInserirOrdenado_clicked();

private:
    Ui::TelaPrincipal *ui;
    QRegularExpressionValidator *validator;
};
#endif // TELAPRINCIPAL_H
