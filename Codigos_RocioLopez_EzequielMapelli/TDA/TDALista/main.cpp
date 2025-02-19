#include <iostream>
#include "Lista.h"

using namespace std;
void MostrarLista(Lista<int> Listita, unsigned int cant)
{
    unsigned int p; p= 1;
    while (p <= cant)
    {
        cout << Listita.recuperar(p) << endl;
        p++;
    }
}

int main()
{
    Lista<int> Listita;
    Listita.agregar_al_principio(2);
    Listita.agregar_al_principio(3);
    Listita.agregar_al_principio(4);
    Listita.agregar_al_final(1);
    Listita.insertar(5, 2);
    Listita.eliminar(3);
    MostrarLista(Listita, Listita.longitud());
    return 0;
}
