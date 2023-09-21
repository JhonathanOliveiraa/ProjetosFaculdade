#include "buscarmatricula.h"
namespace jhone{
BuscarMatricula::BuscarMatricula(std::vector<Professor> busca):
    TemplateBusca(busca)
{
    this->array = busca;
}

int BuscarMatricula::compararProfessorBusca(Professor p1, QString busca){
    int aux;
    if(p1.getMatricula().toInt() < busca.toInt())aux=-1;
    else if(p1.getMatricula().toInt() == busca.toInt()) aux =0;
    else aux = 1;
    return aux;
}
std::vector<Professor> BuscarMatricula::ordenar(){
    std::vector<Professor> saida;
    OrdenarMatricula objeto;
    saida = objeto.arraySelectionSort();
    return saida;
}
}
