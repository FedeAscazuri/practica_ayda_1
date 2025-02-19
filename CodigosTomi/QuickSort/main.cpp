#include <iostream>
using namespace std;

int particion(int a[], int inicio, int fin) {
    int pivot = a[fin];
    int i = inicio - 1;
    for (int j = inicio; j < fin; j++) {
        if (a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[fin];
    a[fin] = temp;
    return i + 1;
}

void quicksort(int a[], int inicio, int fin) {
    if (inicio < fin) {
        int pivotIndex = particion(a, inicio, fin);
        quicksort(a, inicio, pivotIndex - 1);
        quicksort(a, pivotIndex + 1, fin);
    }
}


int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array original: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    quicksort(arr, 0, n - 1);

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
