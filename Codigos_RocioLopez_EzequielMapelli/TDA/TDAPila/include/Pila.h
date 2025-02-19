#ifndef PILA_H
#define PILA_H
#include "Pila.h"

template<typename T>
class Pila
{
    public:
        Pila(unsigned int tam);
        void agregar_a_tope(const T & elem);
        bool es_vacia() const;
        T tope() const;
        void eliminar_tope();
        int tamanio() const;
        ~Pila();
    private:
        T * arreglo;
        unsigned int tam;
        unsigned int cant_elem_agregados;
};

#endif // PILA_H
