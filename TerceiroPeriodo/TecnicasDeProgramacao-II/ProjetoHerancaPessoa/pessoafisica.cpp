#include "pessoafisica.h"

namespace gft{

PessoaFisica::PessoaFisica():
    CPF(),
    sexo()
{

}
PessoaFisica::PessoaFisica(QString CPF, QString sexo,QString nome, QString endereco,int telefone, QString email, float rendaBruta):
    Pessoa(nome, endereco, telefone, email, rendaBruta),
    CPF(CPF),
    sexo(sexo)
{
}

float PessoaFisica::calcularImpostoDeRenda(){
    if(rendaBruta < 0)
        throw QString ("Renda Invalida - calcularImpostoDeRenda");
    if(rendaBruta <= 1400)
        throw QString ("Isento de impostos");
    if(rendaBruta > 1400 && rendaBruta <= 2100){
        return (rendaBruta*10)/100;
    }
    if(rendaBruta > 2100 && rendaBruta <= 2800){
        return (rendaBruta*15)/100;
    }
    if(rendaBruta > 2800 && rendaBruta <= 3600){
        return (rendaBruta*25)/100;
    }
    if(rendaBruta > 3600){
        return (rendaBruta*30)/100;
    }

}

QString PessoaFisica::getCPF() const
{
    return CPF;
}

void PessoaFisica::setCPF(const QString &newCPF)
{
    CPF = newCPF;
}

QString PessoaFisica::getSexo() const
{
    return sexo;
}

void PessoaFisica::setSexo(const QString &newSexo)
{
    sexo = newSexo;
}


}
