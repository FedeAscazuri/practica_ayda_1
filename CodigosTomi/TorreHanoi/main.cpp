#include <iostream>

using namespace std;


void Hanoi(int n, Pila origen,Pila destino,Pila aux)
{
    if (n == 1){
    destino.apilar(origen.desapilar);
    }
    else{ //MOVER N-1 DISCOS DE ORIGEN A AUX USANDO DESTINO
        Hanoi(n-1,origen,aux,destino);
        destino.apilar(origen.desapilar); //MUEVO EL DISCO N
        Hanoi(n-1,aux,destino,origen);
    }
} //MUEVE LOS N-1 DISCOS DE AUX A DEST

int cantMovHanoi(int n)
{ //Determina cuántos movimientos serán necesarios para resolver un Hanoi de n discos
    if (n==1){
    return 1;
    }
    else{
    return 2 * cantMovHanoi(n-1) + 1;
    }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
