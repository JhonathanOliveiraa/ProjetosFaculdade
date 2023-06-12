#include "llde.h"
namespace jhone {

LLDE::LLDE():
    quantidadeElementos(0),
    inicio(0),
    fim(0)
{
}
bool LLDE::estaVazia()const{
    return (quantidadeElementos==0);
}
void LLDE::inserirInicio(int elemento){
    try{
             No *aux = new No(elemento);
             if(estaVazia())
             {
                 inicio = fim = aux;
                 quantidadeElementos++;
                 return;
             }
             inicio->setAnterior(aux);
             aux->setProximo(inicio);
             inicio = aux;
             quantidadeElementos++;
         }catch (std::bad_alloc &erro)
         {
             throw QString("Nao foi possivel alocar memoria - inserirInicio");
         }
}
void LLDE::inserirPosicao(int elemento, int posicao){
         try {
             if(posicao < 0 || posicao > quantidadeElementos) throw QString ("Posição inválida - InserirPosicao");
             if(posicao == 0){
                 inserirInicio(elemento);
                 return;
             }
             if(posicao==quantidadeElementos-1){
                 inserirFinal(elemento);
                 return;
             }
             No *Novo= new No(elemento);
             No *aux = inicio;
             for(int pos=0;pos<posicao-1;pos++){
                 aux = aux->getProximo();
             }
             Novo->setAnterior(aux->getAnterior());
             Novo->setProximo(aux->getProximo());
             aux->setProximo(Novo);
             quantidadeElementos++;
         } catch (std::bad_alloc &erro) {
             throw QString ("Não foi possível criar o nó - InserirPosição");
         }
}
void LLDE::inserirFinal(int elemento){
    try {
        No *aux = new No (elemento);
        if(estaVazia()){
            inicio = fim = aux;
            quantidadeElementos++;
            return;
        }
        fim->setProximo(aux);
        aux->setAnterior(fim);
        quantidadeElementos++;
        fim = aux;
    }catch (std::bad_alloc &erro)
    {
        throw QString("Nao foi possivel alocar memoria - inserirFinal");
    }
}
void LLDE::inserirOrdenado(int elemento){
    try {
        No *novo = new No (elemento);
        if(estaVazia()){
            inicio = fim = novo;
            quantidadeElementos++;
            return;
        }
        else if (elemento < inicio->getDado()){
            novo->setProximo(inicio);
            inicio->setAnterior(novo);
            inicio=novo;
        }
        else {
            No *aux = inicio;
            while (aux->getProximo() != nullptr && aux->getProximo()->getDado() < elemento){
                aux = aux->getProximo();
        }
        if (aux->getProximo() == nullptr) {
            fim = novo;
        } else {
            aux->getProximo()->setAnterior(novo);
        }
        novo->setProximo(aux->getProximo());
        novo->setAnterior(aux);
        aux->setProximo(novo);
    }
    quantidadeElementos++;
    } catch (std::bad_alloc &erro)
    {
        throw QString("Nao foi possivel alocar memoria - inserirFinal");
    }
}
int LLDE::acessarInicio()const{
    if(estaVazia()) throw QString ("A lista está vazia - acessarInicio");
    return inicio->getDado();
}
int LLDE::acessarPosicao(int posicao){
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
int LLDE::acessarFinal()const{
    if(estaVazia()) throw QString ("A lista está vazia - acessarFinal");
    return fim->getDado();
}
int LLDE::retirarInicio(){
    if(estaVazia()) throw QString ("A lista está vazia - retirarInicio");
    int valor = inicio->getDado();
    if(quantidadeElementos==1){
        delete inicio;
        fim = inicio = 0;
        quantidadeElementos--;
        return valor;
    }
    inicio=inicio->getProximo();
    delete inicio->getAnterior();
    inicio->setAnterior(0);
    quantidadeElementos--;
    return valor;
}
int LLDE::retirarPosicao(int posicao){
    if(estaVazia())throw QString ("A lista está vazia - retirarPosicao");
    if(posicao < 0 || posicao >= quantidadeElementos) throw QString ("Posição inválida - Inserir");
    if(posicao == 0) return retirarInicio();
    if(posicao == quantidadeElementos -1) return retirarFinal();
    No *aux = inicio;
    for (int i = 0; i < posicao;i++){
        aux = aux->getProximo();
    }
    int valor = aux->getDado();
    aux->getAnterior()->setProximo(aux->getProximo());
    aux->getProximo()->setAnterior(aux->getAnterior());
    delete aux;
    quantidadeElementos--;
    return valor;
}
int LLDE::retirarFinal(){
    if(estaVazia()) throw QString ("A lista está vazia - retirarFinal");
    No *aux=fim;
    if(quantidadeElementos==1){
    quantidadeElementos=0;
    inicio=fim=0;
    int valor = aux->getDado();
    delete aux;
    return valor;
    }
    fim->getAnterior()->setProximo(0);
    fim=aux->getAnterior();
    int valor = aux->getDado();
    delete aux;
    quantidadeElementos--;
    return valor;
}
QString LLDE::obterLista()const{
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
    if(estaVazia()) resultado = "{ A lista está vazia }";
    return resultado;
}
}
