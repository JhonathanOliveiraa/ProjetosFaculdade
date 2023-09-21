#ifndef BUSCARNOME_H
#define BUSCARNOME_H
#include <templatebusca.h>
#include <vector>
#include <professor.h>
#include <ordenarnome.h>
namespace jhone {
class BuscarNome : public TemplateBusca
{
private:
    std::vector<Professor> array;
public:
    BuscarNome(std::vector<Professor> busca);
    int compararProfessorBusca(Professor p1, QString busca);
    std::vector<Professor> ordenar();
};
}
#endif // BUSCARNOME_H
