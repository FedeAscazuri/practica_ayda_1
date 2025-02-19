#include <iostream>

using namespace std;

void SolucionMedia(int a[], unsigned int inicio, unsigned int mitad, unsigned int fin, unsigned int &iniciomedia, unsigned int &finmedia, int &cantmedia)
{
    int sumaizq = valor_inicial;
    int suma = 0;
    for (unsigned int i = 0; i <= mitad; i++) {
        suma += a[mitad - i];
        if (suma > sumaizq) {
            sumaizq = suma;
            iniciomedia = mitad - i;
        }
    }

    int sumader = valor_inicial;
    suma = 0;
    for (unsigned int j = mitad + 1; j <= fin; j++) {
        suma += a[j];
        if (suma > sumader) {
            sumader = suma;
            finmedia = j;
        }
    }

    cantmedia = sumaizq + sumader;
}

void MayorSubarreglo(int a[], unsigned int inicio, unsigned int fin, unsigned int &iniciomax, unsigned int &finmax, int &cant)
{
    unsigned int inicioizq, finizq, inicioder, finder, iniciomedia, finmedia;
    int cantmedia, cantder, cantizq;

    if (inicio == fin) {
        iniciomax = inicio;
        finmax = fin;
        cant = a[inicio];
    }
    else {
        unsigned int mitad = (fin + inicio) / 2;
        MayorSubarreglo(a, inicio, mitad, inicioizq, finizq, cantizq);
        MayorSubarreglo(a, mitad + 1, fin, inicioder, finder, cantder);
        SolucionMedia(a, inicio, mitad, fin, iniciomedia, finmedia, cantmedia);

        if ((cantizq >= cantder) && (cantizq >= cantmedia)) {
            iniciomax = inicioizq;
            finmax = finizq;
            cant = cantizq;
        }
        else if ((cantder >= cantizq) && (cantder >= cantmedia)) {
            iniciomax = inicioder;
            finmax = finder;
            cant = cantder;
        }
        else {
            iniciomax = iniciomedia;
            finmax = finmedia;
            cant = cantmedia;
        }
    }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
