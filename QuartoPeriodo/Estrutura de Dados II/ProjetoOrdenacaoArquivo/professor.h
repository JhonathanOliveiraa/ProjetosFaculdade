#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <QString>

class Professor
{
private:
    QString nome;
    QString matricula;
    QString departamento;
    QString titulacao;
    QString tipoDeContrato;
public:
    Professor();
    const QString &getNome() const;
    const QString &getMatricula() const;
    const QString &getDepartamento() const;
    const QString &getTitulacao() const;
    const QString &getTipoDeContrato() const;
    void setNome(const QString &newNome);
    void setMatricula(const QString &newMatricula);
    void setDepartamento(const QString &newDepartamento);
    void setTitulacao(const QString &newTitulacao);
    void setTipoDeContrato(const QString &newTipoDeContrato);
};

#endif // PROFESSOR_H
