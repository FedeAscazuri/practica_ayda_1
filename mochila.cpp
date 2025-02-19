#include <iostream>
using namespace std;

struct objeto {
    float peso;
    float valor;
    float ganancia; // Ganancia = valor / peso
};

void Mergeobj(objeto Arreglo[], int inicio, int medio, int fin) {
    int k;
    int i = inicio; 
    int f = inicio;
    int j = medio + 1;
    objeto arr[fin + 1];  // Se declara con tamaño suficiente

    while ((f <= medio) && (j <= fin)) {
        if (Arreglo[f].ganancia >= Arreglo[j].ganancia) { // Ordenar en orden descendente
            arr[i] = Arreglo[f];
            f++;
        } else {
            arr[i] = Arreglo[j];
            j++;
        }
        i++;
    }

    while (f <= medio) {
        arr[i] = Arreglo[f];
        f++;
        i++;
    }

    while (j <= fin) {
        arr[i] = Arreglo[j];
        j++;
        i++;
    }

    for (k = inicio; k <= fin; k++) {
        Arreglo[k] = arr[k];
    }
}

void mergesortObj(objeto Arreglo[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        mergesortObj(Arreglo, inicio, medio);
        mergesortObj(Arreglo, medio + 1, fin);
        Mergeobj(Arreglo, inicio, medio, fin);
    }
}

void mochila(objeto entrada[], objeto solucion[], int n, int limite) {
    mergesortObj(entrada, 0, n - 1); // Ordenar por mayor ganancia
    int i = 0;
    float peso_total = 0.0;

    while (i < n && peso_total < limite) {
        if (entrada[i].peso + peso_total <= limite) {
            solucion[i] = entrada[i]; 
            peso_total += entrada[i].peso;
        } else {
            // Se toma una fracción del objeto
            float fraccion = (limite - peso_total) / entrada[i].peso;
            solucion[i] = {entrada[i].peso * fraccion, entrada[i].valor * fraccion, entrada[i].ganancia};
            peso_total = limite;
        }
        i++;
    }
}

int main() {
    int n = 5; // Cantidad de objetos
    int limite = 15; // Límite de peso de la mochila

    objeto entrada[] = {
        {2, 10, 0},
        {3, 5, 0},
        {5, 15, 0},
        {7, 7, 0},
        {15, 60, 0}
    };

    // Calcular la ganancia de cada objeto
    for (int i = 0; i < n; i++) {
        entrada[i].ganancia = entrada[i].valor / entrada[i].peso;
    }

    objeto solucion[n] = {}; // Inicializar la solución

    mochila(entrada, solucion, n, limite);

    // Imprimir resultado
    cout << "Objetos en la mochila:\n";
    for (int i = 0; i < n; i++) {
        if (solucion[i].peso > 0) {
            cout << "Peso: " << solucion[i].peso << ", Valor: " << solucion[i].valor << ", Ganancia: " << solucion[i].ganancia << endl;
        }
    }

    return 0;
}
