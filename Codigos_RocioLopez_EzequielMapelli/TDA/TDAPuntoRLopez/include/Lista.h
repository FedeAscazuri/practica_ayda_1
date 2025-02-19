#ifndef LISTA_H
#define LISTA_H
#include "Lista.h"
#include <cstddef>
#include "Punto.h";


template<class T>
class Lista
{
    public:
        Lista();
        void agregar_al_principio( const T & elem);
        void agregar_al_final( const T & elem);
        unsigned int longitud() const;
        void eliminar(unsigned int pos);
        T recuperar(unsigned int pos) const;
        void insertar(const T & elem, unsigned int pos);
        bool pertenece(const T & elem) const;
        void modificar(Lista & OtraLista);
        ~Lista();
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


#endif // LISTA_H
