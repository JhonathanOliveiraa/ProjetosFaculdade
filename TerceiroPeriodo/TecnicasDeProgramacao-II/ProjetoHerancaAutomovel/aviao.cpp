#include "aviao.h"
namespace jhone{
Aviao::Aviao():
    velocidadeAtual(),
    tempoHoras()
{
}
Aviao::Aviao(int velocidadeAtual, int tempoHoras):
    velocidadeAtual(0),
    tempoHoras(0)
{
    if(velocidadeAtual<0) throw QString ("Velocidade não pode ser inferior a 0");
    if(tempoHoras<0) throw QString ("Velocidade não pode ser inferior a 0");
}
float Aviao::acelerar(){
    return velocidadeAtual/tempoHoras;
}
float Aviao::freiar(){
    return velocidadeAtual^2/tempoHoras;
}
float Aviao::virar(int raio){
    return velocidadeAtual^2/raio;
}
}
