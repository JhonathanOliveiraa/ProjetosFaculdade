#ifndef EXERCICIOS_H
#define EXERCICIOS_H
#include <QString>
#include <math.h>
#include <ctime>

namespace gft{

class Exercicios
{
public:
    Exercicios();

    //Primerios somados ao CUBO
    QString primeirosCubosIterativo(int n);
    int primeirosCubosRecursivo(int cubos, int aux, int n);

    //Numeros naturais em ordem decrescente
    QString numNaturaisDecrecenteIterativo(int n);
    QString numNaturaisDecrescenteRecursivo(int n, QString ordenado);

    //Menor elemento do vetor
    int menorElementoVetorIterativo(int tamanho);
    int menorElementoVetorRecursivo(int tamanho, int vetor[], int indice, int auxMenor);

    //Conversão de base numérica
    QString imprimeNumeroBinarioIterativo(int n, int valor, int tamanho, QString saida);
    QString converterParaBinarioRecursivo(int n, int valor, int tamanho, QString saida);
    //Potenciação de X à Y
    QString imprimePotenciacaoIterativo(int x, int y, int k, QString saida);
    QString imprimePotenciacaoRecursivo(int x, int y, int k, int contador, QString saida);

    //Produto de N1 e N2
    QString imprimeProdutoIterativo(int n1, int n2, int produto, QString saida);
    QString imprimeProdutoRecursivo(int n1, int n2, int produto, int contador, QString saida);

};
}
#endif // EXERCICIOS_H
