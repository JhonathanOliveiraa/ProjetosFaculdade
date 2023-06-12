#ifndef FILTRAR_H
#define FILTRAR_H
#include "aluno.h"
#include <QString>

class Filtrar
{
public:
    static QString filtrarPorCurso(const std::list<Aluno*> &, int);

    static QString filtrarPorDisciplina(const std::list<Aluno*> &, QString);

    static QString filtrarPorDisciplinaTurma(const std::list<Aluno*> &, QString);

    static QString filtrarAluno(const std::list<Aluno*> &, QString);

    //static QString filtrarPorTurma(const std::list<Aluno*> &, QString);
};

#endif // FILTRAR_H
