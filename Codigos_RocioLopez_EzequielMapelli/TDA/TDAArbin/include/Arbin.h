#ifndef ARBIN_H
#define ARBIN_H
//#include "Punto.h";
//#include "Segmento.h";


template <typename T>
class Arbin {
private:
    class NodoArbol {
        public:
            //Con la sig. linea digo que el constructor de NodoArbol recibe dichos parametros (elem, l y r)
            //y a la derecha le asigno a sus variables internas (dato, pizq y pder) los valores pasados por parametro.
            NodoArbol(const T & elem, Arbin* l, Arbin* r): dato(elem), pizq(l), pder(r) {};
            const T & obtener_dato() const {return dato;} 
            Arbin * obtener_izquierda() const {return pizq;} //Te devuelve un puntero a un Arbin.
            Arbin * obtener_derecha() const {return pder;} //Te devuelve un puntero a un Arbin.
        private:
            //Variables internas de NodoArbol.
            T dato;
            Arbin* pizq;
            Arbin* pder;
    };

    void vaciar (Arbin* raiz); //Defino el método que vacía el arbin (lo uso en el destructor) como privado.

public:
    Arbin(); //Un constructor.
    virtual ~Arbin();

    Arbin(const Arbin& otroArbol);//Otro constructor.
    void construir(Arbin* izq, Arbin* der, const T & dato);

    const T & raiz() const ;
    Arbin* arbol_izquierdo() const; //Te devuelve un puntero a un Arbin.
    Arbin* arbol_derecho() const; //Te devuelve un puntero a un Arbin.

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
