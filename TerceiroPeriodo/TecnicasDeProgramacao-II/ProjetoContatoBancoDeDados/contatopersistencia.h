#ifndef CONTATOPERSISTENCIA_H
#define CONTATOPERSISTENCIA_H
#include <ICrudContato.h>
#include <contato.h>
#include <fstream>
#include <QStringList>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
namespace jhone{
class ContatoPersistencia: public IContatoCRUD
{
private:
    QString nomeDoBancoDeDados;
    QSqlDatabase bd;
public:
    ContatoPersistencia();
    void incluir (const Contato &objContato) ;
    Contato *consultar(QString &cpf);
    std::list<Contato> *getListaDeContatos() ;
    void excluir(QString cpf);
    void alterar(const Contato &objContato);
};
}
#endif // CONTATOPERSISTENCIA_H
