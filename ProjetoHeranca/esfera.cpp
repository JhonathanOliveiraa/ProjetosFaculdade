#include "esfera.h"
namespace jhone{
Esfera::Esfera():
    FiguraGeometrica()
{

}
Esfera::Esfera(float raio):
    FiguraGeometrica(raio)
{
}
float Esfera::calcularAreaTotal()const{
    return (4.0 * 3.1415 *raio *raio);
}
float Esfera::calcularVolume()const{
    return ((4.0/3.0)*3.1415 *raio *raio *raio);
}
QString Esfera::toString()const{
    QString saida= "{ Esfera - Raio: ";
    saida += QString::number(raio);
    saida += " } ";
    return saida;
}
QString Esfera::obterTipoFigura()const{
    return FiguraGeometrica::obterTipoFigura() + "Esfera";
}
}
