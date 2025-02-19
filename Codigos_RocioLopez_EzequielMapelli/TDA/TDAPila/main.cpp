#include <iostream>
#include <Pila.h>

using namespace std;

int main()
{
    Pila<int> pila1(10);
    pila1.agregar_a_tope(1);
    pila1.agregar_a_tope(2);
    pila1.agregar_a_tope(3);
    pila1.agregar_a_tope(4);
    pila1.eliminar_tope();
    cout << pila1.tope() << endl;
    return 0;
}
