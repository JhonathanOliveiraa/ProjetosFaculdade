#ifndef ORDENARMATRICULA_H
#define ORDENARMATRICULA_H
#include <templateordenacao.h>

namespace jhone {

class OrdenarMatricula : public TemplateOrdenacao
{
public:
    OrdenarMatricula();
    bool compararProfessor(Professor p1, Professor p2);

};
}
#endif // ORDENARMATRICULA_H
