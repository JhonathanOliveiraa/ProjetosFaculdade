#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <QString>
namespace jhone {

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
    const QString &getDepartamento() const;
    const QString &getTitulacao() const;
    const QString &getTipoDeContrato() const;
    void setNome(const QString &newNome);
    void setDepartamento(const QString &newDepartamento);
    void setTitulacao(const QString &newTitulacao);
    void setTipoDeContrato(const QString &newTipoDeContrato);
    QString getMatricula() const;
    void setMatricula(const QString &newMatricula);
};
}
#endif // PROFESSOR_H
