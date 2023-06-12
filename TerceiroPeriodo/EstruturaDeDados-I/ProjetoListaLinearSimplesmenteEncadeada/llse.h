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
    void inserirPosicao(int elemento,int posicao);
    void inserirFinal(int elemento);
    void inserirOrdenado(int elemento);
    int acessarInicio();
    int acessarPosicao(int posicao);
    int acessarFinal()const;
    int retirarInicio();
    int retirarPosicao(int posicao);
    int retirarFinal();
    int getQuantidadeElementos() const;
    QString obterDadosLLSE()const;
};
}
#endif // LLSE_H
