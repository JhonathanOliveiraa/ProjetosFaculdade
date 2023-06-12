#include "contacorrentelimite.h"
namespace jhone{
ContaCorrenteLimite::ContaCorrenteLimite():
    ContaGeral(),
    tarifaBancaria()
{
}
ContaCorrenteLimite::ContaCorrenteLimite(float tarifaBancaria,int numeroDaConta, QString usuario, float valorNaConta, float valorDepositado):
    ContaGeral(numeroDaConta,usuario,valorNaConta,valorDepositado),
    tarifaBancaria(0)
{
    if(tarifaBancaria<0) throw QString ("Tarifa bancária inválida");
}
float ContaCorrenteLimite::depositarDinheiro() {
    return valorNaConta = valorNaConta + valorDepositado;
}
float ContaCorrenteLimite::sacarDinheiro() {
    return valorNaConta = valorNaConta - valorDepositado;
}
float ContaCorrenteLimite::emitirSaldo()const {
    return valorNaConta;
}
}
