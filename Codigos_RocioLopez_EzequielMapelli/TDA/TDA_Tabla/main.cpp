#include <iostream>
#include "Tabla.h"

using namespace std;

int main()
{
    Tabla tablita(3,3);
    tablita.agregar(5,0,0);
    tablita.agregar(8,1,1);
    tablita.agregar(1,0,2);
    tablita.agregar(1,1,2);
    tablita.agregar(5,2,2);
    cout << "Está vacia la celda F0C2? " << "---> " << tablita.vaciaCelda(0,2) << endl;
    cout << "Está vacia la celda F1C0? " << "---> " << tablita.vaciaCelda(1,0) << endl;
    cout << "Cual es el valor de la celda F1C1? " << "---> " << tablita.valorCelda(0,0) << endl;
    cout << "Cual es el mayor valor entero de la tabla? " << "---> " << tablita.mayorEntero() << endl;
    cout << "Cual es la suma de todos los valores de la columna 2? " << "---> " << tablita.sumaColum(2) << endl;
    return 0;
}
