#include "Conjunto.h"
#include <assert.h>
#include <cstddef>
#include <string>

template<class T>
Conjunto<T>::Conjunto()
{
    //ctor
    inicio = NULL;
    fin = NULL;
    cantidad = 0;
}

template<class T>
void Conjunto<T>::agregar(const T & elem)
{
    //AGREGA ELEMETOS AL FINAL.
    assert(not pertenece(elem));
    nodo * aux = new nodo;
    aux->dato = elem;
    aux->ste = NULL;
    if (fin == NULL)
    {
        if (inicio == NULL)
            inicio = aux;
        fin = aux;
    }
    else
    {
        fin->ste = aux;
        fin = aux;
    }
    cantidad++;
}

template <class T>
bool Conjunto<T>::pertenece(const T & elem) const
{
    if (inicio == NULL)
        return false;
    else
    {
        nodo * aux = new nodo;
        aux = inicio;
        while ((aux != NULL) && (aux->dato != elem))
            aux = aux->ste;
        if (aux == NULL)
            return false;
        else
            return true;
    }
}

template<class T>
void Conjunto<T>::eliminar_ultimo()
{
    assert((inicio != NULL));
    nodo * aux = new nodo;
    aux = inicio;
    int p; p = 1;
    while (p < cantidad-1)
    {
        aux = aux->ste;
        p++;
    }
    if (aux->ste == NULL)
    {
        inicio = NULL;
        fin = NULL;
        delete aux;
    }
    else
    {
        fin = aux;
        aux = aux->ste;
        fin->ste = NULL;
        delete aux;
    }
    cantidad--;
}

template<class T>
unsigned int Conjunto<T>::tamanio() const
{
    return cantidad;
}

template<class T>
void Conjunto<T>::eliminar(const T & elem)
{
    assert((inicio != NULL) && (pertenece(elem)));
    nodo * aux = new nodo;
    aux = inicio;
    if (aux->dato == elem)
    {
        if (aux->ste == NULL)
        {
            inicio = NULL;
            fin = NULL;
            delete aux;
        }
        else
        {
            inicio = inicio->ste;
            aux->ste = NULL;
            delete aux;
        }
    }
    else
    {
        while((aux->ste != NULL) and (aux->ste->dato != elem))
            aux = aux->ste;
        if (aux->ste == fin)
            fin = aux;
        nodo * borrar = new nodo;
        borrar = aux->ste;
        aux->ste = aux->ste->ste;
        borrar->ste = NULL;
        delete borrar;
    }
    cantidad--;
}

template<class T>
void Conjunto<T>::uniion(Conjunto & otroConjunto)
{
    nodo * aux = new nodo;
    aux = otroConjunto.inicio;
    while (aux != NULL)
    {
        if (pertenece(aux->dato) == true)
            aux = aux->ste;
        else
        {
            agregar(aux->dato);
            aux = aux->ste;
            cantidad++;
        }
    }
}

template<class T>
void Conjunto<T>::interseccion(Conjunto & OtroConjunto)
{
    if ((inicio != NULL) && (OtroConjunto.inicio != NULL))
    {
        int pos; pos = 1;
        nodo * aux = new nodo;
        aux = inicio;
        while(aux != NULL)
        {
            if (OtroConjunto.pertenece(aux->dato))
                aux = aux->ste;
            else
            {
                T borrar;
                borrar = aux->dato;
                aux = aux->ste;
                eliminar(borrar);
            }
        }
    }
    else
    {
        inicio = NULL;
        cantidad = 0;
    }
}


template<class T>
T Conjunto<T>::recuperar(unsigned int pos) const
{
    assert((pos >= 1) and (pos <= cantidad));
    if (pos == 1)
        return inicio->dato;
    if(pos == cantidad)
        return fin->dato;
    if ((pos > 1) && (pos < cantidad))
    {
        nodo * aux = new nodo;
        aux = inicio;
        int p; p = 1;
        while (p < pos)
        {
            aux = aux->ste;
            p++;
        }
        return aux->dato;
    }

}

template<class T>
bool Conjunto<T>::vacioConjunto() const
{
    if (cantidad == 0){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
Conjunto<T>::~Conjunto()
{
    //dtor
    nodo * aux = new nodo;
    while(inicio != NULL)
    {
        aux = inicio;
        inicio = inicio->ste;
        if (aux != NULL)
            delete aux;
    }
}

template class Conjunto<int>;
template class Conjunto<std::string>;
//template class Conjunto<char>;
//template class Conjunto<float>;
//template class Conjunto<Punto>;
//template class Conjunto<Segmento>;
