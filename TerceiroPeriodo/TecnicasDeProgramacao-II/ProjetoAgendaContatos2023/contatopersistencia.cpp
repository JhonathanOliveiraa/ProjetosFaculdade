#include "contatopersistencia.h"
namespace jhone{
ContatoPersistencia::ContatoPersistencia():
    nomeDoArquivoNoDisco("Contatos.txt")
{
}
void ContatoPersistencia::criarArquivo()const{
    std::ofstream arquivoContatoBD;
    arquivoContatoBD.open(nomeDoArquivoNoDisco.toStdString().c_str(),
                          std::ios::out|std::ios::app);
}

void ContatoPersistencia::incluir(const Contato &objContato) const{
    std::ofstream arquivoContatoBD;
    arquivoContatoBD.open(nomeDoArquivoNoDisco.toStdString().c_str(),
                                        std::ios::out|std::ios::app);
    if(!arquivoContatoBD.is_open()){
        throw QString("Persistencia - Arquivo de Contatos nao foi aberto - Metodo incluir");
    }
    arquivoContatoBD<<objContato.toString().toStdString()+"\n";
    arquivoContatoBD.close();

}
std::list<Contato> *ContatoPersistencia::getListaDeContatos() const{
    try {
        std::ifstream arquivoAgenda;
        arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoAgenda.is_open()){
            throw QString("Arquivo de Agenda nao foi aberto - getListaDeContatos");
        }
        std::list<jhone::Contato> *listaDeContatos = new std::list<Contato>();
        std::string linha;
        getline(arquivoAgenda,linha);
        while(!arquivoAgenda.eof()){
            QString str = QString::fromStdString(linha);
            QStringList strList = str.split(";");
            QString cpf = strList[0];
            QString nome = strList[1];
            QString email = strList[2];
            int ddi = strList[3].toInt();
            int ddd = strList[4].toInt();
            int numero = strList[5].toInt();
            QString logradouro = strList[6];
            QString numeroCasa = strList[7];
            int cep = strList[8].toInt();
            jhone::Endereco endereco(logradouro,numeroCasa,cep);
            jhone::Telefone fone(ddi,ddd,numero);
            jhone::Contato objContato(cpf,nome,email,fone,endereco);
            listaDeContatos->push_back(objContato);
            getline(arquivoAgenda,linha);
        }
        arquivoAgenda.close();
        return listaDeContatos;
    } catch (QString &erro) {
        throw(erro);
    } catch (std::bad_alloc &erro){
        throw(QString("Objeto da classe list não foi criado"));
    }

}
Contato *ContatoPersistencia::consultar(QString &cpf) const{
    try {
        std::ifstream arquivoAgenda;
        arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoAgenda.is_open()){
            throw QString("Arquivo de Agenda não foi aberto");
        }
        std::string linha;
        getline(arquivoAgenda,linha);
        while(!arquivoAgenda.eof()){
            QString str = QString::fromStdString(linha);
            QStringList strList = str.split(";");
            QString cpfObj = strList[0];
            QString nome = strList[1];
            QString email = strList[2];
            int ddi = strList[3].toInt();
            int ddd = strList[4].toInt();
            int numero = strList[5].toInt();
            QString logradouro = strList[6];
            QString numeroCasa = strList[7];
            int cep = strList[8].toInt();
            jhone::Endereco endereco(logradouro,numeroCasa,cep);
            jhone::Telefone fone(ddi,ddd,numero);
            jhone::Contato *objContato = new Contato (cpf,nome,email,fone,endereco);
            if(cpf == cpfObj){
                arquivoAgenda.close();
                return objContato;
            }
            delete objContato;
            getline(arquivoAgenda,linha);
        }
        arquivoAgenda.close();
        return 0;
    } catch (QString &erro) {
        throw(erro);
    } catch (std::bad_alloc &erro){
        throw(QString("Objeto da classe list não foi criado"));
    }
}
void ContatoPersistencia::excluir(QString cpf) const {
    try {
        std::list<jhone::Contato> *listaDeContatos = getListaDeContatos();
        std::list<jhone::Contato>::iterator iterator;
        // abrir o arquivo para escrita apagando os dados
        std::ofstream arquivoContatoBD;
        arquivoContatoBD.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoContatoBD.is_open()){
            throw QString("Persistencia - Arquivo de Contatos nao foi aberto - Metodo incluir");
        }
        // Usar no for o iterator
        for(iterator = listaDeContatos->begin(); iterator!=listaDeContatos->end();iterator++){
            if(cpf!=iterator->getCpf()){
                //gravar no arquivo
                arquivoContatoBD<<iterator->toString().toStdString()+"\n";
            }
        }
        //fechar arquivo;
        arquivoContatoBD.close();
        // deletar lista
        delete listaDeContatos;
    } catch (QString &erro) {
        throw QString("Erro ao excluir o contato");
    }
}
void ContatoPersistencia::alterar(const Contato &objContato) const{
    try {
        excluir(objContato.getCpf());
        incluir(objContato);
    } catch (QString &erro) {
        throw QString("Erro ao alterar contato");
    }

}
}

