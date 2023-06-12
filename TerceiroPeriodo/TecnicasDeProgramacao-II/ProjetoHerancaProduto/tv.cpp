#include "tv.h"
namespace Jhone{

TV::TV():
    Produto(),
    modelo(),
    marca(),
    sistemaOperacional(),
    tamanhoTela()
{
}
TV::TV(int preco, int codigo, QString modelo, QString marca, QString sistemaOperacional, QString tamanhoTela):
    Produto(preco,codigo),
    modelo(modelo),
    marca(marca),
    sistemaOperacional(sistemaOperacional),
    tamanhoTela(tamanhoTela)
{
}
QString TV::getModelo() const
{
    return modelo;
}

QString TV::getMarca() const
{
    return marca;
}

QString TV::getSistemaOperacional() const
{
    return sistemaOperacional;
}

QString TV::getTamanhoTela() const
{
    return tamanhoTela;
}

void TV::setModelo(const QString &newModelo)
{
    modelo = newModelo;
}

void TV::setMarca(const QString &newMarca)
{
    marca = newMarca;
}

void TV::setSistemaOperacional(const QString &newSistemaOperacional)
{
    sistemaOperacional = newSistemaOperacional;
}

void TV::setTamanhoTela(const QString &newTamanhoTela)
{
    tamanhoTela = newTamanhoTela;
}
QString TV::obterDescricaoCompleta(){
    QString saida = "Modelo da TV: ";
    saida += modelo;
    saida += "\nMarca da TV: " + marca;
    saida += "\nSistema Operacional da TV: " + sistemaOperacional;
    saida += "\nTamanho da tela da TV: " + tamanhoTela;
    return saida;
}

QString TV::obterTipoProduto(){
    QString saida = "TVs";
    return saida;
}
QString TV::obterPrecoVenda(){
    return (QString::number(preco));
}
}
