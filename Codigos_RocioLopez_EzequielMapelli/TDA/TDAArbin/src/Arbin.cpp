#include "Arbin.h"
#include <cassert>
#include <iostream>
//#include "Punto.h"
//#include "Segmento.h"

using namespace std;

template <typename T>
Arbin<T>::Arbin() {
	inicio = NULL;
}

template <typename T>
Arbin<T>::~Arbin () {
	vaciar (this);
}

template <typename T>
void Arbin<T>::vaciar(Arbin<T>* a) {
    if (a->inicio != NULL) {
        vaciar(a->arbol_izquierdo());
        vaciar(a->arbol_derecho());

        delete a->inicio;
        a->inicio = NULL;
        delete a;
    }
}

template <typename T>
Arbin<T>::Arbin(const Arbin<T>& otroArbol) {
    inicio = NULL;
    this->operator=(otroArbol);
}

template <typename T>
void Arbin<T>::construir(Arbin<T>* izq, Arbin<T>* der, const T & dato) {
	Arbin* i = new Arbin(*izq);
	Arbin* d = new Arbin(*der);
	inicio =  new NodoArbol(dato,i,d);
}

template <typename T>
const T & Arbin<T>::raiz() const {
    assert (inicio);
    return inicio->obtener_dato();
}

template <typename T>
Arbin<T>* Arbin<T>::arbol_izquierdo() const {
    assert (inicio);
    return inicio->obtener_izquierda();
}

template <typename T>
Arbin<T>* Arbin<T>::arbol_derecho() const {
    assert (inicio);
    return inicio->obtener_derecha();
}

template <typename T>
bool Arbin<T>::es_vacio()const {
	return(inicio==NULL);
}

template <typename T>
bool Arbin<T>::es_hoja()const {
    assert (inicio);
    return ((inicio->obtener_izquierda()->inicio == NULL) && (inicio->obtener_derecha()->inicio == NULL));
}

template<typename T>
bool Arbin<T>::pertenece(T elemento) const
{
    if (inicio == NULL)
        return false;
    else
        return (this->arbol_derecho()->pertenece(elemento)) ||(this->arbol_izquierdo()->pertenece(elemento));
}

template<typename T>
unsigned int Arbin<T>::Altura_Arbol() const
{
    if (inicio == NULL)
        return 0;
    else
    {
        return 1 + max(this->arbol_derecho()->Altura_Arbol(), this->arbol_izquierdo()->Altura_Arbol());
    }
}

template<typename T>
unsigned int Arbin<T>::Cant_Nodos() const
{
    if (inicio == NULL)
        return 0;
    else
        return 1 + (this->arbol_derecho()->Cant_Nodos() + this->arbol_izquierdo()->Cant_Nodos());
}

template <typename T>
Arbin<T> & Arbin<T>::operator= (const Arbin<T> & a) {
    vaciar(this);

    if (a.inicio == NULL )
        inicio = NULL;
    else
        inicio =  new NodoArbol(a.inicio->obtener_dato(), (a.inicio->obtener_izquierda()), (a.inicio->obtener_derecha()));

    return *this;
}

template class Arbin<int>;
//template class Arbin<char>;
//template class Arbin<float>;
//template class Arbin<Punto>;
//template class Arbin<Segmento>;
