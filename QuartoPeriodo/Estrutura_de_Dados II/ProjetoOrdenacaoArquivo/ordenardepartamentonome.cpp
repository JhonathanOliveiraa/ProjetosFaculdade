#include "ordenardepartamentonome.h"
namespace jhone{
OrdenarDepartamentoNome::OrdenarDepartamentoNome()
{

}
bool OrdenarDepartamentoNome::compararProfessor(Professor p1, Professor p2)
{
    if(p1.getDepartamento().compare(p2.getDepartamento()) > 0) return true;
    if(p1.getDepartamento().compare(p2.getDepartamento())==0){
        if(p1.getNome().compare(p2.getNome()) >= 0) return true;
    }
    return false;

}
}
