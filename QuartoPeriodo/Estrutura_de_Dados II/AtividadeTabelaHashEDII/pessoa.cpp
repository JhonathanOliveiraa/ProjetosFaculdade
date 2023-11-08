#include "pessoa.h"

Pessoa::Pessoa():
    matricula(0),
    nome("")
{

}

void Pessoa::setMatricula(int newMatricula)
{
    matricula = newMatricula;
}

void Pessoa::setNome(const QString &newNome)
{
    nome = newNome;
}

int Pessoa::getMatricula() const
{
    return matricula;
}

const QString &Pessoa::getNome() const
{
    return nome;
}

