#include "templatebusca.h"


TemplateBusca::TemplateBusca(std::vector<Professor> busca):
    array(busca)
{
}
Professor TemplateBusca::buscaSequencialMelhorada(QString buscar){
    std::vector<Professor> arrayOrdenado = Ordenar->arraySelectionSort();
            if((int)array.size() == 0) throw QString ("O vetor não foi iniciado");
            int aux = -1;
            for(int i=0;i<(int)array.size();i++){
                if(compararProfessor(arrayOrdenado[i], buscar)==0){
                    aux=i;
                    break;
                }
                if(compararProfessor(arrayOrdenado[i],buscar)==1){
                    break;
                }
            }
            if(aux == -1) throw QString ("O dado inserido não consta na lista.");
            return arrayOrdenado[aux];
}
Professor TemplateBusca::buscaBinaria(QString entrada)
{
            int tamanho = array.size();

            std::vector<Professor> arrayOrdenado = Ordenar->arraySelectionSort();

            if (tamanho == 0) throw QString("O vetor nao foi iniciado.");
            int low = 0, high = tamanho -1;
            while (low<= high){
                int mid = (low + high) / 2;
                if (this->compararProfessor(arrayOrdenado[mid], entrada) == 0) return arrayOrdenado[mid];
                if (this->compararProfessor(arrayOrdenado[mid], entrada) == -1) low = mid + 1;
                else high = mid - 1;
            }
            throw QString("O dado inserido nao consta na lista.");
}

