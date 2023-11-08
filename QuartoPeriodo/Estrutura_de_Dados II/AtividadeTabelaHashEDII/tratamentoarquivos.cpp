#include "tratamentoarquivos.h"

TratamentoArquivos::TratamentoArquivos():
    nomeDoArquivo("C:/Users/jhone/Documents/DadosDosAlunos_Matricula_Nome.csv"),
    array()
{

}

Pessoa *TratamentoArquivos::getVetor()
{
    return array;
}

void TratamentoArquivos::buscarArquivo()
{
    try {
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
            int matricula = textoList[0].toInt();
            array[matricula].setMatricula(textoList[0].toInt());
            array[matricula].setNome(textoList[1]);
        }
    } catch (QString &erro) {
        throw erro;
    }
}

Pessoa TratamentoArquivos::consultar(int matricula)
{
    return array[matricula-1];
}

void TratamentoArquivos::alterar(int matricula, QString nome)
{
    array[matricula-1].setNome(nome);
}

void TratamentoArquivos::excluir(int matricula)
{
    int tamanho=1000;
    if (matricula >= 0 && matricula < tamanho) {
        for (int i = matricula-1; i < tamanho - 1; i++) {
            array[i] = array[i + 1];
        }
        tamanho--; // Reduz o tamanho do array
    } else {
        throw QString ("Não foi possível fazer a exclusão, verifique o número da matrícula");
    }
}
void TratamentoArquivos::inserir(int matricula, QString nome)
{
    if(array[matricula-1].getMatricula()==matricula-1) throw QString("Já há uma pessoa nessa matrícula");
    array[matricula-1].setMatricula(matricula-1);
    array[matricula-1].setNome(nome);
}
