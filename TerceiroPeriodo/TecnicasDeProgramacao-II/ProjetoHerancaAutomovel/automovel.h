#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H
#include <iveiculos.h>
#include <QString>
namespace jhone{

class Automovel : public IVeiculos
{
private:
    int velocidadeAtual;
    int tempoHoras;
public:
    Automovel();
    Automovel(int velocidadeAtual,int tempoHoras);
    float acelerar();
    float freiar();
    float virar(int raio);
};
}
#endif // AUTOMOVEL_H
