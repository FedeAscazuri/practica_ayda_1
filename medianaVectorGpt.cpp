#include <iostream>
using namespace std;

// Función para encontrar la mediana de dos arreglos ordenados en O(log n)
double encontrarMediana(int v1[], int v2[], int n) {
    if (n > 2) {
        int mid1 = n / 2;
        int mid2 = n - mid1 - 1;

        if (v1[mid1] == v2[mid2]) 
            return v1[mid1];

        // Reducimos el tamaño de búsqueda eliminando la mitad de los elementos
        if (v1[mid1] < v2[mid2])
            return encontrarMediana(v1 + mid1, v2, n - mid1);
        else
            return encontrarMediana(v1, v2 + mid2, n - mid2);
    }
    return (max(v1[0], v2[0]) + min(v1[1], v2[1])) / 2.0;
}

int main() {
    int n = 8;
    int v1[8] = {27,36,5,12,15,87,12,55};
    int v2[8] = {6,99,8,45,2,31,26,74};
    double mediana = encontrarMediana(v1, v2, n);
    cout << "Mediana: " << mediana << endl;

    return 0;
}