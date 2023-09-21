#ifndef TRATAMENTODEARQUIVOS_H
#define TRATAMENTODEARQUIVOS_H
#include <fstream>
#include <QString>
#include <professor.h>
#include <QList>
#include <vector>
#include <iostream>
#include <QTextStream>
namespace jhone {

class TratamentoDeArquivos
{
private:
    QString nomeDoArquivo;
    std::ofstream arquivoErro;
    std::vector<Professor> array;
public:
    TratamentoDeArquivos();
    void buscarArquivos();
    QString obterLogErro();
    std::vector<Professor> getArray() const;
};
}
#endif // TRATAMENTODEARQUIVOS_H
