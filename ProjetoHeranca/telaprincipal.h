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

private:
    Ui::TelaPrincipal *ui;
};
#endif // TELAPRINCIPAL_H
