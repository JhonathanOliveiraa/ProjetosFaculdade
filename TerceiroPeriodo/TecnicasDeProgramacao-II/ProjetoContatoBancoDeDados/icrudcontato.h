#ifndef ICRUDCONTATO_H
#define ICRUDCONTATO_H
#include <QString>
#include <list>
#include <contato.h>
namespace  jhone{
class IContatoCRUD{
public:
    virtual void incluir (const Contato &objContato) = 0;
    virtual std::list<Contato> *getListaDeContatos()  = 0;
    virtual  Contato *consultar (QString &cpf) = 0;
    virtual void alterar(const Contato &objContato)  = 0;
    virtual void excluir(QString cpf) = 0;
    // REGRAS DE NEGÓCIO:
    //não é permitido incluir na agenda ninguém que, tenha o mesmo cpf(cpf precisa ser válido e único), não preencha o nome completo ou não preencha o email (o email tem que ser válido), não preencher telefone ou não preencher de forma completa
};
}
#endif // ICRUDCONTATO_H
