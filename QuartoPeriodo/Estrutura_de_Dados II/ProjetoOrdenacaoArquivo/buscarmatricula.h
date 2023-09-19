#ifndef BUSCARMATRICULA_H
#define BUSCARMATRICULA_H
#include <vector>
#include <professor.h>
#include <templatebusca.h>
#include <ordenarmatricula.h>
class BuscarMatricula : TemplateBusca
{
private:
    std::vector<Professor> array;
public:
    BuscarMatricula(std::vector<Professor> busca);
    virtual int compararProfessor(Professor p1, QString teste);
    std::vector<Professor> ordenar();
};

#endif // BUSCARMATRICULA_H
