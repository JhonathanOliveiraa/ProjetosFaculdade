#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H

#include <pessoa.h>
#include <ipessoa.h>

namespace gft{
class PessoaFisica: public Pessoa, public IPessoa
{
private:
    QString CPF;
    QString sexo;
public:
    PessoaFisica();
    PessoaFisica(QString CPF, QString sexo,QString nome, QString endereco,
                 int telefone, QString email, float rendaBruta);

    void extracted(float &imposto);
    float calcularImpostoDeRenda();
    QString getCPF() const;
    void setCPF(const QString &newCPF);
    QString getSexo() const;
    void setSexo(const QString &newSexo);
};

}
#endif // PESSOAFISICA_H
