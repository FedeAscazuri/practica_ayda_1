#include <iostream>
#include "Vector.h"
using namespace std;

//consigna: Sean X e Y dos vectores de tamaño n, ordenados de forma creciente, implementar un algoritmo
//para calcular la mediana de los 2n elementos que contienen X e Y. Recordemos que la mediana
//de un vector es aquel elemento que, una vez ordenado el vector, deja la mitad de los elementos a
//cada uno de sus lados

int particion(int a[], int ini, int fin){
    int aux;
    int i = ini;
    int j = fin;
    int p = a[ini];
    while(i < j){
        while (a[i] <= p)
            i++;
        while(a[j] > p)
            j--;
        if(i < j){
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
        }
    }
    aux = a[j];
    a[j] = p;
    a[ini] = aux;
    return j;
}

void quicksort(int a[], int i, int j){
    if(i < j){
        int p = particion(a, i, j);
        quicksort(a, i, p-1);
        quicksort(a, p+1, j);
    }
}

void nuevoVector(int v1[], int v2[], int n, int v[]){
    int i = 0;
    while(i < n) {
        v[i] = v1[i];
        i++;
    }
    for(int j = 0; j < n; j++) {
        v[i] = v2[j];
        i++;
    }
    int t = 2*n;
    quicksort(v, 0, t-1);
}

int mediana(int v1[], int v2[], int n){
    int medio = (n*2 -1)/2;
    int v[2*n];
    nuevoVector(v1, v2, n, v);
    return v[medio];
}

int main() {
    int n = 4;
    int v1[8] = {27,36,5,12,15,87,12,55};
    int v2[8] = {6,99,8,45,2,31,26,74};
    cout<<"v1: "<<endl;
    for (int i = 0; i < 8; i++)
        cout<<v1[i]<<" ";

    cout<<endl<<"v2:"<<endl;
    for (int i = 0; i < 8; i++)
        cout<<v2[i]<<" ";
    cout<<endl;

    int med = mediana(v1, v2, 8);
    cout<<"mediana: "<<med;
    return 0;
}
