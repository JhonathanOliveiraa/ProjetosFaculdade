#ifndef TRATAMENTODEARQUIVOS_H
#define TRATAMENTODEARQUIVOS_H
#include <fstream>
#include <QString>
#include <professor.h>
#include <QList>
#include <vector>
class TratamentoDeArquivos
{
private:
    QString nomeDoArquivo;
    QString logErro;
    std::vector<Professor> array;
public:
    TratamentoDeArquivos();
    void buscarArquivos();
    std::vector<Professor> getArray() const;
};

#endif // TRATAMENTODEARQUIVOS_H
