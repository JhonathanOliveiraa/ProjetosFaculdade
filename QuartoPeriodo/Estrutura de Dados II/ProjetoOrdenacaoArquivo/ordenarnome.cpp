#include "ordenarnome.h"

OrdenarNome::OrdenarNome()
{

}

bool OrdenarNome::compararProfessor(Professor p1, Professor p2)
{
      if(p1.getNome().compare(p2.getNome()) <= 0) return true;
    else return false;
}

