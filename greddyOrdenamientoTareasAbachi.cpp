#include <iostream>
#include <string>

using namespace std;

struct proceso {
    int tiempo;
    string nombre;
};

void Mergepro(proceso Arreglo[], int inicio, int medio, int fin) {
    int k;
    int i = inicio;  // Índice para el arreglo auxiliar
    int f = inicio;  // Índice para la primera mitad del arreglo
    int j = medio + 1; // Índice para la segunda mitad
    proceso arr[fin + 1]; // Arreglo auxiliar para la fusión

    while ((f <= medio) && (j <= fin)) {
        if (Arreglo[f].tiempo <= Arreglo[j].tiempo) {
            arr[i] = Arreglo[f];
            f++;
        } else {
            arr[i] = Arreglo[j];
            j++;
        }
        i++;
    }

    // Copiar los elementos restantes de la primera mitad, si hay
    while (f <= medio) {
        arr[i] = Arreglo[f];
        f++;
        i++;
    }

    // Copiar los elementos restantes de la segunda mitad, si hay
    while (j <= fin) {
        arr[i] = Arreglo[j];
        j++;
        i++;
    }

    // Copiar el arreglo ordenado de vuelta al original
    for (k = inicio; k <= fin; k++) {
        Arreglo[k] = arr[k];
    }
}

void mergesortpro(proceso Arreglo[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        mergesortpro(Arreglo, inicio, medio);
        mergesortpro(Arreglo, medio + 1, fin);
        Mergepro(Arreglo, inicio, medio, fin);
    }
}

void procesos(proceso entrada[], proceso solucion[], int n) {
    mergesortpro(entrada, 0, n - 1);
    for (int i = 0; i < n; i++) {
        solucion[i] = entrada[i];
    }
}

int main() {
    // Lista de procesos de prueba
    proceso entrada[] = {
        {5, "P1"}, {10, "P2"}, {3, "P3"}
    };

    int n = sizeof(entrada) / sizeof(entrada[0]);
    proceso solucion[n];

    procesos(entrada, solucion, n);

    cout << "Procesos ordenados por tiempo de ejecución:\n";
    for (int i = 0; i < n; i++) {
        cout << "Nombre: " << solucion[i].nombre << ", Tiempo: " << solucion[i].tiempo << endl;
    }

    return 0;
}
