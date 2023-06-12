#ifndef PRODUTO_H
#define PRODUTO_H
#include <QString>

namespace Jhone{
class Produto
{
protected:
    int codigo;
    int preco;
public:
    Produto();
    Produto(int codigo);
    virtual QString obterDescricaoCompleta()=0;
    virtual QString obterPrecoVenda()=0;
    virtual QString obterTipoProduto()=0;
    int getCodigo() const;
    void setCodigo(int newCodigo);
    int getPreco() const;
    void setPreco(int newPreco);
};
}
#endif // PRODUTO_H
