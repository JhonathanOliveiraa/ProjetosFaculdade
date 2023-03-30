#include "cilindro.h"
namespace jhone{

Cilindro::Cilindro():
    FiguraGeometrica(),
    altura(0)
{
}
Cilindro::Cilindro(float raio, float altura):
    FiguraGeometrica(raio),
    altura(0)
{
    if(altura<=0)throw QString ("Altura não pode ser <= 0");
    this->altura = altura;
}

float Cilindro::getAltura() const
{
    return altura;
}

void Cilindro::setAltura(float newAltura)
{
    if(newAltura<=0)throw QString ("Altura não pode ser <= 0");
    altura = newAltura;
}
float Cilindro::calcularAreaLateral()const{
    return ((2*3.1415)*raio*altura);
}
float Cilindro::calcularAreaTotal()const{
    return ((2*3.1415)*raio *(altura+raio));
}
float Cilindro::calcularVolume()const{
    return ((3.1415*raio*raio)*altura);
}
QString Cilindro::toString()const{
    QString saida = "{Cilindro - Raio ";
    saida += QString::number(raio);
    saida += " e Altura ";
    saida += QString::number(altura);
    saida += " } ";
    return saida;
}
QString Cilindro::obterTipoFigura()const{
    return FiguraGeometrica::obterTipoFigura() + "Cilindro";
}
}
