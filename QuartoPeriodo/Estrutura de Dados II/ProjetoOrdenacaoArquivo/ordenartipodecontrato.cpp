#include "ordenartipodecontrato.h"

OrdenarTipoDeContrato::OrdenarTipoDeContrato()
{

}
bool OrdenarTipoDeContrato::compararProfessor(Professor p1, Professor p2)
{
    if(p1.getTipoDeContrato().compare(p2.getTipoDeContrato()) <= 0) return true;
    else return false;
}
