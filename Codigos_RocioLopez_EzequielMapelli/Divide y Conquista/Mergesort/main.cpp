#include <iostream>

using namespace std;

void mergest(int arreglo[], int inicio, int mitad, int fin);

void mergesort(int arreglo[], int inicio, int fin);

void mostrarArreglo(int arr[],int fin);

int main()
{
    int arreglo[5];
    arreglo[0] = 11;
    arreglo[1] = 5;
    arreglo[2] = 5;
    arreglo[3] = 1;
    arreglo[4] = 9;
    mergesort(arreglo,0,4);
    mostrarArreglo(arreglo,4);
    return 0;
}

void mostrarArreglo(int arr[],int fin){
    for(int i = 0; i <=fin; i++){
        cout<< arr[i]<<" | ";
    }
}

void mergest(int arreglo[], int inicio, int mitad, int fin){
    int arregloAuxiliar[fin+1];
    int i = inicio;
    int j = mitad+1;
    int p = 0;
    while((i<=mitad)&&(j<=fin)){
        if(arreglo[j] < arreglo[i]){
            arregloAuxiliar[p] = arreglo[j];
            j++;
            p++;
        }else{
            arregloAuxiliar[p] = arreglo[i];
            i++;
            p++;
        }
    }
    if(p <= fin){
        while(i <= mitad){
            arregloAuxiliar[p] = arreglo[i];
            i++;
            p++;
        }
        while(j <= fin){
            arregloAuxiliar[p] = arreglo[j];
            j++;
            p++;
        }
    }
    p = 0;
    for(int pos = inicio; pos <= fin; pos++){
        arreglo[pos] = arregloAuxiliar[p];
        p++;
    }
}

void mergesort(int arreglo[], int inicio, int fin){
    if(inicio < fin){
        int mitad = (inicio + fin)/2;
        mergesort(arreglo, inicio, mitad);
        mergesort(arreglo, mitad+1, fin);
        mergest(arreglo, inicio, mitad, fin);
    }
}
