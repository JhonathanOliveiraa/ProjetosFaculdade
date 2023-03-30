#include "cone.h"
namespace jhone{
Cone::Cone():
    Cilindro()
{
}
Cone::Cone(float raio, float altura):
    Cilindro(raio,altura)
{
}
float Cone::calcularGeratriz()const{
    float geratriz=0;
    geratriz = (sqrt((altura*altura)+(raio*raio)));
    return geratriz;
}
float Cone::calcularAreaLateral()const{
    return (3.1415*raio*calcularGeratriz());
}
float Cone::calcularAreaTotal()const{
    return(3.1415*raio*(calcularGeratriz()+raio));
}
float Cone::calcularVolume()const{
    return (1.0/3.0*3.1415*raio*raio*altura);
}
QString Cone::toString()const{
    QString saida = "{Cone - Raio ";
    saida += QString::number(raio);
    saida += " e Altura ";
    saida += QString::number(altura);
    saida += " } ";
    return saida;
}
QString Cone::obterTipoFigura()const{
    return FiguraGeometrica::obterTipoFigura() + "Cone";
}
}
