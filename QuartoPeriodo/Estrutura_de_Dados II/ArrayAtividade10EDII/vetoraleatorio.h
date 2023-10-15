#ifndef VETORALEATORIO_H
#define VETORALEATORIO_H
#include <QString>
#include <ctime>
#include <random>
#include <bits/stdc++.h>

namespace jhone{
class VetorAleatorio
{
private:
    int tamanho;
    int *array;
    int *arraySelectionSort;
    int *arrayInsertionSort;
    int *arrayBubbleSort;
    int *arrayMergeSort;
    int *arrayHeapSort;
    int numExec;
    int numOrdenSelectionSort;
    int numOrdenInsertionSort;
    int numOrdenBubbleSort;
public:
    VetorAleatorio(int tamanho);
    ~VetorAleatorio();
    int getTamanho() const;
    QString getConjunto();
    QString getConjuntoOrdenadoSelectionSort();
    QString getConjuntoOrdenadoInsertionSort();
    QString getConjuntoOrdenadoBubbleSort();
    QString getConjuntoOrdenadoMergeSort();
    QString getConjuntoOrdenadoHeapSort();
    int buscarNumero(int aux);
    int buscarNumeroMelhorado(int aux);
    int buscarBinaria(int aux);
    void selectionSort();
    void insertionSort();
    void bubbleSort();
    void merge(int arr[], int p, int q, int r);
    void mergeSort(int arr[], int l, int r);
    void heapify(int arr[], int n, int i);
    void heapSort(int arr[], int n);
    int getNumExec() const;
    int getNumOrdenSelectionSort() const;
    int getNumOrdenInsertionSort() const;
    int getNumOrdenBubbleSort() const;
};
}
#endif // VETORALEATORIO_H
