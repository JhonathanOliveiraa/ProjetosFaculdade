#include "ordenarmatricula.h"

OrdenarMatricula::OrdenarMatricula()
{

}
bool OrdenarMatricula::compararProfessor(Professor p1, Professor p2)
{
    if(p1.getMatricula().toInt() > (p2.getMatricula().toInt())) return true;
    else return false;
}
