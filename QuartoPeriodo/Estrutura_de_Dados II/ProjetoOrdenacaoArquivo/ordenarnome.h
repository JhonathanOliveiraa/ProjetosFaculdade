#ifndef ORDENARNOME_H
#define ORDENARNOME_H
#include <templateordenacao.h>
namespace jhone {

class OrdenarNome : public TemplateOrdenacao
{
private:
public:
    OrdenarNome();
    bool compararProfessor(Professor p1, Professor p2);
};
}
#endif // ORDENARNOME_H
