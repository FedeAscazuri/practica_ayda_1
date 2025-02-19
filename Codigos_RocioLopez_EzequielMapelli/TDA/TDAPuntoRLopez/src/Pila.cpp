#include "Pila.h"
#include <assert.h>
#include "Punto.h"


template<class T>
Pila<T>::Pila(unsigned int tam)
{
    this->arreglo = new T[tam];
    this->tam = tam;
    this->cant_elem_agregados = 0;
}

template<class T>
void Pila<T>::agregar_a_tope( const T & elem)
{
    assert(cant_elem_agregados < tam);
    this->arreglo[cant_elem_agregados] = elem;
    this->cant_elem_agregados++;
}

template<class T>
bool Pila<T>::es_vacia() const
{
    if (cant_elem_agregados == 0)
        return true;
    else
        return false;
}

template<class T>
T Pila<T>::tope() const
{
    return this->arreglo[cant_elem_agregados - 1];
}

template<class T>
void Pila<T>::eliminar_tope()
{
    this-> cant_elem_agregados--;
}

template<class T>
Pila<T>::~Pila()
{
    delete[] this->arreglo;
    //Destructor
}

template class Pila<int>;
//template class Pila<unsigned int>;
//template class Pila<float>;
template class Pila<Punto>;

