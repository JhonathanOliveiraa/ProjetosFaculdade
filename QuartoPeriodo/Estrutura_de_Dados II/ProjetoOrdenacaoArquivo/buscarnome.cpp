#include "buscarnome.h"
namespace jhone{

BuscarNome::BuscarNome(std::vector<Professor> busca):
    TemplateBusca(busca)
{
    this->array = busca;
}

int BuscarNome::compararProfessorBusca(Professor p1, QString busca){
    int aux;
    if(p1.getNome() < busca)aux=-1;
    else if(p1.getNome() == busca) aux =0;
    else aux =1;
    return aux;
}
std::vector<Professor> BuscarNome::ordenar(){
    std::vector<Professor> saida;
    OrdenarNome objeto;
    saida = objeto.arraySelectionSort();
    return saida;
}

}
