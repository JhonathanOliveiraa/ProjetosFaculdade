#ifndef ICONTAGERAL_H
#define ICONTAGERAL_H
namespace jhone{
class IContaGeral
{
public:
    IContaGeral();
    virtual float depositarDinheiro() = 0;
    virtual float sacarDinheiro() = 0;
    virtual float emitirSaldo() const = 0;
};
}
#endif // ICONTAGERAL_H
