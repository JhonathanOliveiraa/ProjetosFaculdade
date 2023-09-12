#include "professor.h"


Professor::Professor()
{

}
void Professor::setNome(const QString &newNome)
{
    nome = newNome;
}

void Professor::setMatricula(const QString &newMatricula)
{
    matricula = newMatricula;
}

void Professor::setDepartamento(const QString &newDepartamento)
{
    departamento = newDepartamento;
}

void Professor::setTitulacao(const QString &newTitulacao)
{
    titulacao = newTitulacao;
}

void Professor::setTipoDeContrato(const QString &newTipoDeContrato)
{
    tipoDeContrato = newTipoDeContrato;
}

const QString &Professor::getNome() const
{
    return nome;
}

const QString &Professor::getMatricula() const
{
    return matricula;
}

const QString &Professor::getDepartamento() const
{
    return departamento;
}

const QString &Professor::getTitulacao() const
{
    return titulacao;
}

const QString &Professor::getTipoDeContrato() const
{
    return tipoDeContrato;
}
