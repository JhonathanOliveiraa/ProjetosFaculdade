#include "vetoraleatorio.h"
namespace jhone{


VetorAleatorio::VetorAleatorio(int tamanho):
    tamanho(0),
    numExec(0),
    numOrdenSelectionSort(0),
    numOrdenInsertionSort(0),
    numOrdenBubbleSort(0)
{
    if(tamanho<=0) throw QString ("Tamanho não pode ser negativo nem 0");
    try {
        array = new int[tamanho];
        arraySelectionSort = new int[tamanho];
        arrayInsertionSort = new int[tamanho];
        arrayBubbleSort = new int[tamanho];
        arrayMergeSort = new int[tamanho];
        arrayHeapSort = new int[tamanho];
        arrayQuickSort = new int[tamanho];
        this->tamanho=tamanho;
        unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
        std::srand(seed);
        for(int i=0;i<tamanho;i++){
            int numeroAleatorio = std::rand() %1000 +1;
            array[i] = numeroAleatorio;
            arraySelectionSort[i] = numeroAleatorio;
            arrayInsertionSort[i] = numeroAleatorio;
            arrayBubbleSort[i] = numeroAleatorio;
            arrayMergeSort[i] = numeroAleatorio;
            arrayHeapSort[i] = numeroAleatorio;
            arrayQuickSort[i] = numeroAleatorio;
        }
    } catch (std::bad_alloc &erro) {
        throw QString ("Erro ao gerar número aleatório");
    }
}
VetorAleatorio::~VetorAleatorio(){
    delete array;
}

int VetorAleatorio::getTamanho() const
{
    return tamanho;
}
int VetorAleatorio::buscarNumero(int aux){
    this->numExec=0;
    for(int i=0;i<tamanho;i++){
        numExec++;
        if(aux == array[i]){
            return i;
        }
    }
    numExec++;
    return -1;
}
int VetorAleatorio::buscarNumeroMelhorado(int aux){
    this->numExec=0;

    for(int i=0;i<tamanho;i++){
        numExec++;
        if(aux == arraySelectionSort[i]){
            return i;
        }
        if(aux < arraySelectionSort[i]){
            return -1;
        }
    }
    return -1;
}
int VetorAleatorio::buscarBinaria(int aux){
    this->numExec=0;
    int inicio=0, fim = tamanho -1;
    while(inicio <= fim){
        numExec++;
        int meio = (inicio+fim)/2;
        if(arraySelectionSort[meio]==aux) return meio;
        if(arraySelectionSort[meio]<aux) inicio = meio+1;
        else fim = meio -1;
    }
    return -1;
}
QString VetorAleatorio::getConjunto(){
    QString saida = "| ";
    for(int i=0;i<tamanho;i++){
        saida += QString::number(array[i]) + " | ";
    }
    return saida;
}
QString VetorAleatorio::getConjuntoOrdenadoSelectionSort(){
    selectionSort();
    QString saida = "| ";
    for(int i=0;i<tamanho;i++){
        saida += QString::number(arraySelectionSort[i]) + " | ";
    }
    return saida;
}
QString VetorAleatorio::getConjuntoOrdenadoInsertionSort()
{
    insertionSort();
    QString saida = "| ";
    for(int i=0;i<tamanho;i++){
        saida += QString::number(arrayInsertionSort[i]) + " | ";
    }
    return saida;
}

QString VetorAleatorio::getConjuntoOrdenadoBubbleSort()
{
    bubbleSort();
    QString saida = "| ";
    for(int i=0;i<tamanho;i++){
        saida += QString::number(arrayBubbleSort[i]) + " | ";
    }
    return saida;
}
QString VetorAleatorio::getConjuntoOrdenadoMergeSort()
{
    mergeSort(arrayMergeSort,0,tamanho-1);
    QString saida = "| ";
    for(int i=0;i<tamanho;i++){
        saida += QString::number(arrayMergeSort[i]) + " | ";
    }
    return saida;
}

QString VetorAleatorio::getConjuntoOrdenadoHeapSort()
{
    mergeSort(arrayMergeSort,0,tamanho-1);
    QString saida = "| ";
    for(int i=0;i<tamanho;i++){
        saida += QString::number(arrayMergeSort[i]) + " | ";
    }
    return saida;
}

QString VetorAleatorio::getConjuntoOrdenadoQuickSort()
{
    quickSort(arrayQuickSort,0,tamanho-1);
    QString saida = "| ";
    for(int i=0;i<tamanho;i++){
        saida += QString::number(arrayQuickSort[i]) + " | ";
    }
    return saida;
}
void VetorAleatorio::selectionSort(){
    this->numOrdenSelectionSort=0;
    for(int step = 0; step < getTamanho() -1; step++){
        int num_min = step;
        for(int i = step + 1; i < getTamanho(); i++){
            numOrdenSelectionSort++;
            if(arraySelectionSort[i] < arraySelectionSort[num_min]){
                num_min = i;
                numOrdenSelectionSort++;
            }
        }
        int temp = arraySelectionSort[step];
        arraySelectionSort[step] = arraySelectionSort[num_min];
        arraySelectionSort[num_min] = temp;
    }
}
void VetorAleatorio::insertionSort() {
    this->numOrdenInsertionSort=0;
    for (int step = 1; step < getTamanho(); step++) {
        int key = arrayInsertionSort[step];
        int j = step - 1;
        while (key < arrayInsertionSort[j] && j >= 0) {
            arrayInsertionSort[j + 1] = arrayInsertionSort[j];
            --j;
            numOrdenInsertionSort++;
        }
        arrayInsertionSort[j + 1] = key;
    }
}

void VetorAleatorio::bubbleSort(){
    this->numOrdenBubbleSort=0;
    for (int step = 0; step < (getTamanho()-1); ++step) {

        // check if swapping occurs
        int swapped = 0;

        // loop to compare two elements
        for (int i = 0; i < (getTamanho()-step-1); ++i) {

            // compare two array elements
            // change > to < to sort in descending order
            if (arrayBubbleSort[i] > arrayBubbleSort[i + 1]) {

                // swapping occurs if elements
                // are not in intended order
                int temp = arrayBubbleSort[i];
                arrayBubbleSort[i] = arrayBubbleSort[i + 1];
                arrayBubbleSort[i + 1] = temp;
                numOrdenBubbleSort++;
                swapped = 1;
            }
        }

        // no swapping means the array is already sorted
        // so no need of further comparison
        if (swapped == 0)
            break;
    }
}
void VetorAleatorio::merge(int arr[], int p, int q, int r) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void VetorAleatorio::mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}
void VetorAleatorio::heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void VetorAleatorio::heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}
void VetorAleatorio::swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int VetorAleatorio::partition(int array[], int low, int high) {

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    // swap pivot with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

void VetorAleatorio::quickSort(int array[], int low, int high) {
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

// Driver code
int VetorAleatorio::getNumExec() const
{
    return numExec;
}

int VetorAleatorio::getNumOrdenSelectionSort() const
{
    return numOrdenSelectionSort;
}

int VetorAleatorio::getNumOrdenInsertionSort() const
{
    return numOrdenInsertionSort;
}
int VetorAleatorio::getNumOrdenBubbleSort() const
{
    return numOrdenBubbleSort;
}

}
