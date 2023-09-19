#ifndef ORDENARDEPARTAMENTOTIPOCONTRATONOME_H
#define ORDENARDEPARTAMENTOTIPOCONTRATONOME_H
#include <templateordenacao.h>
#include <QString>
class OrdenarDepartamentoTipoContratoNome : public TemplateOrdenacao
{
private:
public:
    OrdenarDepartamentoTipoContratoNome();
    bool compararProfessor(Professor p1, Professor p2);
};

#endif // ORDENARDEPARTAMENTOTIPOCONTRATONOME_H
