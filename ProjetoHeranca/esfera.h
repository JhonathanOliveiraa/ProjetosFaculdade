#ifndef ESFERA_H
#define ESFERA_H
#include <figurageometrica.h>
#include <QString>

namespace jhone{
class Esfera : public FiguraGeometrica
{
public:
    Esfera();
    Esfera(float raio);
    //sobrescrever os métodos abstratos
    float calcularAreaTotal()const;
    float calcularVolume()const;
    //sobrescrever os métodos concretos
    QString obterTipoFigura()const;
    QString toString()const;
};
}
#endif // ESFERA_H
