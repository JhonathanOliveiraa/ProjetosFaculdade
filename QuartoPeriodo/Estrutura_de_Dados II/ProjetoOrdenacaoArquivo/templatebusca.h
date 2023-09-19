#ifndef TEMPLATEBUSCA_H
#define TEMPLATEBUSCA_H
#include <professor.h>
#include <templateordenacao.h>
#include <QString>
class TemplateBusca
{
private:
    TemplateOrdenacao *Ordenar;
    std::vector<Professor> array;
public:
    TemplateBusca(std::vector <Professor> busca);
    virtual int compararProfessor(Professor p1, QString teste)=0;
    Professor buscaSequencialMelhorada(QString buscar);
    Professor buscaBinaria(QString buscar);
};

#endif // TEMPLATEBUSCA_H
