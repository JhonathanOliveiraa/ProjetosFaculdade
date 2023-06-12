#ifndef TV_H
#define TV_H
#include <QString>
#include <produto.h>

namespace Jhone{


class TV : public Produto
{
private:
    QString modelo;
    QString marca;
    QString sistemaOperacional;
    QString tamanhoTela;
public:
    TV();
    TV(int preco,int codigo, QString modelo, QString marca, QString sistemaOperacional, QString tamanhoTela);
    QString getModelo() const;
    QString getMarca() const;
    QString getSistemaOperacional() const;
    QString getTamanhoTela() const;
    void setModelo(const QString &newModelo);
    void setMarca(const QString &newMarca);
    void setSistemaOperacional(const QString &newSistemaOperacional);
    void setTamanhoTela(const QString &newTamanhoTela);
    QString obterDescricaoCompleta();
    QString obterPrecoVenda();
    QString obterTipoProduto();
};
}
#endif // TV_H
