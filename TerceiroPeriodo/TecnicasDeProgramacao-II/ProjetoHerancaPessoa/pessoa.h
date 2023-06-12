#ifndef PESSOA_H
#define PESSOA_H

#include <QString>

namespace gft{
class Pessoa
{
protected:
    QString nome;
    QString endereco;
    int telefone;
    QString email;
    float rendaBruta;
public:
    Pessoa();
    Pessoa(QString nome, QString endereco, int telefone, QString email, float rendaBruta);
    QString getNome() const;
    void setNome(const QString &newNome);
    QString getEndereco() const;
    void setEndereco(const QString &newEndereco);
    int getTelefone() const;
    void setTelefone(int newTelefone);
    QString getEmail() const;
    void setEmail(const QString &newEmail);
    float getRendaBruta() const;
    void setRendaBruta(float newRendaBruta);
};

}
#endif // PESSOA_H
