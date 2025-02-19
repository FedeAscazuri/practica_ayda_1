#include <iostream>
using namespace std;

void merge(int a[], int inicio, int mid1, int mid2, int fin) {
    int i = inicio, j = mid1 + 1, k = mid2 + 1, l = inicio;
    int b[20];

    while (i <= mid1 && j <= mid2 && k <= fin) {
        if (a[i] <= a[j] && a[i] <= a[k]) {
            b[l++] = a[i++];
        } else if (a[j] <= a[i] && a[j] <= a[k]) {
            b[l++] = a[j++];
        } else {
            b[l++] = a[k++];
        }
    }

    while (i <= mid1 && j <= mid2) {
        if (a[i] <= a[j]) {
            b[l++] = a[i++];
        } else {
            b[l++] = a[j++];
        }
    }

    while (j <= mid2 && k <= fin) {
        if (a[j] <= a[k]) {
            b[l++] = a[j++];
        } else {
            b[l++] = a[k++];
        }
    }

    while (i <= mid1 && k <= fin) {
        if (a[i] <= a[k]) {
            b[l++] = a[i++];
        } else {
            b[l++] = a[k++];
        }
    }

    while (i <= mid1) {
        b[l++] = a[i++];
    }

    while (j <= mid2) {
        b[l++] = a[j++];
    }

    while (k <= fin) {
        b[l++] = a[k++];
    }

    for (int m = inicio; m <= fin; m++) {
        a[m] = b[m];
    }
}


void mergesort(int a[], int inicio, int fin) {
    if (inicio < fin) {
        int third = (fin - inicio) / 3;
        int mid1 = inicio + third;
        int mid2 = mid1 + third + 1;
        mergesort(a, inicio, mid1);
        mergesort(a, mid1 + 1, mid2);
        mergesort(a, mid2 + 1, fin);
        merge(a, inicio, mid1, mid2, fin);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 3, 1, 9, 10, 4, 8, 2, 14, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    mergesort(arr, 0, n - 1);

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
