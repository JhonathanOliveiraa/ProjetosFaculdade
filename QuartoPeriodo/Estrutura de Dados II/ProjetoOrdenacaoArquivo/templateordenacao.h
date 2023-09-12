#ifndef TEMPLATEORDENACAO_H
#define TEMPLATEORDENACAO_H
#include <professor.h>
#include <QString>

class TemplateOrdenacao
{
private:

public:
    TemplateOrdenacao();
    virtual bool compararProfessor(Professor p1, Professor p2)=0;
};

#endif // TEMPLATEORDENACAO_H
