#include <iostream>
#include <limits.h>

void DivideMAXMIN(int Arreglo[], int inicio, int fin, int &MAX, int &MIN) {
    if (inicio == fin) {
        MAX = Arreglo[inicio];
        MIN = MAX;
    } else {
        if (inicio == fin - 1) {
            if (Arreglo[inicio] > Arreglo[fin]) {
                MAX = Arreglo[inicio];
                MIN = Arreglo[fin];
            } else {
                MIN = Arreglo[inicio];
                MAX = Arreglo[fin];
            }
        } else {
            int maxx = Arreglo[inicio];
            int minn = Arreglo[inicio];

            int tercero = (fin - inicio) / 3;
	        int mitad1 = (inicio + tercero) +1;
	        int mitad2 = mitad1 + tercero + 1;

            DivideMAXMIN(Arreglo, inicio, tercero, MAX, MIN);
            DivideMAXMIN(Arreglo, mitad1 + 1, mitad2, maxx, minn);
	        DivideMAXMIN(Arreglo, mitad2+1,fin,maxx,minn);

            if (maxx > MAX) {
                MAX = maxx;
            }
            if (minn < MIN) {
                MIN = minn;
            }
        }
    }
}

int main() {
    int arr[] = {3, 1, 7, 2, 8, -5, 10, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    DivideMAXMIN(arr, 0, n - 1, min, max);

    std::cout << "Mínimo: " << min << ", Máximo: " << max << std::endl;
    return 0;
}