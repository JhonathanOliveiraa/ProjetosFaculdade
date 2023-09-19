#include "ordenardepartamento.h"

OrdenarDepartamento::OrdenarDepartamento()
{

}
bool OrdenarDepartamento::compararProfessor(Professor p1, Professor p2)
{
    if(p1.getDepartamento().compare(p2.getDepartamento()) > 0) return true;
    if(p1.getDepartamento().compare(p2.getDepartamento()) < 0) return false;
    if(p1.getTitulacao().compare(p2.getTitulacao()) > 0) return true;
    if(p1.getTitulacao().compare(p2.getTitulacao()) < 0) return false;
    if(p1.getNome().compare(p2.getNome()) > 0) return true;
    return false;
}


