#include <cassert>
#include <iostream>
#include <limits>
#include "Heap.h"

template <typename T>
Heap<T>::Heap(int tamanio){
    this->espacioUsado = 0;
    this->tamanio = tamanio;
    this->arregloEstructural = new T[this->tamanio];
    for(int i=0; i <this->tamanio; i++){
        arregloEstructural[i] = INT_MIN;
    }
}

template <typename T>
Heap<T>::~Heap(){
    delete[] this->arregloEstructural;
}

template <typename T>
int Heap<T>::indicePadre(int indice){
    return (indice/2);
}

template <typename T>
int Heap<T>::indiceHijoIzquierdo(int indice){
    return (indice*2);
}

template <typename T>
int Heap<T>::indiceHijoDerecho(int indice){
    return (indice*2)+1;
}

template <typename T>
void Heap<T>::burbujeoSuperior(int indiceNuevo){
    if(indiceNuevo > 1){ //Si estoy en 1 es que llegue a la raiz
        if(arregloEstructural[indicePadre(indiceNuevo)] > arregloEstructural[indiceNuevo]){//Si padre es mas grande que el hijo
            T auxiliar = arregloEstructural[indicePadre(indiceNuevo)]; //Intercambio al padre con el hijo
            arregloEstructural[indicePadre(indiceNuevo)] = arregloEstructural[indiceNuevo];
            arregloEstructural[indiceNuevo] = auxiliar;
        }
        burbujeoSuperior(indicePadre(indiceNuevo));
    }
}

template <typename T>
void Heap<T>::burbujeoInferior(int indice){
    int indiceIntercambio = indice;//Inicializo. Indice intercambio me dice al final con cual de los hijos debo intercambiar lo que hay en el indice.
    if((indiceHijoIzquierdo(indice) <= this->espacioUsado) &&
       (arregloEstructural[indiceHijoIzquierdo(indice)] < arregloEstructural[indice])){//Si el hijo izq es menor al padre
        indiceIntercambio = indiceHijoIzquierdo(indice);
    }
    if((indiceHijoDerecho(indice) <= this->espacioUsado) &&
       (arregloEstructural[indiceHijoDerecho(indice)] < arregloEstructural[indiceIntercambio])){
        indiceIntercambio = indiceHijoDerecho(indice);
    }
    if(indiceIntercambio != indice){
        T auxiliar = arregloEstructural[indice]; //Intercambio al hijo con el padre
        arregloEstructural[indice] = arregloEstructural[indiceIntercambio];
        arregloEstructural[indiceIntercambio] = auxiliar;
        burbujeoInferior(indiceIntercambio);
    }
}

template <typename T>
bool Heap<T>::heapVacio()const{
    return (arregloEstructural[1] == INT_MIN);
}

template <typename T>
void Heap<T>::insertarHeap(T elemento){
    if((this->espacioUsado + 1) < this->tamanio){ //Si queda espacio en el heap
        espacioUsado++;
        arregloEstructural[espacioUsado] = elemento;//Agrega al final.
        burbujeoSuperior(espacioUsado);//Ordeno los elementos.
    }
}

template <typename T>
void Heap<T>::eliminarHeap(){
    arregloEstructural[1] = arregloEstructural[this->espacioUsado];
    arregloEstructural[this->espacioUsado] = INT_MIN;
    espacioUsado--;
    burbujeoInferior(1);
}

template <typename T>
const T & Heap<T>::raizHeap() const{
    return arregloEstructural[1];
}

template class Heap<int>;
