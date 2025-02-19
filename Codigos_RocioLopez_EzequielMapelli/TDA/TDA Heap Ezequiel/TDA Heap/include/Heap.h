#ifndef HEAP_H
#define HEAP_H

template <typename T>
class Heap //MinHeap
{
    public:
        Heap(int tamanio);
        ~Heap();
        bool heapVacio() const;
        void insertarHeap(T elemento);
        void eliminarHeap();
        const T & raizHeap() const;

    private:
       T *arregloEstructural;
       int tamanio; //Tamaño del arreglo.
       int espacioUsado; //Cuanto use del arreglo.
       //funciones privadas:
       int indicePadre(int indice); //Devuelvo indice del nodo/2, ahi siempre esta el padre, tambien puedo hacer >>1 (shift a derecha)
       int indiceHijoIzquierdo(int indice); //Devuelvo indice del nodo*2
       int indiceHijoDerecho(int indice); //Devuelvo indice del nodo*2 + 1
       void burbujeoSuperior(int indice); //Si el padre es mas grande que el hijo, los intercambia, hasta llegar a la raiz.
       void burbujeoInferior(int indice); //Si los hijos sonmas chicos que el padre, intercambio por el hijo menor.

};

#endif // HEAP_H
