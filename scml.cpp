#include <iostream>

using namespace std;

// Función de búsqueda binaria para encontrar la posición donde insertar el número
int buscar_posicion(int arr[], int longitud, int valor) {
    int inicio = 0, fin = longitud - 1;
    
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        
        if (arr[medio] >= valor)
            fin = medio - 1; // Buscar en la mitad izquierda
        else
            inicio = medio + 1; // Buscar en la mitad derecha
    }
    
    return inicio; // Retorna la posición donde debería ir 'valor'
}

// Función para encontrar la SCML
int SCML(int secuencia[], int n) {
    int lis[n]; // Arreglo auxiliar para la SCML
    int longitud = 0; // Longitud de la SCML

    for (int i = 0; i < n; i++) {
        // Encontrar la posición donde insertar usando nuestra propia búsqueda binaria
        int pos = buscar_posicion(lis, longitud, secuencia[i]);//Busqueda binaria log(n)

        // Insertar el número en la posición correcta
        lis[pos] = secuencia[i];

        // Si el número se coloca al final, incrementamos la longitud de la SCML
        if (pos == longitud)
            longitud++;
    }
    
    return longitud;
}

int main() {
    int secuencia[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(secuencia) / sizeof(secuencia[0]);

    cout << "Longitud de la SCML: " << SCML(secuencia, n) << endl;
    return 0;
}
