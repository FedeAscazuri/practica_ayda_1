#ifndef CONJUNTO_H
#define CONJUNTO_H
#include "Conjunto.h"
//#include "Punto.h";


template<class T>
class Conjunto
{
    public:
        Conjunto();
        void agregar(const T & elem);
        bool pertenece(const T & elem) const;
        void eliminar_ultimo();
        unsigned int tamanio() const;
        void eliminar(const T & elem);
        void uniion(Conjunto & otroConjunto);
        void interseccion(Conjunto & otroConjunto);
        T recuperar(unsigned int pos) const;
        ~Conjunto();
    private:
        struct nodo
        {
            T dato;
            nodo * ste;
        };
        nodo * inicio;
        nodo * fin;
        unsigned int cantidad;
};

#endif // CONJUNTO_H
