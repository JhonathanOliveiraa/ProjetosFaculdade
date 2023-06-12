#include "filtrar.h"

QString Filtrar::filtrarPorCurso(const std::list<Aluno*> &listaAlunos, int curso)
{
    QString saida = "";
    for(auto aluno = listaAlunos.begin(); aluno != listaAlunos.end(); aluno++ )
    {
        if((*aluno)->verificaCurso(curso))
        {
            saida += (*aluno)->getMatricula() + " " + (*aluno)->getNome();
            saida += "\n";
        }
    }
    if(saida == "")
        throw QString ("O curso digitado não consta na base de dados.");
    return saida;
}

QString Filtrar::filtrarPorDisciplina(const std::list<Aluno*> &listaAlunos, QString disciplina)
{
        QString saida="";
        for(auto aluno = listaAlunos.begin(); aluno != listaAlunos.end(); aluno++ )
        {
            if((*aluno)->verificaDisciplina(disciplina))
            {
                saida += (*aluno)->getMatricula() + " " + (*aluno)->getNome();
                saida += "\n";
            }
        }
        if(saida == ""){
            throw QString ("Disciplina digitada não consta na base de dados.");
        }
        return saida;
}

QString Filtrar::filtrarPorDisciplinaTurma(const std::list<Aluno*> &listaAlunos, QString disciplinaTurma)
{
    QString saida="";
    for(auto aluno = listaAlunos.begin(); aluno != listaAlunos.end(); aluno++)
    {
        if((*aluno)->verificaDisciplinaTurma(disciplinaTurma))
        {
            saida += (*aluno)->getMatricula() + " " + (*aluno)->getNome();
            saida += "\n";
        }
    }
    if(saida == "")
        throw QString ("A turma digitada não consta na base de dados.");
    return saida;
}



QString Filtrar::filtrarAluno(const std::list<Aluno*> &listaAlunos, QString matricula)
{
    QString saida="";
    for(auto aluno = listaAlunos.begin(); aluno != listaAlunos.end(); aluno++)
    {
        if((*aluno)->verificaAluno(matricula))
        {
            saida = (*aluno)->getTodasDisciplinas();
            return saida;
            //imprimi um dinosauro legal
        }
    }
    throw QString ("Matrícula não encontrada.");
}













