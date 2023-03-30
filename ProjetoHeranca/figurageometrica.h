#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include <QString>
namespace jhone{
class FiguraGeometrica // Abstrata
{
protected:
    float raio;
public:
    FiguraGeometrica();
    FiguraGeometrica(float raio);
    QString obterTipoFigura()const;
    float getRaio() const;
    void setRaio(float newRaio);
    QString toString()const;
    virtual float calcularAreaTotal()const = 0;
    virtual float calcularVolume()const = 0;
};
}
#endif // FIGURAGEOMETRICA_H
