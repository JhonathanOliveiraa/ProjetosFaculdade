#include "notebooks.h"
namespace Jhone{
Notebooks::Notebooks():
    Produto(),
    marca(),
    modelo(),
    memoriaRAM(),
    capcidadeHD(),
    processador(),
    tamanhoTela(),
    sistemaOperacional()
{
}
Notebooks::Notebooks(int preco, int codigo, QString marca, QString modelo, QString memoriaRAM, QString capacidadeHD, QString processador, QString tamanhoTela, QString sistemaOperacional):
    Produto(preco,codigo),
    marca(marca),
    modelo(modelo),
    memoriaRAM(memoriaRAM),
    capacidadeHD(capacidadeHD),
    processador(processador),
    tamanhoTela(tamanhoTela),
    sistemaOperacional(sistemaOperacional)
{
}

QString Notebooks::getMarca() const
{
    return marca;
}

QString Notebooks::getModelo() const
{
    return modelo;
}

QString Notebooks::getMemoriaRAM() const
{
    return memoriaRAM;
}

QString Notebooks::getCapacidadeHD() const
{
    return capacidadeHD;
}

QString Notebooks::getProcessador() const
{
    return processador;
}

QString Notebooks::getTamanhoTela() const
{
    return tamanhoTela;
}

QString Notebooks::getSistemaOperacional() const
{
    return sistemaOperacional;
}

void Notebooks::setMarca(const QString &newMarca)
{
    marca = newMarca;
}

void Notebooks::setModelo(const QString &newModelo)
{
    modelo = newModelo;
}

void Notebooks::setMemoriaRAM(const QString &newMemoriaRAM)
{
    memoriaRAM = newMemoriaRAM;
}

void Notebooks::setCapacidadeHD(const QString &newCapacidadeHD)
{
    capacidadeHD = newCapacidadeHD;
}

void Notebooks::setProcessador(const QString &newProcessador)
{
    processador = newProcessador;
}

void Notebooks::setTamanhoTela(const QString &newTamanhoTela)
{
    tamanhoTela = newTamanhoTela;
}

void Notebooks::setSistemaOperacional(const QString &newSistemaOperacional)
{
    sistemaOperacional = newSistemaOperacional;
}
QString Notebooks::obterDescricaoCompleta(){
    QString saida = "Marca do notebook: ";
    saida += marca;
    saida += "\nModelo do notebook: " + modelo;
    return saida;
}

QString Notebooks::obterTipoProduto(){
    QString saida = "Notebook";
    return saida;
}
QString Notebooks::obterPrecoVenda(){
    return (QString::number(preco));
}
}
