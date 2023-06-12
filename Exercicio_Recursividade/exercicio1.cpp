#include "exercicio1.h"

namespace jhone{
Exercicio1::Exercicio1()
{
}
QString Exercicio1::imprimirIterativo(int n)
{
    QString saida="";
    for(int valor = 1; valor<=n; valor++){
        saida += QString::number(valor);
        if(valor<n){
            saida += ", ";
        }
    }
    return saida;
}

QString Exercicio1::imprimirRecursivo(int n, int valor, QString saida)
{
    if(valor <= n){
        saida += QString::number(valor);
        if(valor < n){
            saida += ", ";
        }
        return imprimirRecursivo(n, valor+1, saida);
    }
    else return saida;
}

QString Exercicio1::imprimirParesIterativo(int n)
{
    QString saida ="";
    for(int valor = 1; valor<=n; valor++){
        if(valor%2==0){
            saida+=QString::number(valor);
        }
        if(valor%2==0 && valor<n){
            saida += ", ";
        }
    }
    return saida;
}

QString Exercicio1::imprimirParesRecursivo(int n, int valor, QString saida)
{
    if(valor <= n){
        if(valor%2==0){
            saida+=QString::number(valor);
        }
        if(valor%2==0 && valor<n){
            saida += ", ";
        }
        return imprimirParesRecursivo(n, valor+1, saida);
    }
    else return saida;
}

QString Exercicio1::imprimirImparesIterativo(int n)
{
    QString saida ="";
    for(int valor = 1; valor<=n; valor++){
        if(valor%2!=0){
            saida+=QString::number(valor);
        }
        if(valor%2!=0 && valor<n){
            saida += ", "; }
    }
    return saida;
}

QString Exercicio1::imprimirImparesRecursivo(int n, int valor, QString saida)
{
    if(valor <= n){
        if(valor%2!=0){ saida+=QString::number(valor); }
        if(valor%2!=0 && valor<n){ saida += ", "; }
        return imprimirImparesRecursivo(n, valor+1, saida);
    }
    else return saida;
}

QString Exercicio1::somarIterativo(int n)
{
    QString saida="";
    int soma = 0;
    for(int valor = 1; valor<=n; valor++){
        soma = soma + valor;
    }
    saida = QString::number(soma);
    return saida;
}

QString Exercicio1::somarRecursivo(int n, int valor, int soma, QString saida)
{
    if(valor <= n){
        soma = soma+valor;
        return somarRecursivo(n, valor+1, soma,  saida);
    }
    else{
        saida = QString::number(soma);
        return saida;
    }
}

QString Exercicio1::piPrecisaoIterativo()
{
    std::cout<<std::fixed<<std::setprecision(4);
    double sinal = 1, pi = 0;
    for(double impar = 1.0; 4/impar > 0.0001; impar = impar+2){
        pi = pi + (4/impar)*sinal;
        sinal = sinal*(-1);
    }
    QString saida = QString::number(pi);
    return saida;
}

double Exercicio1::piPrecisaoRecursivo(double pi, double sinal, double impar)
{
    std::cout<<std::fixed<<std::setprecision(4);
    if(4/impar > 0.0001){
        pi = pi + (4/impar)*sinal;
        sinal = sinal*(-1);
        return piPrecisaoRecursivo(pi, sinal, impar+2);
    }
    return pi;
}
}
