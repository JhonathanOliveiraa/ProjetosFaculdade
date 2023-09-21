#include "ordenardepartamentotipocontratonome.h"
namespace jhone{

OrdenarDepartamentoTipoContratoNome::OrdenarDepartamentoTipoContratoNome()
{

}
bool OrdenarDepartamentoTipoContratoNome::compararProfessor(Professor p1, Professor p2){
    if(p1.getDepartamento().compare(p2.getDepartamento()) > 0) return true;
    if(p1.getDepartamento().compare(p2.getDepartamento()) < 0) return false;
    if(p1.getTipoDeContrato().compare(p2.getTipoDeContrato()) > 0) return true;
    if(p1.getTipoDeContrato().compare(p2.getTipoDeContrato()) < 0) return false;
    if(p1.getNome().compare(p2.getNome()) > 0) return true;
    return false;
}
}
