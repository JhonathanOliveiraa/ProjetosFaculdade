#include "llse.h"
namespace Jhone{

LLSE::LLSE():
    quantidadeElementos(0),
    inicio(0)
{
}
bool LLSE::estaVazia()const{
    return (quantidadeElementos==0);
}
int LLSE::getQuantidadeElementos() const
{
    return quantidadeElementos;
}
void LLSE::inserirInicio(int elemento){
    try {
        No *aux = new No(elemento);
        quantidadeElementos++;
        aux->setProximo(inicio);
        inicio=aux;
    } catch (std::bad_alloc &erro) {
        throw QString ("Não foi possível criar o nó - inserirInicio");
    }
}
void LLSE::inserirFinal(int elemento){
    try {
        No *novo = new No(elemento);
        if(estaVazia()) {
            quantidadeElementos++;
            inicio=novo;
            return;
        }
        No *aux = inicio;
        while (aux->getProximo() != 0){
            aux=aux->getProximo();
        }
        aux->setProximo(novo);
        quantidadeElementos++;
    }
     catch (std::bad_alloc &erro) {
        throw QString ("Não foi possível criar o nó - inserirFinal");
    }
    }
int LLSE::retirarInicio(){
    if(estaVazia())throw QString ("A lista está vazia - retirarInicio");
    No* aux = inicio;
    inicio = aux->getProximo();
    int valor = aux->getDado();
    delete aux;
    quantidadeElementos--;
    return valor;
}
int LLSE::retirarFinal(){
    if(estaVazia())throw QString ("A lista está vazia - retirarFinal");
    if(quantidadeElementos==1){
        int valor = inicio->getDado();
        delete inicio;
        quantidadeElementos=0;
        inicio=0;
        return valor;
    }
    No *aux = inicio;
    while (aux->getProximo()->getProximo() != 0){
        aux = aux->getProximo();
    }
    int valor = aux->getProximo()->getDado();
    delete aux->getProximo();
    aux->setProximo(0);
    quantidadeElementos--;
    return valor;
}
int LLSE::acessarInicio(){
    if(estaVazia())throw QString ("A lista está vazia");
    return inicio->getDado();
}
int LLSE::acessarFinal()const{
    if(estaVazia())throw QString ("A lista está vazia");
    No *aux=inicio;
    while (aux->getProximo() != 0){
        aux=aux->getProximo();
    }
    return aux->getDado();
}
QString LLSE::obterDadosLLSE()const{
    if(estaVazia())throw QString ("A lista está vazia");
    QString resultado = " | ";
    No *aux=inicio;
    for(int pos=0;pos<quantidadeElementos;pos++){
        resultado += QString::number(aux->getDado());
        aux = aux->getProximo();
        if(pos < quantidadeElementos-1){
            resultado += " | -> | ";
        }
    }
    resultado += " | ";
    return resultado;
}

}

