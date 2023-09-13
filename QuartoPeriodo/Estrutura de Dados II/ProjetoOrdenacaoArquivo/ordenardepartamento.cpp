#include "ordenardepartamento.h"

OrdenarDepartamento::OrdenarDepartamento()
{

}
bool OrdenarDepartamento::compararProfessor(Professor p1, Professor p2)
{
    if(p1.getDepartamento().compare(p2.getDepartamento()) <= 0) return true;
    else return false;
}
