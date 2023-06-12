#ifndef ALUNO_H
#define ALUNO_H
#include "disciplinaturma.h"
#include <QString>
#include <QStringList>
#include <list>


class Aluno
{
private:
    QString matricula;
    int curso;
    QString nome;
    std::list<DisciplinaTurma*>disciplinaTurma;

public:

    Aluno(const QString linhaQt);

    QString getMatricula() const;
    void setMatricula(const QString &newMatricula);

    QString getNome() const;
    void setNome(const QString &newNome);

    int getCurso() const;
    void setCurso(const QString &matricla);

    QString getDisciplinaTurma(int) const;
    void setDisciplinaTurma(QString disciplinas);

    QString getTodasDisciplinas();

    bool verificaAluno(QString);
    bool verificaCurso(int);
    bool verificaDisciplina(QString);
    bool verificaDisciplinaTurma(QString);


};

#endif // ALUNO_H
