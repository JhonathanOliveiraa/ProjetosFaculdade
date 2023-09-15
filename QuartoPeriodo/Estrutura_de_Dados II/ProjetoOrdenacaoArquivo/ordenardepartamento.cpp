#include "ordenardepartamento.h"

OrdenarDepartamento::OrdenarDepartamento()
{

}
bool OrdenarDepartamento::compararProfessor(Professor p1, Professor p2)
{
    if(p1.getDepartamento().compare(p2.getDepartamento()) > 0) return true;
    if(p1.getDepartamento().compare(p2.getDepartamento()) == 0){
        teste.compararProfessor(p1,p2);
    }
    return false;
}

