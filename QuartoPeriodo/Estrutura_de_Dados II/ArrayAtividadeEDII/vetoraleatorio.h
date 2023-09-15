#ifndef VETORALEATORIO_H
#define VETORALEATORIO_H
#include <QString>
#include <ctime>
#include <random>
namespace jhone{
class VetorAleatorio
{
private:
    int tamanho;
    int *array;
public:
    VetorAleatorio(int tamanho);
    ~VetorAleatorio();
    int getTamanho() const;
    QString getConjunto();
    //fazer uma cópia para que não haja problemas com exclusão
};
}
#endif // VETORALEATORIO_H
