#include "ordenartitulacao.h"

OrdenarTitulacao::OrdenarTitulacao()
{

}
bool OrdenarTitulacao::compararProfessor(Professor p1, Professor p2)
{
    if(p1.getTitulacao().compare(p2.getTitulacao()) <= 0) return true;
    else return false;
}
