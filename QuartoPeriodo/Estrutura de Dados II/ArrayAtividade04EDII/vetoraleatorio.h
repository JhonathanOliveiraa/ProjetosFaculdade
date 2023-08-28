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
    int *arraySelectionSort;
public:
    VetorAleatorio(int tamanho);
    ~VetorAleatorio();
    int getTamanho() const;
    QString getConjunto();
    QString getConjuntoOrdenado();
    int buscarNumero(int aux);
    int buscarNumeroMelhorado(int aux);
    void selectionSort();
    int buscarBinaria(int aux);
    //fazer uma cópia para que não haja problemas com exclusão
};
}
#endif // VETORALEATORIO_H
