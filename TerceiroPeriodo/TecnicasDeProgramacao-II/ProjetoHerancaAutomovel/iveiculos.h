#ifndef IVEICULOS_H
#define IVEICULOS_H
namespace jhone{

class IVeiculos
{
private:
public:
    IVeiculos();
    virtual float acelerar() = 0;
    virtual float freiar() = 0;
    virtual float virar(int raio) = 0;
};
}
#endif // IVEICULOS_H
