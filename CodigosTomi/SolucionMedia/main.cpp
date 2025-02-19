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


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
