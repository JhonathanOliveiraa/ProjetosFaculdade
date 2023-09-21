#ifndef ORDENARDEPARTAMENTONOME_H
#define ORDENARDEPARTAMENTONOME_H
#include <QString>
#include <templateordenacao.h>

namespace jhone{
class OrdenarDepartamentoNome : public TemplateOrdenacao
{
private:
public:
    OrdenarDepartamentoNome();
    bool compararProfessor(Professor p1, Professor p2);

};
}

#endif // ORDENARDEPARTAMENTONOME_H
