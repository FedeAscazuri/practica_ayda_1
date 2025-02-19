#include <iostream>

using namespace std;

int particion(int arreglo[], int inicio, int fin);

void quicksort(int arreglo[], int inicio, int fin);

void mostrarArreglo(int arr[],int fin);

int main()
{
    int arreglo[5];
    arreglo[0] = 11;
    arreglo[1] = 5;
    arreglo[2] = 2;
    arreglo[3] = 1;
    arreglo[4] = 9;
    quicksort(arreglo,0,4);
    mostrarArreglo(arreglo,4);
    return 0;
}

void mostrarArreglo(int arr[],int fin){
    for(int i = 0; i <=fin; i++){
        cout<< arr[i]<<" | ";
    }
}

int particion(int arreglo[], int inicio, int fin){
    int pivot = inicio;
    while(inicio <= fin){
        if(arreglo[inicio] <= arreglo[pivot]){
            inicio++;
        }
        else if(arreglo[fin] > arreglo[pivot]){
            fin--;
        }
        else{
            int aux = arreglo[inicio];
            arreglo[inicio] = arreglo[fin];
            arreglo[fin] = aux;
            inicio++;
            fin--;
        }
    }
    if (inicio > fin){
        int aux = arreglo[pivot];
        arreglo[pivot] = arreglo[fin];
        arreglo[fin] = aux;
        pivot = fin;
    }
    return pivot;
}

void quicksort(int arreglo[], int inicio, int fin){
    if(inicio < fin){
        int pivot = particion(arreglo, inicio, fin);
        quicksort(arreglo, inicio, pivot-1);
        quicksort(arreglo, pivot+1, fin);
    }
}
