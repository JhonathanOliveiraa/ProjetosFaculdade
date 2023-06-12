#ifndef MANIPULARARQUIVOS_H
#define MANIPULARARQUIVOS_H
#include <QString>
#include <fstream>
#include <QStringList>
#include <piloto.h>
#include <vector>
namespace jhone{
class ManipularArquivos
{
private:
    QString nomeDoArquivoNoDisco;
    std::vector<Piloto> listaDePilotosF1;

public:
    ManipularArquivos(QString nomeDoArquivo);
    void buscarDadosNoArquivo();
    const std::vector<Piloto> &getListaDePilotosF1() const;
};
}
#endif // MANIPULARARQUIVOS_H
