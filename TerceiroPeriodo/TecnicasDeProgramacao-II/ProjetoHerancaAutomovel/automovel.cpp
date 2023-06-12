#include "automovel.h"
namespace jhone{
Automovel::Automovel():
    velocidadeAtual(),
    tempoHoras()
{
}
Automovel::Automovel(int velocidadeAtual, int tempoHoras):
    velocidadeAtual(0),
    tempoHoras(0)
{
    if(velocidadeAtual<0) throw QString ("Velocidade não pode ser inferior a 0");
    if(tempoHoras<0) throw QString ("Velocidade não pode ser inferior a 0");
}
float Automovel::acelerar(){
    return  velocidadeAtual/tempoHoras;
}
float Automovel::freiar(){
    return velocidadeAtual^2/tempoHoras;
}
float Automovel::virar(int raio){
    return velocidadeAtual^2/raio;
}
}
