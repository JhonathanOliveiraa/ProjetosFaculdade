#include "buscarnome.h"

BuscarNome::BuscarNome(std::vector<Professor> busca):
    TemplateBusca(busca)
{
    this->array = busca;
}

int BuscarNome::compararProfessor(Professor p1, QString teste){
    int aux;
    if(p1.getNome() < teste)aux=-1;
    else if(p1.getNome() == teste) aux =0;
    else aux =1;
    return aux;
}
std::vector<Professor> BuscarNome::ordenar(){
    std::vector<Professor> saida;
    OrdenarNome objeto;
    saida = objeto.arraySelectionSort();
    return saida;
}
