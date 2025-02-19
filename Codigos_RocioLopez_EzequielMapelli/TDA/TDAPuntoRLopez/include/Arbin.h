#ifndef ARBIN_H
#define ARBIN_H
//#include "Punto.h";
//#include "Segmento.h";


template <typename T>
class Arbin {
private:
    class NodoArbol {
        public:
            NodoArbol(const T & elem, Arbin* l, Arbin* r): dato(elem), pizq(l), pder(r) {};
            const T & obtener_dato() const {return dato;}
            Arbin * obtener_izquierda() const {return pizq;}
            Arbin * obtener_derecha() const {return pder;}
        private:
            T dato;
            Arbin* pizq;
            Arbin* pder;
    };

    void vaciar (Arbin* raiz);

public:
    Arbin();
    virtual ~Arbin();

    Arbin(const Arbin& otroArbol);
    void construir(Arbin* izq, Arbin* der, const T & dato);

    const T & raiz() const ;
    Arbin* arbol_izquierdo() const;
    Arbin* arbol_derecho() const;

    bool es_vacio() const;
    bool es_hoja() const;
    bool pertenece(T elemento) const;
    unsigned int Altura_Arbol() const;
    unsigned int Cant_Nodos() const;

    Arbin & operator= (const Arbin & otroArbol);

private:
    NodoArbol* inicio;
};

#endif // ARBIN_H
