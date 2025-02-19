#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Función para imprimir el estado actual del array con índices visuales
void printArrayWithIndexes(const vector<int>& arr, int highlight1 = -1, int highlight2 = -1) {
    cout << "Índices:  ";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << setw(3) << i << " ";
    }
    cout << "\nValores:  ";
    for (size_t i = 0; i < arr.size(); i++) {
        if (i == highlight1 || i == highlight2)
            cout << "[" << setw(2) << arr[i] << "] ";
        else
            cout << setw(3) << arr[i] << " ";
    }
    cout << "\n-------------------------------------\n";
}

// Función para ajustar el heap (heapify)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;        // Inicializar la raíz como el mayor
    int left = 2 * i + 1;   // Hijo izquierdo
    int right = 2 * i + 2;  // Hijo derecho

    // Comparar con hijo izquierdo
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Comparar con hijo derecho
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Si el mayor no es la raíz, intercambiar y continuar heapify
    if (largest != i) {
        swap(arr[i], arr[largest]);
        printArrayWithIndexes(arr, i, largest); // Mostrar cambio
        heapify(arr, n, largest);
    }
}

// Implementación de Heapsort con visualización
void heapSort(vector<int>& arr) {
    int n = arr.size();

    cout << "Construyendo el Heap Máximo:\n";
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    cout << "Que hago aca?:\n";
    printArrayWithIndexes(arr, 0, n-1);

    cout << "Extrayendo elementos:\n";
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Mover la raíz al final
        printArrayWithIndexes(arr, 0, i); // Mostrar cambio
        heapify(arr, i, 0);
    }
}

// Programa principal
int main() {
    vector<int> arr = {6, 10, 11, 5, 7, 13};

    cout << "Array original:\n";
    printArrayWithIndexes(arr);

    heapSort(arr);

    cout << "Array ordenado con Heapsort:\n";
    printArrayWithIndexes(arr);

    return 0;
}
