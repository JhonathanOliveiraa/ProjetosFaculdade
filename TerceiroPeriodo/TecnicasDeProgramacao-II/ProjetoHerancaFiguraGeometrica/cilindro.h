#ifndef CILINDRO_H
#define CILINDRO_H
#include <figurageometrica.h>
#include <QString>

namespace jhone{
class Cilindro: public FiguraGeometrica
{
protected:
    float altura;
public:
    Cilindro();
    Cilindro(float raio, float altura);
    float calcularAreaLateral()const;
    float calcularAreaTotal()const;
    float calcularVolume()const;
    float getAltura() const;
    void setAltura(float newAltura);
    QString toString()const;
    QString obterTipoFigura()const;
};
}
#endif // CILINDRO_H
