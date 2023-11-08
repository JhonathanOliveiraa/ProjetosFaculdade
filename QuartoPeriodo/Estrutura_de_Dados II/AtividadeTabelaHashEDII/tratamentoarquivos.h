#ifndef TRATAMENTOARQUIVOS_H
#define TRATAMENTOARQUIVOS_H
#include <QString>
#include <pessoa.h>
#include <fstream>
#include <QStringList>

class TratamentoArquivos
{
private:
    QString nomeDoArquivo;
    Pessoa array[1000];
public:
    TratamentoArquivos();
    Pessoa* getVetor();
    void buscarArquivo();
    Pessoa consultar(int matricula);
    void alterar(int matricula, QString nome);
    void excluir(int matricula);
    void inserir(int matricula, QString nome);
};

#endif // TRATAMENTOARQUIVOS_H
