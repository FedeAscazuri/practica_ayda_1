#include <iostream>

using namespace std;

void SelectionSort(int A[], int n) {
    int i, j, small, temp;
    for (i = 0; i < n - 1; i++) {
        small = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[small])
                small = j;
        }
        temp = A[small];
        A[small] = A[i];
        A[i] = temp;
    }
}

void mergesort(int a[], int inicio, int fin) {
    if (inicio < fin) {
        int mitad = (inicio + fin) / 2;
        mergesort(a, inicio, mitad);
        mergesort(a, mitad + 1, fin);
        merge(a, inicio, mitad, fin);
    }
}

void merge(int a[], int inicio, int mitad, int fin) {
    int h = inicio, i = inicio, j = mitad + 1, k;
    int b[20];
    while ((h <= mitad) && (j <= fin)) {
        if (a[h] <= a[j]) {
            b[i] = a[h];
            h++;
        }
         else {
            b[i] = a[j];
            j++;
        }
        i++;
    }
    if (h > mitad) {
        for (k = j; k <= fin; k++) {
            b[i] = a[k];
            i++;
        }
    }
     else {
        for (k = h; k <= mitad; k++) {
            b[i] = a[k];
            i++;
        }
    }
    for (k = inicio; k <= fin; k++) {
        a[k] = b[k];
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
