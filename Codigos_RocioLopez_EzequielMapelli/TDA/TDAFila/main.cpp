#include <iostream>
#include <Fila.h>

using namespace std;

int main()
{
    Fila<int> fila1(10);
    fila1.agregar(1);
    fila1.agregar(2);
    fila1.agregar(3);
    fila1.agregar(4);
    fila1.eliminar();
    cout << fila1.recuperar() << endl;
    return 0;
}
