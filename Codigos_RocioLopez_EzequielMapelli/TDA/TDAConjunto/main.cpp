#include <iostream>
#include <string>
#include "Conjunto.h"

using namespace std;


void MostrarConj(Conjunto<string> Conj1, unsigned int cant)
{
    int pos; pos= 1;
    while (pos <= cant)
    {
        string mostrar = Conj1.recuperar(pos);
        cout << mostrar << endl;
        pos++;
    }
}


int main()
{
    Conjunto<string> Conj1;
    cout << "Esta vacio el conjunto 1? ---> " << Conj1.vacioConjunto() << endl;
    Conj1.agregar("AAA");
    Conj1.agregar("BBB");
    Conj1.agregar("CCC");
    Conj1.agregar("DDD");
    cout << "Esta vacio el conjunto 1? ---> " << Conj1.vacioConjunto() << endl;
    MostrarConj(Conj1, Conj1.tamanio());
    return 0;
}
