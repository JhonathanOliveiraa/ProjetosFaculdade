#ifndef BARCO_H
#define BARCO_H
#include <automovel.h>
#include <iveiculos.h>
#include <QString>
namespace jhone{
class Barco : public IVeiculos
{
private:
    int velocidadeAtual;
    int tempoHoras;
public:
    Barco();
    Barco(int velocidadeAtual,int tempoHoras);
    float acelerar();
    float freiar();
    float virar(int raio);
};
}
#endif // BARCO_H
