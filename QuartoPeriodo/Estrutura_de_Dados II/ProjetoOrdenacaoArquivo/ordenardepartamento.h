#ifndef ORDENARDEPARTAMENTO_H
#define ORDENARDEPARTAMENTO_H
#include <templateordenacao.h>
#include <ordenartitulacao.h>
namespace jhone {

class OrdenarDepartamento : public TemplateOrdenacao
{
private:
    OrdenarTitulacao teste;
public:
    OrdenarDepartamento();
    bool compararProfessor(Professor p1, Professor p2);

};
}
#endif // ORDENARDEPARTAMENTO_H
