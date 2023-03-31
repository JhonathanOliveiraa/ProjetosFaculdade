#ifndef CONE_H
#define CONE_H
#include <cilindro.h>
#include <cmath>
#include <QString>
namespace jhone{
class Cone: public Cilindro
{
public:
    Cone();
    Cone(float raio,float altura);
    float calcularGeratriz()const;
    float calcularAreaLateral()const;
    float calcularAreaTotal()const;
    float calcularVolume()const;
    QString toString()const;
    QString obterTipoFigura()const;
};
}
#endif // CONE_H
