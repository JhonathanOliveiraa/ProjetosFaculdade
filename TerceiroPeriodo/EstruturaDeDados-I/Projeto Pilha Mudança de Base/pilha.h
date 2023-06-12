#ifndef PILHA_H
#define PILHA_H
#include <QString>
namespace jhone{

class Pilha
{
    //atributos
private:
    int tamanho;
    int *array;
    int topo;
public:
    Pilha(int tamanho);
    ~Pilha ();
    bool estaCheia()const;
    bool estaVazia()const;
    int acessar() const;
    void empilhar(int valor); //n pd ser 'const' pq ele altera o valor dos atributos
    int desempilhar(); //n pd ser 'const' pq ele altera o valor dos atributos
    int retornaTopo();
};
}
#endif // PILHA_H

