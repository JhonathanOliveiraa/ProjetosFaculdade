#ifndef BUSCARNOME_H
#define BUSCARNOME_H
#include <templatebusca.h>
#include <vector>
#include <templateordenacao.h>
#include <professor.h>
#include <ordenarnome.h>
class BuscarNome : public TemplateBusca
{
private:
    std::vector<Professor> array;
public:
    BuscarNome(std::vector<Professor> busca);
    virtual int compararProfessor(Professor p1, QString teste);
    std::vector<Professor> ordenar();
};

#endif // BUSCARNOME_H
