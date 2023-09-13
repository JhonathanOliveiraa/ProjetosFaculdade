#ifndef ORDENARDEPARTAMENTO_H
#define ORDENARDEPARTAMENTO_H
#include <templateordenacao.h>


class OrdenarDepartamento : public TemplateOrdenacao
{
public:
    OrdenarDepartamento();
    bool compararProfessor(Professor p1, Professor p2);

};

#endif // ORDENARDEPARTAMENTO_H
