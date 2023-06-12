#ifndef CDMUSICAS_H
#define CDMUSICAS_H
#include <produto.h>
namespace Jhone{
class CDMusicas : public Produto
{
private:
    QString nomeAlbum;
    QString banda;
    QString cantor;
    QString genero;
public:
    CDMusicas();
    CDMusicas(int preco, int codigo, QString nomeAlbum, QString banda, QString cantor, QString genero);
    QString getNomeAlbum() const;
    QString getBanda() const;
    QString getCantor() const;
    QString getGenero() const;
    void setNomeAlbum(const QString &newNomeAlbum);
    void setBanda(const QString &newBanda);
    void setCantor(const QString &newCantor);
    void setGenero(const QString &newGenero);
    QString obterDescricaoCompleta();
    QString obterPrecoVenda();
    QString obterTipoProduto();
};
}
#endif // CDMUSICAS_H
