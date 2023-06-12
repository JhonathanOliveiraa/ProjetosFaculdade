#ifndef LIVRO_H
#define LIVRO_H
#include <QString>
#include <produto.h>

namespace Jhone{
class Livro : public Produto
{
private:
    QString titulo;
    QString autor;
    QString tradutor;
    QString editora;
    int anoPublicacao;
public:
    Livro();
    Livro(int preco, int codigo, QString titulo, QString autor, QString tradutor, QString editora, int anoPublicacao);
    QString getTitulo() const;
    QString getAutor() const;
    QString getTradutor() const;
    QString getEditora() const;
    int getAnoPublicacao() const;
    void setTitulo(const QString &newTitulo);
    void setAutor(const QString &newAutor);
    void setTradutor(const QString &newTradutor);
    void setEditora(const QString &newEditora);
    void setAnoPublicacao(int newAnoPublicacao);
    QString obterDescricaoCompleta();
    QString obterPrecoVenda();
    QString obterTipoProduto();
};
}
#endif // LIVRO_H
