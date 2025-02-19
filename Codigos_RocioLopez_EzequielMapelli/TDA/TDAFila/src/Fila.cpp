#include "Fila.h"
//#include "Punto.h"
//#include "Segmento.h"


template<class T>
Fila<T>::Fila(unsigned int tam)
{
    //ctor
    this->arreglo = new T[tam];
    this->tam = tam;
    this->cant_elem_agregados = 0;
}

template<class T>
void Fila<T>::agregar(const T & elem)
{
    this->arreglo[cant_elem_agregados] = elem;
    this->cant_elem_agregados++;
}

template<class T>
bool Fila<T>::esvacia() const
{
    if (cant_elem_agregados == 0)
        return true;
    else
        return false;
}

template<class T>
void Fila<T>::eliminar()
{
    unsigned int pos;
    pos= 0;
    while (pos < tam-1)
    {
        this->arreglo[pos] = arreglo[pos+1];
        pos++;
    }
    this->cant_elem_agregados--;
}

template<class T>
T Fila<T>::recuperar() const
{
    return this->arreglo[0];
}

template<class T>
Fila<T>::~Fila()
{
    delete[] this->arreglo;
    //dtor
}

template class Fila<unsigned int>;
template class Fila<int>;
//template class Fila<float>;
//template class Fila<Punto>;
//template class Fila<Segmento>;
