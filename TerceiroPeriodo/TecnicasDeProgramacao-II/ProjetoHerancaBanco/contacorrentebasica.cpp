#include "contacorrentebasica.h"
namespace jhone{
ContaCorrenteBasica::ContaCorrenteBasica():
    ContaGeral(),
    tarifaBancaria()
{
}
ContaCorrenteBasica::ContaCorrenteBasica(float tarifaBancaria,int numeroDaConta, QString usuario, float valorNaConta, float valorDepositado):
    ContaGeral(numeroDaConta,usuario,valorNaConta,valorDepositado),
    tarifaBancaria(0)
{
    if(tarifaBancaria<0) throw QString ("Tarifa Bancária inválida");
}
float ContaCorrenteBasica::getTarifaBancaria() const
{
    return tarifaBancaria;
}

void ContaCorrenteBasica::setTarifaBancaria(float newTarifaBancaria)
{
    tarifaBancaria = newTarifaBancaria;
}
float ContaCorrenteBasica::depositarDinheiro() {
    return valorNaConta = valorNaConta + valorDepositado;
}
float ContaCorrenteBasica::sacarDinheiro() {
    return valorNaConta = valorNaConta - valorDepositado;
}
float ContaCorrenteBasica::emitirSaldo()const {
    return valorNaConta;
}
}
