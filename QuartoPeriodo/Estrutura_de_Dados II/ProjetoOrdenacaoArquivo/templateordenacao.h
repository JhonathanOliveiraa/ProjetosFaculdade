#ifndef TEMPLATEORDENACAO_H
#define TEMPLATEORDENACAO_H
#include <professor.h>
#include <QString>
#include <tratamentodearquivos.h>
#include <vector>
namespace jhone {

class TemplateOrdenacao
{
protected:
    TratamentoDeArquivos obj;
    std::vector<Professor> array;
public:
    TemplateOrdenacao();
    std::vector<Professor> arraySelectionSort();
    virtual bool compararProfessor(Professor p1, Professor p2)=0;
};
}
#endif // TEMPLATEORDENACAO_H
