#ifndef SEGMENTO_H
#define SEGMENTO_H
#include "Punto.h"

class Segmento
{
    public:
        //Costructor por parametros.
        Segmento(const Punto & ext1 , const Punto & ext2);
        const Punto & extremo1() const;
        const Punto & extremo2() const;
        void trasladar(float x, float y);
        float longitud() const;
        //Operador de comparacion.
        bool operator==(const Segmento & otroSegmento) const;

        //operador de asignacion.
        //Segmento & operator=(const Segmento & otroSegmento);

        //~Segmento();

    private:
        Punto ext1;
        Punto ext2;
};

#endif // SEGMENTO_H
