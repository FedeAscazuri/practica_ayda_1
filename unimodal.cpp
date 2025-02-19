#include <iostream>
using namespace std;

int findUnimodalPeakRecursive(int arr[], int l, int r) {
    if (l == r) {
        return l; // Caso base: hemos encontrado el pico
    }

    int m = l + (r - l) / 2;

    if (arr[m] > arr[m + 1]) {
        // El pico está en la parte izquierda o en m
        return findUnimodalPeakRecursive(arr, l, m);
    } else {
        // El pico está en la parte derecha
        return findUnimodalPeakRecursive(arr, m + 1, r);
    }
}

int main() {
    int arr[] = {1, 3, 7, 8, 15, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int peakIndex = findUnimodalPeakRecursive(arr, 0, n - 1);
    cout << "El índice del pico es: " << arr[peakIndex] << endl;

    return 0;
}
