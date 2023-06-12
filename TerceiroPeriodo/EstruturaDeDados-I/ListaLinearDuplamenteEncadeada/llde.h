#ifndef LLDE_H
#define LLDE_H
#include <QString>
#include <no.h>
namespace jhone {

class LLDE
{
private:
    int quantidadeElementos;
    No *inicio;
    No *fim;
public:
    LLDE();
    QString obterLista()const;
    bool estaVazia()const;
    void inserirInicio(int elemento);
    void inserirPosicao(int elemento, int posicao);
    void inserirFinal(int elemento);
    void inserirOrdenado(int elemento);
    int acessarInicio()const;
    int acessarPosicao(int posicao);
    int acessarFinal()const;
    int retirarInicio();
    int retirarPosicao(int posicao);
    int retirarFinal();
};
}
#endif // LLDE_H
