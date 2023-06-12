#include "livro.h"
namespace Jhone{
Livro::Livro():
    Produto(),
    titulo(),
    autor(),
    tradutor(),
    editora(),
    anoPublicacao()
{
}
Livro::Livro(int preco, int codigo, QString titulo, QString autor, QString tradutor, QString editora, int anoPublicacao):
    Produto(preco,codigo),
    titulo(titulo),
    autor(autor),
    tradutor(tradutor),
    editora(editora),
    anoPublicacao(0)
{
    if(anoPublicacao<=0) throw QString ("Ano de publicação incorreto");
}
void Livro::setTitulo(const QString &newTitulo)
{
    titulo = newTitulo;
}

void Livro::setAutor(const QString &newAutor)
{
    autor = newAutor;
}

void Livro::setTradutor(const QString &newTradutor)
{
    tradutor = newTradutor;
}

void Livro::setEditora(const QString &newEditora)
{
    editora = newEditora;
}

void Livro::setAnoPublicacao(int newAnoPublicacao)
{
    anoPublicacao = newAnoPublicacao;
}

QString Livro::getTitulo() const
{
    return titulo;
}

QString Livro::getAutor() const
{
    return autor;
}

QString Livro::getTradutor() const
{
    return tradutor;
}

QString Livro::getEditora() const
{
    return editora;
}

int Livro::getAnoPublicacao() const
{
    return anoPublicacao;
}
QString Livro::obterDescricaoCompleta(){
    QString saida = "Título da obra: ";
    saida += titulo;
    saida += "\nAutor da obra: " + autor;
    saida += "\nTradutor da obra: " + tradutor;
    saida += "\nEditora da obra: " + editora;
    saida += "\nAno da publicação: " + QString::number(anoPublicacao);
    return saida;
}
QString Livro::obterTipoProduto(){
    QString saida = "Livro";
    return saida;
}
QString Livro::obterPrecoVenda(){
    return (QString::number(preco));
}

}
