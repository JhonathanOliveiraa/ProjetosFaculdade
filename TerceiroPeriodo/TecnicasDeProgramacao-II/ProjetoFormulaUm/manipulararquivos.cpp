#include "manipulararquivos.h"
namespace jhone{
ManipularArquivos::ManipularArquivos(QString nomeDoArquivo):
    nomeDoArquivoNoDisco(nomeDoArquivo)
{
}
const std::vector<Piloto> &ManipularArquivos::getListaDePilotosF1() const
{
    return listaDePilotosF1;
}

void ManipularArquivos::buscarDadosNoArquivo(){
    try {
        // criando um arquivo de entrada
        std::ifstream arquivo;
        // abrindo um arquivo de entrada
        arquivo.open(nomeDoArquivoNoDisco.toStdString().c_str());
        // verificando erro de abertura do arquivo de entrada
        if(!arquivo.is_open()) throw QString("ERRO Arquivo nao pode ser aberto");
        // Lendo dados do arquivo texto
        std::string linha;
        // lendo do arquivo
        getline(arquivo,linha);

        // Teste de fim do arquivo
        while(!arquivo.eof()){
            QString texto= QString::fromStdString(linha);
            QStringList strList = texto.split(';');
            int codigo = strList[0].toInt();
            QString nome = strList[1];
            QString pais = strList[2];
            int idade = strList[3].toInt();
            QString equipe = strList[4];
            QString motor = strList[5];
            int arrayClassificacao[7];
            arrayClassificacao[0] = strList[6].toInt();
            arrayClassificacao[1] = strList[7].toInt();
            arrayClassificacao[2] = strList[8].toInt();
            arrayClassificacao[3] = strList[9].toInt();
            arrayClassificacao[4] = strList[10].toInt();
            arrayClassificacao[5] = strList[11].toInt();
            arrayClassificacao[6] = strList[12].toInt();
            Piloto p(codigo, nome, pais, idade, equipe, motor, arrayClassificacao);
            p.calcularPontuacaoFinal();
            this->listaDePilotosF1.push_back(p);
            getline(arquivo,linha);
        }
        // fechado o arquivo de entrada
        arquivo.close();
        std::sort(listaDePilotosF1.begin(),listaDePilotosF1.end(),[](Piloto A, Piloto B){
            return A.getPontuacaoFinal() > B.getPontuacaoFinal();
        });
}
     catch (QString &erro) {
        throw QString ("ERRO");
    }
}

}
