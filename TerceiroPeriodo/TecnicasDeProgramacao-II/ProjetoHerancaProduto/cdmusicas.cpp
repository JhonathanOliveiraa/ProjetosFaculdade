#include "cdmusicas.h"
namespace Jhone{

CDMusicas::CDMusicas():
    Produto(),
    nomeAlbum(),
    banda(),
    cantor(),
    genero()
{
}
CDMusicas::CDMusicas(int preco, int codigo, QString nomeAlbum, QString banda, QString cantor, QString genero):
    Produto(preco,codigo),
    nomeAlbum(nomeAlbum),
    banda(banda),
    cantor(cantor),
    genero(genero)
{
}

QString CDMusicas::getNomeAlbum() const
{
    return nomeAlbum;
}

QString CDMusicas::getBanda() const
{
    return banda;
}

QString CDMusicas::getCantor() const
{
    return cantor;
}

QString CDMusicas::getGenero() const
{
    return genero;
}

void CDMusicas::setNomeAlbum(const QString &newNomeAlbum)
{
    nomeAlbum = newNomeAlbum;
}

void CDMusicas::setBanda(const QString &newBanda)
{
    banda = newBanda;
}

void CDMusicas::setCantor(const QString &newCantor)
{
    cantor = newCantor;
}

void CDMusicas::setGenero(const QString &newGenero)
{
    genero = newGenero;
}
QString CDMusicas::obterDescricaoCompleta(){
    QString saida = "Nome do álbum: ";
    saida += nomeAlbum;
    saida += "\nNome da banda: " + banda;
    saida += "\nNome do cantor: " + cantor;
    saida += "\nGênero músical: " + genero;
    return saida;
}
QString CDMusicas::obterTipoProduto(){
    QString saida = "CDs Musicais";
    return saida;
}
QString CDMusicas::obterPrecoVenda(){
    return (QString::number(preco));
}

}
