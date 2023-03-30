#include "paciente.h"
namespace Jhone{
    Paciente::Paciente():
        nomeCompleto(""),
        peso(0),
        altura(0),
        sexo("")
    {

    }

    Paciente::Paciente(QString nomeCompleto, int peso, float altura, QString sexo):
        nomeCompleto(""),
        peso(0),
        altura(0),
        sexo("")
    {
        this->nomeCompleto = nomeCompleto;
        if (peso <= 0)
            throw QString("Peso menor ou igual a 0");

        this->peso = peso;
        if (altura <= 0)
            throw QString("Altura menor ou igual a 0");

        this->altura = altura;
        this->sexo = sexo;
    }

    void Paciente::setNome(QString newNome){
        this->nomeCompleto = newNome;
    }

    QString Paciente::getNome()const{
        return this->nomeCompleto;
    }

    void Paciente::setAltura(float newAltura){
        if (newAltura <= 0 )
            throw QString("Altura nao pode ser igual ou menor que 0");
        this->altura = newAltura;
    }

    float Paciente::getAltura()const{
        return this->altura;
    }

    void Paciente::setPeso(int newPeso){
        if (newPeso <= 0)
            throw QString("Peso nao pode ser menor ou igual a 0");

        this->peso = newPeso;
    }

    int Paciente::getPeso()const{
        return this->peso;
    }

    void Paciente::setSexo(QString newSexo){
        this->sexo = newSexo;
    }

    QString Paciente::getSexo()const{
        return this->sexo;
    }

    float Paciente::calcularIMC()const{
        return (peso/(altura*altura));
    }
    QString Paciente::calcularFaixaRisco()const{
        float imc = calcularIMC();
        if (imc < 20)
            return "Abaixo do peso ideal";
        if (imc <= 25)
            return "Peso normal";
        if (imc <= 30)
            return "Excesso de peso";
        if (imc <= 35)
            return "Obesidade";
        return "Obesidade mórbida";
    }
    float Paciente::calcularPesoIdeal()const{
        if (getSexo() == "Masculino")
            return (72.7*altura-58);
        if (getSexo() == "Feminino")
            return (62.1*altura-44.7);
        throw QString("Não foi possível calcular o peso ideal, sexo não foi selecionado");
    }
}
