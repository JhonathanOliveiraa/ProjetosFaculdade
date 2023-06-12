#ifndef AVIAO_H
#define AVIAO_H
#include <QString>
#include <iveiculos.h>
#include <automovel.h>
namespace jhone{

class Aviao : public IVeiculos
{
private:
    int velocidadeAtual;
    int tempoHoras;

public:
    Aviao();
    Aviao(int velocidadeAtual, int tempoHoras);
    float acelerar();
    float freiar();
    float virar(int raio);
};
}
#endif // AVIAO_H
