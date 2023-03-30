#ifndef NO_H
#define NO_H
namespace Jhone{

class No
{
    //Atributos
private:
    int dado;
    No* proximo;
    //Metodos
public:
    No();
    No(int dado);
    int getDado() const;
    void setDado(int newDado);
    No *getProximo() const;
    void setProximo(No *newProximo);
};
}
#endif // NO_H
