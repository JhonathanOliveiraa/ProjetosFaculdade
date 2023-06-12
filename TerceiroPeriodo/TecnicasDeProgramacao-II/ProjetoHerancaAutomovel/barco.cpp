#include "barco.h"
namespace jhone{
Barco::Barco():
    velocidadeAtual(),
    tempoHoras()
{
}
Barco::Barco(int velocidadeAtual, int tempoHoras):
    velocidadeAtual(0),
    tempoHoras(0)
{
    if(velocidadeAtual<0) throw QString ("Velocidade não pode ser inferior a 0");
    if(tempoHoras<0) throw QString ("Velocidade não pode ser inferior a 0");
}
float Barco::acelerar(){
    return  velocidadeAtual/tempoHoras;
}
float Barco::freiar(){
    return velocidadeAtual^2/tempoHoras;
}
float Barco::virar(int raio){
    return velocidadeAtual^2/raio;
}
}
