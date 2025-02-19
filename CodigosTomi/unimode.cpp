#include <iostream>

using namespace std;

int buscarIndice(int a[], int inicio, int fin) {
    if (inicio > fin) {
        return -1;  // Caso base: no se encuentra el índice
    }

    int medio = inicio + (fin - inicio) / 2;

    if (a[medio] == medio) {
        return medio;  // Encontramos el índice que cumple T[i] = i
    } else if (a[medio] > medio) {
        return buscarIndice(a, inicio, medio - 1);  // Buscar en la mitad izquierda
    } else {
        return buscarIndice(a, medio + 1, fin);  // Buscar en la mitad derecha
    }
}


// Función recursiva de divide y conquista para encontrar min y max
void findMinMax(int arr[], int inicio, int fin, int &min, int &max) {
    // Caso base: Un solo elemento
    if (inicio == fin) {
        min = max = arr[inicio];
        return;
    }

    // Caso base: Dos elementos
    if (fin == inicio + 1) {
        if (arr[inicio] < arr[fin]) {
            min = arr[inicio];
            max = arr[fin];
        } else {
            min = arr[fin];
            max = arr[inicio];
        }
        return;
    }

    // Dividir el arreglo en dos mitades
    int medio = (inicio + fin) / 2;
    int minIzq = INT_MAX, maxIzq = INT_MIN;
    int minDer = INT_MAX, maxDer = INT_MIN;

    // Llamadas recursivas en ambas mitades
    findMinMax(arr, inicio, medio, minIzq, maxIzq);
    findMinMax(arr, medio + 1, fin, minDer, maxDer);

    // Combinar resultados
    min = std::min(minIzq, minDer);
    max = std::max(maxIzq, maxDer);
}
int main() {

/*
    int arr[] = {-3, 0, 1, 3, 5, 7}; // Ejemplo de array donde T[i] = i se cumple en índice 3
    int n = sizeof(arr) / sizeof(arr[0]);

    int resultado = buscarIndice(arr, 0, n - 1);

    if (resultado != -1) {
        std::cout << "Indice encontrado: " << resultado << std::endl;
    } else {
        std::cout << "No se encontró un índice tal que T[i] = i" << std::endl;
    }
*/

    int arr[] = {3, 5, 1, 8, 2, 9, 4, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min = INT_MAX, max = INT_MIN;
    findMinMax(arr, 0, n - 1, min, max);

    cout << "Mínimo: " << min << endl;
    cout << "Máximo: " << max << endl;
    return 0;
}