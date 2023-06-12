#include "contapoupanca.h"
namespace jhone{
ContaPoupanca::ContaPoupanca():
    ContaGeral()
{
}
ContaPoupanca::ContaPoupanca(int numeroDaConta, QString usuario, float valorNaConta,float valorDepositado):
    ContaGeral(numeroDaConta, usuario, valorNaConta, valorDepositado)
{
}
float ContaPoupanca::depositarDinheiro(){
    return valorNaConta = valorDepositado + valorNaConta;
}
float ContaPoupanca::sacarDinheiro(){
    return valorNaConta = valorDepositado - valorNaConta;
}
float ContaPoupanca::emitirSaldo()const{
    return valorNaConta;
}
}
