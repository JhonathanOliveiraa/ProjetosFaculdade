#include "tratamentodearquivos.h"


TratamentoDeArquivos::TratamentoDeArquivos():
    nomeDoArquivo("C:/Users/jhone/OneDrive/Documentos/GitHub/ProjetosFaculdade/QuartoPeriodo/Estrutura de Dados II/ProjetoOrdenacaoArquivo/Arquivos/DocentesEscolaBD_TESTE_V1.csv"),
    arquivoErro("logErro.txt")
{

}
void TratamentoDeArquivos::buscarArquivos()
{
    try {
        Professor p;
        std::ifstream arquivo;
        arquivo.open(nomeDoArquivo.toStdString().c_str());
        if(nomeDoArquivo.isEmpty()) throw QString("Arquivo nao foi selecionado");
        if(!arquivo.is_open()){
            throw QString("ERRO Arquivo nao pode ser aberto");
        }
        std::string linha;
        while(getline(arquivo, linha)){
            QString texto = QString::fromStdString(linha);
            QStringList textoList = texto.split(';');
            if(textoList.length()!=5 || textoList[1]==" " || textoList[4].isEmpty() || textoList[3] == " " ) {
                arquivoErro<<linha<<std::endl;
                continue;
            }
            p.setMatricula(textoList[0]);
            p.setNome(textoList[1]);
            p.setDepartamento(textoList[2]);
            p.setTitulacao(textoList[3]);
            p.setTipoDeContrato(textoList[4]);
            array.push_back(p);
        }
    }
    catch (QString &erro) {
        throw erro;
    }
}

std::vector<Professor> TratamentoDeArquivos::getArray() const
{
    return array;
}
