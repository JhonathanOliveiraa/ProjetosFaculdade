#ifndef CONTACORRENTELIMITE_H
#define CONTACORRENTELIMITE_H
#include <contageral.h>
#include <icontageral.h>
#include <QString>
namespace jhone{

class ContaCorrenteLimite : public ContaGeral, public IContaGeral
{
private:
    float tarifaBancaria;
public:
    ContaCorrenteLimite();
    ContaCorrenteLimite(float tarifaBancaria, int numeroDaConta, QString usuario, float valorNaConta, float valorDepositado);
    float depositarDinheiro() ;
    float sacarDinheiro() ;
    float emitirSaldo() const;
};
}
#endif // CONTACORRENTELIMITE_H
