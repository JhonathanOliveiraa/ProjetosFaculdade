#ifndef CONTATOCONTROLE_H
#define CONTATOCONTROLE_H
#include <ICrudContato.h>
#include <QString>
#include <contato.h>
#include <contatopersistencia.h>
namespace jhone {

class ContatoControle : public IContatoCRUD
{
private:
    jhone::IContatoCRUD *contatoPersistencia;
    void verificarRegrasIncluir(const Contato &objContato) const;
    void verificarCPF(const Contato &objContato) const;
public:
    ContatoControle();
    void incluir (const Contato &objContato) ;
    std::list<Contato> *getListaDeContatos() ;
    Contato *consultar (QString &cpf) ;
    void alterar(const Contato &objContato) ;
    void excluir(QString cpf) ;
    void criarArquivo()const;
};
}
#endif // CONTATOCONTROLE_H
