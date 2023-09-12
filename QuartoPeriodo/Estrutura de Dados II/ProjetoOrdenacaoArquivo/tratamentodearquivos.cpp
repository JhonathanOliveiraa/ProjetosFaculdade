#include "tratamentodearquivos.h"


TratamentoDeArquivos::TratamentoDeArquivos():
    nomeDoArquivo("C:/Users/jhone/OneDrive/Documentos/GitHub/ProjetosFaculdade/QuartoPeriodo/Estrutura de Dados II/ProjetoOrdenacaoArquivo/Arquivos/DocentesEscolaBD_TESTE_V1.csv"),
    logErro("logErro.txt")
{

}

void TratamentoDeArquivos::buscarArquivos()
{
    {
        try {
            std::ifstream arquivo;
            arquivo.open(nomeDoArquivo.toStdString().c_str());
            if(nomeDoArquivo.isEmpty()) throw QString("Arquivo nao foi selecionado");
            if(!arquivo.is_open()){
                throw QString("ERRO Arquivo nao pode ser aberto");
            }
            std::string linha;
            while(!arquivo.eof()){
                getline(arquivo,linha);
                QString texto = QString::fromStdString(linha);
                QStringList textoList = texto.split(';');
                if(textoList.length()!=5) {
                    std::ofstream arquivoErro;
                    arquivoErro.open(logErro.toStdString().c_str());
                    arquivoErro<<texto.toStdString();
                    arquivoErro.close();
                    continue;
                }
                Professor p;
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


}
std::vector<Professor> TratamentoDeArquivos::getArray() const
{
    return array;
}
