#ifndef FILA_H
#define FILA_H
#include "Fila.h"
//#include "Punto.h";



template<class T>
class Fila
{
    public:
        Fila(unsigned int tam);
        void agregar(const T & elem);
        bool esvacia() const;
        void eliminar();
        T recuperar() const;
        ~Fila();
    private:
        T * arreglo;
        unsigned int tam;
        unsigned int cant_elem_agregados;
};

#endif // FILA_H
