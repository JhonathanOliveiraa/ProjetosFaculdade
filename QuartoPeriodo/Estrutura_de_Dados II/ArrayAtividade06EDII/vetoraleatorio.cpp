#include "vetoraleatorio.h"
namespace jhone{


VetorAleatorio::VetorAleatorio(int tamanho):
    tamanho(0),
    numExec(0),
    numOrden(0)
{
    if(tamanho<=0) throw QString ("Tamanho não pode ser negativo nem 0");
    try {
        array = new int[tamanho];
        arraySelectionSort = new int[tamanho];
        this->tamanho=tamanho;
        unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
        std::srand(seed);
        for(int i=0;i<tamanho;i++){
            int numeroAleatorio = std::rand() %1000 +1;
            array[i] = numeroAleatorio;
            arraySelectionSort[i] = numeroAleatorio;
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
QString VetorAleatorio::getConjuntoOrdenado(){
    QString saida = "| ";
    for(int i=0;i<tamanho;i++){
    saida += QString::number(arraySelectionSort[i]) + " | ";
    }
    return saida;
}
void VetorAleatorio::selectionSort(){
    this->numExec=0;
    for(int step = 0; step < getTamanho() -1; step++){
        int num_min = step;
        for(int i = step + 1; i < getTamanho(); i++){
            numExec++;
            if(arraySelectionSort[i] < arraySelectionSort[num_min]){
                num_min = i;
            }
        }
        int temp = arraySelectionSort[step];
        arraySelectionSort[step] = arraySelectionSort[num_min];
        arraySelectionSort[num_min] = temp;
    }
}
int VetorAleatorio::getNumExec() const
{
    return numExec;
}

int VetorAleatorio::getNumOrden() const
{
    return numOrden;
}

}
