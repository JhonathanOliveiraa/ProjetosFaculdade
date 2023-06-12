#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H

#include "ipessoa.h"
#include "pessoa.h"

namespace gft{
class PessoaJuridica: public Pessoa, public IPessoa
{
private:
    QString CNPJ;
    QString razaoSocial;
public:
    PessoaJuridica();
    PessoaJuridica(QString CNPJ, QString razaoSocial,QString nome, QString endereco,
                   int telefone, QString email, float rendaBruta);
    float calcularImpostoDeRenda();
    QString getCNPJ() const;
    void setCNPJ(const QString &newCNPJ);
    QString getRazaoSocial() const;
    void setRazaoSocial(const QString &newRazaoSocial);
};

}

#endif // PESSOAJURIDICA_H
