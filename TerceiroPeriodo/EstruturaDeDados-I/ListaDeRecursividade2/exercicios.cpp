#include "exercicios.h"

namespace gft{

Exercicios::Exercicios()
{

}


QString Exercicios::primeirosCubosIterativo(int n)
{
    int aux = 0;
    int cubos = 0;
    for(int i = 0; i <= n; i++){
        cubos = pow(i,3);
        aux += cubos;
    }
    return QString::number(aux);
}

int Exercicios::primeirosCubosRecursivo(int cubos, int aux, int n)
{
    if(cubos > n) return aux;
    else {
        aux += pow(cubos,3);
        return primeirosCubosRecursivo(cubos + 1, aux, n);
    }
}



QString Exercicios::numNaturaisDecrecenteIterativo(int n)
{
    if(n < 0)
        throw QString("Por favor, insira um valor positivo.");

    QString saida;
    for(int i = n; i >= 0; i--){
        saida += QString::number(i);
        if(i != 0) saida += ", ";
    }
    return saida;
}

QString Exercicios::numNaturaisDecrescenteRecursivo(int n, QString ordenado)
{
    if(n >= 0){
        ordenado += QString::number(n);
        if(n != 0) ordenado += ", ";
        return numNaturaisDecrescenteRecursivo(n -1, ordenado);
    }
    return ordenado;
}



int Exercicios::menorElementoVetorIterativo(int tamanho)
{
    int vetor[tamanho];
    {
        // Semente para geração de números aleatórios
        std::srand(std::time(nullptr));

        for (int i = 0; i < tamanho; i++) {
            vetor[i] = std::rand() % 101; // Gera um número aleatório entre 0 e 100
        }
    }
    if(tamanho < 0)
        throw QString ("Por Por favor, insira um valor positivo para o tamanho do vetor.");

    int menorAux = vetor[0];

    for(int i = 0; i < tamanho; i++){
        if(vetor[i] < menorAux)
            menorAux = vetor[i];
    }
    return menorAux;
}

int Exercicios::menorElementoVetorRecursivo(int tamanho, int vetor[], int indice, int auxMenor)
{
    if(indice < tamanho){
        if(vetor[indice] < auxMenor){
            auxMenor = vetor[indice];
        }
        return menorElementoVetorRecursivo(tamanho, vetor, indice +1, auxMenor);
    }
    return auxMenor;
}



QString Exercicios::imprimeNumeroBinarioIterativo(int n, int valor, int tamanho, QString saida)
{
    do
    {
        valor += tamanho * (n % 2);
        n = n / 2;
        tamanho *= 10;
    }
    while (n > 0);
    saida = QString::number(valor);
    return saida;
}

QString Exercicios::converterParaBinarioRecursivo(int n, int valor, int tamanho, QString saida)
{
    if(n>0)
    {
        valor += tamanho * (n % 2);
        return converterParaBinarioRecursivo(n/2, valor, tamanho*10, saida);
    }
    saida = QString::number(valor);
    return saida;
}



QString Exercicios::imprimePotenciacaoIterativo(int x, int y, int k, QString saida)
{
    for(int i = 1; i<y; i++)
    {
        k *= x;
    }
    saida = "Resultado = " + QString::number(k);
    return saida;
}

QString Exercicios::imprimePotenciacaoRecursivo(int x, int y, int k, int contador, QString saida)
{
    if(contador<y)
    {
        k *= x;
        return imprimePotenciacaoRecursivo(x, y, k, contador+1, saida);
    }
    saida = "Resultado = " + QString::number(k);
    return saida;
}



QString Exercicios::imprimeProdutoIterativo(int n1, int n2, int produto, QString saida)
{
    for(int i = 1; i<=n2; i++)
    {
        produto += n1;
    }
    saida = "Produto = " + QString::number(produto);
    return saida;
}

QString Exercicios::imprimeProdutoRecursivo(int n1, int n2, int produto, int contador, QString saida)
{
    if(contador<=n2)
    {
        produto += n1;
        return imprimeProdutoRecursivo(n1, n2, produto, contador+1, saida);
    }
    saida = "Produto = " + QString::number(produto);
    return saida;
}



}
