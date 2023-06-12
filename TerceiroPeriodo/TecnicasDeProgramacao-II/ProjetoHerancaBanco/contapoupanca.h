#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H
#include <contageral.h>
#include <icontageral.h>
namespace jhone{
class ContaPoupanca : public ContaGeral, public IContaGeral
{
private:
public:
    ContaPoupanca();
    ContaPoupanca(int numeroDaConta, QString usuario, float valorNaConta,float valorDepositado);
    float depositarDinheiro();
    float sacarDinheiro();
    float emitirSaldo()const;
};
}
#endif // CONTAPOUPANCA_H
