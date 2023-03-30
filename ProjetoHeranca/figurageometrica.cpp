#include "figurageometrica.h"
namespace jhone{
FiguraGeometrica::FiguraGeometrica():
    raio(0)
{
}
FiguraGeometrica::FiguraGeometrica(float raio):
    raio(0)
{
    if (raio<=0)throw QString("Raio não pode ser menor ou igual a 0");
    this->raio = raio;
}
float FiguraGeometrica::getRaio() const
{
    return raio;
}
void FiguraGeometrica::setRaio(float newRaio)
{
    raio = newRaio;
}
QString FiguraGeometrica::obterTipoFigura()const{
    return "Figura Geometrica => ";
}
QString FiguraGeometrica::toString()const{
    QString saida= "{Figura Geometrica - Raio: ";
    saida += QString::number(raio);
    saida += " } ";
    return saida;
}
}
