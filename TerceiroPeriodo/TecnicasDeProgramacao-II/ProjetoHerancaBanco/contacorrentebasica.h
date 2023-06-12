#ifndef CONTACORRENTEBASICA_H
#define CONTACORRENTEBASICA_H
#include <contageral.h>
#include <icontageral.h>
#include <QString>
namespace jhone{
class ContaCorrenteBasica : public ContaGeral, public IContaGeral
{
protected:
    float tarifaBancaria;
public:
    ContaCorrenteBasica();
    ContaCorrenteBasica(float tarifaBancaria, int numeroDaConta, QString usuario, float valorNaConta, float valorDepositado);
    float getTarifaBancaria() const;
    void setTarifaBancaria(float newTarifaBancaria);
    float depositarDinheiro() ;
    float sacarDinheiro() ;
    float emitirSaldo() const;
};
}
#endif // CONTACORRENTEBASICA_H
