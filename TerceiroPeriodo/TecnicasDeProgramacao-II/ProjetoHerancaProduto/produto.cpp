#include "produto.h"
namespace Jhone{
Produto::Produto():
    codigo()
{
}
Produto::Produto(int codigo):
    codigo(0)
{
    if(codigo<0) throw QString ("O código não deve ser negativo");
}
int Produto::getCodigo() const
{
    return codigo;
}
void Produto::setCodigo(int newCodigo)
{
    codigo = newCodigo;
}
int Produto::getPreco() const
{
    return preco;
}

void Produto::setPreco(int newPreco)
{
    preco = newPreco;
}
}
