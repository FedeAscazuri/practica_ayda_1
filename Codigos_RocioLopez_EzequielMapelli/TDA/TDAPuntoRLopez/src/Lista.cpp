#include "Lista.h"
#include <assert.h>



template<class T>
Lista<T>:: Lista()
{
    inicio= NULL;
    fin= NULL;
    cantidad= 0;
}

template<class T>
void Lista<T>::agregar_al_principio(const T & elem)
{
    nodo * aux = new nodo;
    aux ->dato = elem;
    aux ->ste = inicio;
    inicio = aux;
    if (fin ==  NULL)
        fin = inicio;
    cantidad++;
}

template<class T>
void Lista<T>::agregar_al_final(const T & elem)
{
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
        fin= aux;
    }
    cantidad++;
}


template<class T>
unsigned int Lista<T>::longitud() const
{
    return cantidad;
}

template<class T>
void Lista<T>::eliminar(unsigned int pos)
{
    assert((pos >= 1) and (pos <= cantidad));
    {
        nodo * aux = new nodo;
        if (pos == 1)
        {
            aux = inicio;
            inicio = inicio->ste;
            aux->ste = NULL;
            delete aux;
        }
        else
        {
            nodo * borrar = new nodo;
            unsigned int p;
            p = 1;
            aux = inicio;
            while (p < pos-1)
            {
                aux = aux->ste;
                p++;
            }
            if (pos == cantidad)
                fin = aux;
            borrar = aux->ste;
            aux->ste = aux->ste->ste;
            borrar->ste = NULL;
            aux = aux->ste;
            delete borrar;
        }
        cantidad--;
    }
}

template<class T>
T Lista<T>::recuperar(unsigned int pos) const
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
void Lista<T>::insertar(const T & elem, unsigned int pos)
{
    assert((pos >= 1) and (pos <= cantidad));
    if (pos == 1)
        agregar_al_principio(elem);
    if (pos == cantidad)
        agregar_al_final(elem);
    if ((pos > 1) && (pos < cantidad))
    {
        nodo * elemento = new nodo;
        nodo * aux = new nodo;
        elemento->dato = elem;
        elemento->ste = NULL;
        aux = inicio;
        int p; p = 1;
        while (p < pos-1)
        {
            aux = aux->ste;
            p++;
        }
        elemento->ste = aux->ste;
        aux->ste = elemento;
        cantidad++;
    }
}

template<class T>
bool Lista<T>::pertenece(const T & elem) const
{
    if (inicio == NULL)
        return false;
    else
    {
        nodo * aux = new nodo;
        aux = inicio;
        while ((aux != NULL) && (aux->dato != elem))
        {
            aux = aux->ste;
        }
        if (aux == NULL)
            return false;
        else
            return true;
    }
}

template<class T>
void Lista<T>::modificar(Lista & OtraLista)
{
    nodo * aux = new nodo;
    aux = OtraLista.inicio;
    int pos; pos = 1;
    while (pos <= OtraLista.longitud())
    {
        if (pertenece(aux->dato) == false)
            agregar_al_final(aux->dato);
        aux = aux->ste;
        pos++;
    }
}

template<class T>
Lista<T>::~Lista()
{
    nodo * aux = new nodo;
    while (inicio != NULL)
    {
        aux = inicio;
        inicio = inicio->ste;
        if (aux != NULL)
            delete aux;
    }
}


template class Lista<int>;
//template class Lista<char>;
//template class Lista<float>;

