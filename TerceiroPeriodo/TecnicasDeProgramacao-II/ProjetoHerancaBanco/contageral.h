#ifndef CONTAGERAL_H
#define CONTAGERAL_H
#include <QString>
#include <icontageral.h>
namespace jhone{
class ContaGeral
{
protected:
    int numeroDaConta;
    float valorNaConta;
    float valorDepositado;
    QString usuario;    
public:
    ContaGeral();
    ContaGeral(int numeroDaConta, QString usuario, float valorNaConta, float valorDepositado);
    int getNumeroDaConta() const;
    void setNumeroDaConta(int newNumeroDaConta);
    QString getUsuario() const;
    void setUsuario(const QString &newUsuario);
    float getValorDepositado() const;
    void setValorDepositado(float newValorDepositado);
};
}
#endif // CONTAGERAL_H
