#ifndef LLSE_H
#define LLSE_H
#include <no.h>
#include <QString>
namespace Jhone{
class LLSE // Lista linear simplesmente encadeada
{
private:
    int quantidadeElementos;
    No* inicio;

public:
    LLSE();
    bool estaVazia()const;
    void inserirInicio(int elemento);
    int retirarInicio();
    int getQuantidadeElementos() const;
    int acessarInicio();
    QString obterDadosLLSE()const;
    int acessarFinal()const;
    int retirarFinal();
    void inserirFinal(int elemento);
};
}
#endif // LLSE_H
