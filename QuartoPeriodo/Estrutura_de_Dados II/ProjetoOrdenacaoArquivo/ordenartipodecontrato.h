#ifndef ORDENARTIPODECONTRATO_H
#define ORDENARTIPODECONTRATO_H
#include <templateordenacao.h>

namespace jhone {

class OrdenarTipoDeContrato : public TemplateOrdenacao
{
public:
    OrdenarTipoDeContrato();
    bool compararProfessor(Professor p1, Professor p2);

};
}
#endif // ORDENARTIPODECONTRATO_H
