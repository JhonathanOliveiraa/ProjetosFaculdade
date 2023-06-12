#include "aluno.h"

Aluno::Aluno(const QString linhaQt)
{
    QStringList lista = linhaQt.split(';');
    if(lista.size() != 3)
        throw QString ("Formato inválido.");
            matricula = lista[0];
    nome = lista[1];
    try
    {
        setCurso(lista[0]);
        setDisciplinaTurma(lista[2]);
    }
    catch(QString &erro)
    {
        throw erro;
    }
}

QString Aluno::getNome() const
{
    return nome;
}

void Aluno::setNome(const QString &newNome)
{
    nome = newNome;
}

int Aluno::getCurso() const
{
    return curso;
}

void Aluno::setCurso(const QString &matricula)
{
    QStringList curso = matricula.split('.');

    if(curso.size() != 4)
        throw QString ("Matricula inválida.");

            this->curso=curso[2].toInt();
}

//int Aluno::getDisciplinaCursoTamanho()
//{
//    return disciplinaTurma.size();
//}

void Aluno::setDisciplinaTurma(QString disciplinas)
{
    QStringList listaDisciplinas = disciplinas.split("  ");
    for (auto disciplina = listaDisciplinas.begin(); disciplina != listaDisciplinas.end(); disciplina++)
    {
        try
        {
            DisciplinaTurma* objetoDisciplina = new DisciplinaTurma();
            objetoDisciplina->setDisciplinaTurma(*disciplina);
            disciplinaTurma.push_back(objetoDisciplina);
        }
        catch (const QString& exception)
        {
            throw QString("Erro ao adicionar disciplina a lista do objeto Aluno: ") + exception;
        }
    }
}

QString Aluno::getMatricula() const
{
    return matricula;
}

void Aluno::setMatricula(const QString &newMatricula)
{
    matricula = newMatricula;
}

bool Aluno::verificaCurso(int curso)
{
    return this->curso == curso;
}

bool Aluno::verificaDisciplinaTurma(QString verificar)
{
    for(auto it=disciplinaTurma.begin(); it!=disciplinaTurma.end(); it++)
    {
        if((*it)->getTurma() == verificar)
        {
            return true;
        }
    }
    return false;
}

bool Aluno::verificaDisciplina(QString disciplina)
{
    for(auto it = disciplinaTurma.begin(); it != disciplinaTurma.end(); it++)
    {
        if(disciplina == (*it)->getDisciplina())
        {
            return true;
        }
    }
    return false;
}

bool Aluno::verificaAluno(QString matricula)
{
    if(this->matricula == matricula)
        return true;
    return false;
}

QString Aluno::getTodasDisciplinas()
{
    QString saida = getMatricula() + "  " + getNome() + ":\n";
    for(auto it = disciplinaTurma.begin(); it != disciplinaTurma.end(); it++)
    {
        saida += (*it)->getTurma() + "\n";
    }
    return saida;
}


