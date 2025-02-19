#include <iostream>
#include <string>

using namespace std;

struct actividad {
    int inicio;
    int fin;
};

void Mergepro(actividad Arreglo[], int inicio, int medio, int fin) {
    int k;
    int i = inicio;  // Índice para el arreglo auxiliar
    int f = inicio;  // Índice para la primera mitad del arreglo
    int j = medio + 1; // Índice para la segunda mitad
    actividad arr[fin + 1]; // Arreglo auxiliar para la fusión

    while ((f <= medio) && (j <= fin)) {
        if ((Arreglo[f].inicio * (Arreglo[f].fin-Arreglo[f].inicio)) <= ((Arreglo[j].inicio * (Arreglo[j].fin-Arreglo[j].inicio)))) {
        //if ((Arreglo[f].inicio) >= (Arreglo[j].fin)) {
        //if (Arreglo[f].fin <= Arreglo[j].fin){
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

void mergesortact(actividad Arreglo[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        mergesortact(Arreglo, inicio, medio);
        mergesortact(Arreglo, medio + 1, fin);
        Mergepro(Arreglo, inicio, medio, fin);
    }
}

void procesos(actividad entrada[], actividad solucion[], int fin, int &tam_sol) {
    mergesortact(entrada,0,fin);
    int i=0;
    int j=0;
    int horafin= entrada[i].fin;
    solucion[j]= entrada[i];
    i++;
    j++;
    while(i<fin){
        if (horafin<=entrada[i].inicio){
            solucion[j]=entrada[i];
            horafin=entrada[i].fin;
            j++;
    }
        i++;
    }
    tam_sol = j;
}

int main() {
    // Lista de procesos de prueba
    actividad entrada[] = {
        //{5, 7}, {3, 4}, {1, 6}
        {0, 10}, {14, 16}, {20, 22},{1,15}
    };

    int n = sizeof(entrada) / sizeof(entrada[0]);
    actividad solucion[n];
    int tam_sol = 0; // Número real de elementos validos en solucion

    procesos(entrada, solucion, n, tam_sol);

    cout << "Procesos ordenados por tiempo de ejecución:\n";
    for (int i = 0; i < tam_sol; i++) {
        cout << "Nombre: " << solucion[i].inicio << ", Tiempo: " << solucion[i].fin << endl;
    }

    return 0;
}
