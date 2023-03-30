#ifndef MUDARBASE_H
#define MUDARBASE_H
#include <QString>
namespace jhone{

class MudarBase
{
private:
    int numero;
    int base;
public:
    MudarBase(int numero, int base);
    QString calcularMB();
    int saidaConvert();
};

#endif // MUDARBASE_H
//numero e base(atributos)type
// metodos set's e gets e calcular mbtype
}
