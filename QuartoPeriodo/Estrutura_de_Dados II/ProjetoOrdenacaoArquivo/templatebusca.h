#ifndef TEMPLATEBUSCA_H
#define TEMPLATEBUSCA_H
#include <professor.h>
#include <templateordenacao.h>
#include <QString>
namespace jhone {

class TemplateBusca
{
private:
    std::vector<Professor> array;
public:
    TemplateBusca(std::vector <Professor> busca);
    virtual int compararProfessorBusca(Professor p1, QString teste)=0;
    virtual std::vector<Professor> ordenar()=0;
    Professor buscaSequencialMelhorada(QString buscar);
    Professor buscaBinaria(QString buscar);
};
}
#endif // TEMPLATEBUSCA_H
