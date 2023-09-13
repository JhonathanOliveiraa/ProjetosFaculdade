#include "ordenarmatricula.h"

OrdenarMatricula::OrdenarMatricula()
{

}
bool OrdenarMatricula::compararProfessor(Professor p1, Professor p2)
{
    if(p1.getMatricula() < (p2.getMatricula())) return true;
    else return false;
}
