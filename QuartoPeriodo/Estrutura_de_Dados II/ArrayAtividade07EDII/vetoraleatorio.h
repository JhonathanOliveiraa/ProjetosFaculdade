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
    int *arrayInsertionSort;
    int numExec;
    int numOrdenSelectionSort;
    int numOrdenInsertionSort;
public:
    VetorAleatorio(int tamanho);
    ~VetorAleatorio();
    int getTamanho() const;
    QString getConjunto();
    QString getConjuntoOrdenadoSelectionSort();
    QString getConjuntoOrdenadoInsertionSort();
    double medicaoSelectionSort();
    double medicaoInsertionSort();
    int buscarNumero(int aux);
    int buscarNumeroMelhorado(int aux);
    void selectionSort();
    void insertionSort();
    int buscarBinaria(int aux);
    int getNumExec() const;
    int getNumOrdenSelectionSort() const;
    int getNumOrdenInsertionSort() const;
};
}
#endif // VETORALEATORIO_H
