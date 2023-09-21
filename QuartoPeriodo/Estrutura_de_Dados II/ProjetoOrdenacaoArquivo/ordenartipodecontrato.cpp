#include "ordenartipodecontrato.h"
namespace jhone{

OrdenarTipoDeContrato::OrdenarTipoDeContrato()
{

}
bool OrdenarTipoDeContrato::compararProfessor(Professor p1, Professor p2)
{
    if(p1.getTipoDeContrato().compare(p2.getTipoDeContrato()) > 0) return true;
    if(p1.getTipoDeContrato().compare(p2.getTipoDeContrato())==0){
        if(p1.getNome().compare(p2.getNome()) > 0) return true;
      else return false;
    }
    else return false;
}
}
