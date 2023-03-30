#include "mudarbase.h"
#include <pilha.h>
namespace jhone
{
    MudarBase::MudarBase(int numero, int base):
        numero(numero),
        base(base)
    {    
    }


    QString MudarBase::calcularMB()
        {
            Pilha p(30);
            QString saida="";
            QString str="0123456789ABCDEF";
            int resto=0;
            int aux=numero;

            while(aux!=0)
            {
                resto = aux%base;
                p.empilhar(resto);
                aux /= base;
            }
            while(!p.estaVazia())
            {
                int pos = p.desempilhar();
                saida += str[pos];
            }
            return saida;
        }

}
