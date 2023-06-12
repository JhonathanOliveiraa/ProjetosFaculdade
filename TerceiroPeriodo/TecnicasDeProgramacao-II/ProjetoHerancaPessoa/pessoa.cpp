#include "pessoa.h"

namespace gft{

Pessoa::Pessoa():
    nome(),
    endereco(),
    telefone(0),
    email(),
    rendaBruta(0)
{

}

Pessoa::Pessoa(QString nome, QString endereco, int telefone, QString email, float rendaBruta):
    nome(nome),
    endereco(endereco),
    telefone(0),
    email(email),
    rendaBruta(0)
{
    if(telefone <= 0) throw QString ("Numero de telefone invalido");
    this->telefone = telefone;
    if(rendaBruta < 0) throw QString ("Renda Bruta invalida");
    this->rendaBruta = rendaBruta;
}

QString Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setNome(const QString &newNome)
{
    nome = newNome;
}

QString Pessoa::getEndereco() const
{
    return endereco;
}

void Pessoa::setEndereco(const QString &newEndereco)
{
    endereco = newEndereco;
}

int Pessoa::getTelefone() const
{
    return telefone;
}

void Pessoa::setTelefone(int newTelefone)
{
    telefone = newTelefone;
}

QString Pessoa::getEmail() const
{
    return email;
}

void Pessoa::setEmail(const QString &newEmail)
{
    email = newEmail;
}

float Pessoa::getRendaBruta() const
{
    return rendaBruta;
}

void Pessoa::setRendaBruta(float newRendaBruta)
{
    rendaBruta = newRendaBruta;
}


}
