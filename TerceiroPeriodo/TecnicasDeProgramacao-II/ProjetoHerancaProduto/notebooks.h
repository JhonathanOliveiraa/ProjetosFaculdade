#ifndef NOTEBOOKS_H
#define NOTEBOOKS_H
#include <QString>
#include <produto.h>

namespace Jhone{


class Notebooks : public Produto
{
private:
    QString marca;
    QString modelo;
    QString memoriaRAM;
    QString capacidadeHD;
    QString processador;
    QString tamanhoTela;
    QString sistemaOperacional;
public:
    Notebooks();
    Notebooks(int preco,int codigo, QString marca, QString modelo, QString memoriaRAM, QString capacidadeHD, QString processador, QString tamanhoTela, QString sistemaOperacional);
    QString getMarca() const;
    QString getModelo() const;
    QString getMemoriaRAM() const;
    QString getCapacidadeHD() const;
    QString getProcessador() const;
    QString getTamanhoTela() const;
    QString getSistemaOperacional() const;
    void setMarca(const QString &newMarca);
    void setModelo(const QString &newModelo);
    void setMemoriaRAM(const QString &newMemoriaRAM);
    void setCapacidadeHD(const QString &newCapacidadeHD);
    void setProcessador(const QString &newProcessador);
    void setTamanhoTela(const QString &newTamanhoTela);
    void setSistemaOperacional(const QString &newSistemaOperacional);
    QString obterDescricaoCompleta();
    QString obterPrecoVenda();
    QString obterTipoProduto();
};
}
#endif // NOTEBOOKS_H
