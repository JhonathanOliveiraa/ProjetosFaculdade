#ifndef EXERCICIO1_H
#define EXERCICIO1_H
#include <QString>
#include <iostream>
#include <math.h>
#include <iomanip>
namespace jhone{
class Exercicio1
{
public:
    Exercicio1();

    QString imprimirIterativo(int n);
    QString imprimirRecursivo(int n, int valor, QString saida);
    QString imprimirParesIterativo(int n);
    QString imprimirParesRecursivo(int n, int valor, QString saida);
    QString imprimirImparesIterativo(int n);
    QString imprimirImparesRecursivo(int n, int valor, QString saida);
    QString somarIterativo(int n);
    QString somarRecursivo(int n, int valor, int soma, QString saida);
    QString piPrecisaoIterativo();
    double piPrecisaoRecursivo(double pi, double sinal, double impar);

};
}
#endif // EXERCICIO1_H
