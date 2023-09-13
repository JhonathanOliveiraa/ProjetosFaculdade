#ifndef ORDENARTITULACAO_H
#define ORDENARTITULACAO_H
#include <templateordenacao.h>


class OrdenarTitulacao : public TemplateOrdenacao
{
public:
    OrdenarTitulacao();
    bool compararProfessor(Professor p1, Professor p2);
};

#endif // ORDENARTITULACAO_H
