#include "pessoajuridica.h"

namespace gft{

PessoaJuridica::PessoaJuridica():
    CNPJ(),
    razaoSocial()
{
}

PessoaJuridica::PessoaJuridica(QString CNPJ, QString razaoSocial,QString nome, QString endereco,
                               int telefone, QString email, float rendaBruta):
    Pessoa(nome, endereco, telefone, email, rendaBruta),
    CNPJ(CNPJ),
    razaoSocial(razaoSocial)
{
}

float PessoaJuridica::calcularImpostoDeRenda(){

    return (rendaBruta*20)/100;

}

QString PessoaJuridica::getCNPJ() const
{
    return CNPJ;
}

void PessoaJuridica::setCNPJ(const QString &newCNPJ)
{
    CNPJ = newCNPJ;
}

QString PessoaJuridica::getRazaoSocial() const
{
    return razaoSocial;
}

void PessoaJuridica::setRazaoSocial(const QString &newRazaoSocial)
{
    razaoSocial = newRazaoSocial;
}


}
