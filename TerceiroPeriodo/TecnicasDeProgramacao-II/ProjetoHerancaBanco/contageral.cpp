#include "contageral.h"
namespace jhone{

ContaGeral::ContaGeral():
    numeroDaConta(),
    valorNaConta(),
    valorDepositado(),
    usuario()
{
}
ContaGeral::ContaGeral(int numeroDaConta, QString usuario, float valorNaConta, float valorDepositado):
    numeroDaConta(0),
    valorNaConta(0),
    valorDepositado(0),
    usuario(usuario)
{
    if (numeroDaConta<0) throw QString ("O número da conta é inválido");
    if (valorNaConta<0) throw QString ("O valor na conta não pode ser negativo");
    if (valorDepositado<0) throw QString ("O valor na conta não pode ser negativo");
}
int ContaGeral::getNumeroDaConta() const
{
    return numeroDaConta;
}

void ContaGeral::setNumeroDaConta(int newNumeroDaConta)
{
    numeroDaConta = newNumeroDaConta;
}

QString ContaGeral::getUsuario() const
{
    return usuario;
}

void ContaGeral::setUsuario(const QString &newUsuario)
{
    usuario = newUsuario;
}
float ContaGeral::getValorDepositado() const
{
    return valorDepositado;
}

void ContaGeral::setValorDepositado(float newValorDepositado)
{
    valorDepositado = newValorDepositado;
}

}
