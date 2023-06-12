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
void LLSE::inserirPosicao(int elemento,int posicao){
    try {
        if(posicao < 0 || posicao > quantidadeElementos) throw QString ("Posição inválida - Inserir");
        if(posicao == 0){
            inserirInicio(elemento);
            return;
        }
        if(posicao==quantidadeElementos){
            inserirFinal(elemento);
            return;
        }
        No *Novo= new No(elemento);
        No *aux = inicio;
        for(int pos=0;pos<posicao-1;pos++){
            aux = aux->getProximo();
        }
        Novo->setProximo(aux->getProximo());
        aux->setProximo(Novo);
        quantidadeElementos++;
    } catch (std::bad_alloc &erro) {
        throw QString ("Não foi possível criar o nó - InserirPosição");
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
void LLSE::inserirOrdenado(int elemento){
    try {
        No *novo = new No(elemento);
        if(estaVazia()){
            quantidadeElementos++;
            novo->setProximo(inicio);
            inicio=novo;
            return;
        }
        No *aux = inicio;
        No *aux2, *menor;
        for(int pos = 0; pos < quantidadeElementos-1; pos++){
            aux2=aux->getProximo();
            menor = aux;
        }
        for(int i = 0; i < quantidadeElementos; i++){
            if(aux2->getDado() > menor->getDado()){
                menor = aux2;
            }
            aux2 = aux2->getProximo();
        }
        int auxi2 = aux->getDado();
        aux->setDado(menor->getDado());
        menor->setDado(auxi2);
        aux = aux->getProximo();

    } catch (std::bad_alloc &erro) {
        throw QString ("Não foi possível criar o nó - inserirOrdenado");
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
int LLSE::retirarPosicao(int posicao){
    if(estaVazia())throw QString ("A lista está vazia - retirarPosicao");
    if(posicao < 0 || posicao >= quantidadeElementos) throw QString ("Posição inválida - Inserir");
    if(posicao == 0) return retirarInicio();
    if(posicao == quantidadeElementos-1) return retirarFinal();
    No *anterior = inicio;
    for (int i = 0; i < posicao-1;i++){
        anterior = anterior->getProximo();
    }
    No *aux = anterior->getProximo();
    anterior->setProximo(aux->getProximo());
    quantidadeElementos--;
    int valor = aux->getDado();
    delete aux;
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
int LLSE::acessarPosicao(int posicao){
    if(estaVazia()) throw QString ("A lista está vazia");
    if(posicao<0 || posicao>=quantidadeElementos) throw QString ("Posição inválida - acessarPosicao");
    if(posicao==0) return acessarInicio();
    if(posicao==quantidadeElementos-1) return acessarFinal();
    No *aux=inicio;
    for(int pos=0;pos<posicao;pos++){
        aux=aux->getProximo();
    }
    return aux->getDado();
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

