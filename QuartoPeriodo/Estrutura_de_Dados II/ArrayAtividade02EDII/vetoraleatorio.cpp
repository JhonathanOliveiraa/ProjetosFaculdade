#include "vetoraleatorio.h"
namespace jhone{

VetorAleatorio::VetorAleatorio(int tamanho):
    tamanho(0)
{
    if(tamanho<=0) throw QString ("Tamanho não pode ser negativo nem 0");
    try {
        array = new int[tamanho];
        this->tamanho=tamanho;
        unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
        std::srand(seed);
        for(int i=0;i<tamanho;i++){
            int numeroAleatorio = std::rand() %1000 +1;
            array[i] = numeroAleatorio;
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
    for(int i=0;i<tamanho;i++){
        if(aux == array[i]){
            return i;
        }
    }
    throw QString("O número procurado não existe");
}
QString VetorAleatorio::getConjunto(){
    QString saida = "";
    for(int i=0;i<tamanho;i++){
    saida += QString::number(array[i]) + " | ";
    }
    return saida;
}
}
