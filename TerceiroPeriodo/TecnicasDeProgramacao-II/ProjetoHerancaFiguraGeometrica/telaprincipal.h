#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include <esfera.h>
#include <cilindro.h>
#include <cone.h>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QPixmap>
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
    void on_pushButtonCalcular_clicked();

    void on_comboBoxTipoFigura_currentIndexChanged(int index);

private:
    Ui::TelaPrincipal *ui;
    int aux;
};
#endif // TELAPRINCIPAL_H
