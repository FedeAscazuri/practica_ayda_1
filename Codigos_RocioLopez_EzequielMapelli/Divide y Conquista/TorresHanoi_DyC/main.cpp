#include <iostream>

using namespace std;

void hanoi(int cantDiscos, char origen, char destino, char auxiliar){
    if (cantDiscos == 1){
        cout << origen << destino << ":";
    }
    else{
        hanoi(cantDiscos-1, origen, auxiliar, destino);
        cout << origen << destino << ":";
        hanoi(cantDiscos-1, auxiliar, destino, origen);
    }
}

int main()
{
    //Declaración de variables:
    int cantDiscos = 4;
    char origen = 'A';
    char destino = 'B';
    char auxiliar = 'C';
    hanoi(cantDiscos, origen, destino, auxiliar);
    return 0;
}
