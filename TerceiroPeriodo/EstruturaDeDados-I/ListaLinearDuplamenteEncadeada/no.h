#ifndef NO_H
#define NO_H
#include <QString>
namespace jhone{

class No
{
private:
    int dado;
    No *proximo;
    No *anterior;
public:
    No();
    No(int dado);
    No *getProximo() const;
    void setProximo(No *newProximo);
    No *getAnterior() const;
    void setAnterior(No *newAnterior);
    int getDado() const;
    void setDado(int newDado);
};
}
#endif // NO_H
