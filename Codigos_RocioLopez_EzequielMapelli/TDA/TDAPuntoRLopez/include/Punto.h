#ifndef PUNTO_H_INCLUDED
#define PUNTO_H_INCLUDED

class Punto
{
    public:
        //Constructor que inicializa un punto en el origen.
        //Necesario para definir tipos de datos que usan a Punto como estructura de implementacion.
        Punto();

        //Constructor por parametros.
        Punto(float x, float y);
        float coordX() const;
        float coordY() const;
        float distancia(const Punto & otroPunto) const;
        void trasladar (float x, float y);

        //Operador de comparacion
        bool operator==(const Punto & otroPunto) const;

        //Operador de asignacion.
        Punto & operator=(const Punto & otroPunto);

    private:
        float x;
        float y;
};

#endif // PUNTO_H_INCLUDED
