#ifndef BUSCARMATRICULA_H
#define BUSCARMATRICULA_H
#include <vector>
#include <professor.h>
#include <templatebusca.h>
#include <ordenarmatricula.h>
namespace jhone {
class BuscarMatricula : public TemplateBusca
{
private:
    std::vector<Professor> array;
public:
    BuscarMatricula(std::vector<Professor> busca);
    int compararProfessorBusca(Professor p1, QString busca);
    std::vector<Professor> ordenar();
};
}

#endif // BUSCARMATRICULA_H
