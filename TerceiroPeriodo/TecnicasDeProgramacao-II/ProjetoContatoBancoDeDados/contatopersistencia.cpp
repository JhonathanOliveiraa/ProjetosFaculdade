#include "contatopersistencia.h"
namespace jhone{
ContatoPersistencia::ContatoPersistencia()
{
    bd = QSqlDatabase::addDatabase("QSQLITE");
    nomeDoBancoDeDados = "C:/Users/jhone/OneDrive/Documentos/BancoDeDados/ContatoBD.db"; // Necessário colocar o diretório do seu computador, o banco de dados está na pasta Arquivos
    bd.setDatabaseName(nomeDoBancoDeDados);
}

void ContatoPersistencia::incluir(const Contato &objContato) {
    if (!bd.open()){
            throw QString("Erro ao abrir o banco de dados");
        }

        QSqlQuery query;
        query.prepare("INSERT INTO contatos (cpf_contatos, nome, email, ddi, ddd, numero_fone, logradouro, num_end, cep) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?);");
        query.bindValue(0, objContato.getCpf());
        query.bindValue(1, objContato.getNome());
        query.bindValue(2, objContato.getEmail());
        query.bindValue(3, objContato.getFone().getDdi());
        query.bindValue(4, objContato.getFone().getDdd());
        query.bindValue(5, objContato.getFone().getNumero());
        query.bindValue(6, objContato.getEndereco().getLogradouro());
        query.bindValue(7, objContato.getEndereco().getNumero());
        query.bindValue(8, objContato.getEndereco().getCep());

        if (!query.exec()){
            bd.close();
            throw QString("Erro ao executar a inserção - ") + query.lastError().text();
        }
        bd.close();
    }
std::list<Contato> *ContatoPersistencia::getListaDeContatos() {
        if (!bd.open()) throw QString("ERRO: Banco de dados não foi aberto - GetListaDeContatosPersistencia - ") + bd.lastError().text();
        QSqlQuery query("SELECT cpf_contatos, nome, email, ddi, ddd, numero_fone, logradouro, num_end, cep FROM contatos");
        std::list<Contato> *listaDeContatos = new std::list<Contato>();
        while (query.next()) {
            QString cpf = query.value(0).toString();
            QString nome = query.value(1).toString();
            QString email = query.value(2).toString();
            int ddi = query.value(3).toInt();
            int ddd = query.value(4).toInt();
            int numero = query.value(5).toInt();
            QString logradouro = query.value(6).toString();
            QString numeroCasa = query.value(7).toString();
            int cep = (query.value(8).toInt());
            jhone::Telefone fone(ddi, ddd, numero);
            jhone::Endereco endereco(logradouro, numeroCasa, cep);
            jhone::Contato objContato(cpf, nome, email, fone, endereco);
            listaDeContatos->push_back(objContato);
        }
        bd.close();
        return listaDeContatos;
}

Contato *ContatoPersistencia::consultar(QString &cpf) {
    if (!bd.open()){
        throw QString("Erro ao abrir o banco de dados");
    }
    QSqlQuery query;
        query.prepare("SELECT cpf_contatos, nome, email, ddi, ddd, numero_fone, logradouro, num_end, cep FROM contatos WHERE cpf_contatos = ?;");
        query.bindValue(0, cpf);
        if (!query.exec()){
            bd.close();
            throw QString("Erro ao executar a consulta - ConsultarPersistência");
        }
        if (!query.next()) {
            bd.close();
            return nullptr;
        }
    QString cpfAux = query.value(0).toString();
    QString nome = query.value(1).toString();
    QString email = query.value(2).toString();
    int ddi = query.value(3).toInt();
    int ddd = query.value(4).toInt();
    int numFone = query.value(5).toInt();
    QString logradouro = query.value(6).toString();
    QString num_end = query.value(7).toString();
    int cep = query.value(8).toInt();
    jhone::Endereco endereco(logradouro,num_end,cep);
    jhone::Telefone fone(ddi,ddd,numFone);
    jhone::Contato* aux = new Contato(cpfAux,nome,email,fone,endereco);
    bd.close();
    return aux;
}
void ContatoPersistencia::excluir(QString cpf) {
        if (!bd.open()){
            throw QString("Erro ao abrir o banco de dados");
        }
        QSqlQuery query;
        query.prepare("DELETE FROM contatos WHERE cpf_contatos = ?;");
        query.bindValue(0, cpf);
        if (!query.exec()){
            bd.close();
            throw QString("Erro ao executar a exclusão - DeletarPersistência");
        }
        bd.close();
}
void ContatoPersistencia::alterar(const Contato &objContato){
        if (!bd.open()){
            throw QString("Erro ao abrir o banco de dados");
        }
        QSqlQuery query;
        query.prepare("UPDATE contatos SET cpf_contatos = ?, nome = ?, email = ?, ddi = ?, ddd = ?, numero_fone = ?, logradouro = ?, num_end = ?, cep = ? WHERE cpf_contatos = ?;");
        query.bindValue(0, objContato.getCpf());
        query.bindValue(1, objContato.getNome());
        query.bindValue(2, objContato.getEmail());
        query.bindValue(3, objContato.getFone().getDdi());
        query.bindValue(4, objContato.getFone().getDdd());
        query.bindValue(5, objContato.getFone().getNumero());
        query.bindValue(6, objContato.getEndereco().getLogradouro());
        query.bindValue(7, objContato.getEndereco().getNumero());
        query.bindValue(8, objContato.getEndereco().getCep());
        query.bindValue(9, objContato.getCpf());
        if (!query.exec()){
            bd.close();
            throw QString("Erro ao executar a alteração - AlterarPersistência");
        }
        bd.close();
    }
}

