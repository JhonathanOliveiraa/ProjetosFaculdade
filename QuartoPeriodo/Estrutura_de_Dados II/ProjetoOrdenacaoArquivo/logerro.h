#ifndef LOGERRO_H
#define LOGERRO_H
#include <tratamentodearquivos.h>
#include <QDialog>

namespace Ui {
class logErro;
}

class logErro : public QDialog
{
    Q_OBJECT

public:
    explicit logErro(QWidget *parent = nullptr);
    ~logErro();

private:
    Ui::logErro *ui;
    jhone::TratamentoDeArquivos *Leitor;
};

#endif // LOGERRO_H
