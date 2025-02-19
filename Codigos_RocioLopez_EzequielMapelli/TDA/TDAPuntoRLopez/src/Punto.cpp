#include "Punto.h"
#include <cmath>

Punto::Punto()
{
    this->x = 0;
    this->y = 0;
}

Punto::Punto(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Punto::coordX() const
{
    return x;
}

float Punto::coordY() const
{
    return y;
}

float Punto::distancia(const Punto & otroPunto) const
{
    return sqrt(pow(x-otroPunto.x, 2.0) + pow(y-otroPunto.y, 2.0));
}

void Punto::trasladar(float x, float y)
{
   this->x += x;
   this->y += y;
}

bool Punto::operator==(const Punto & otroPunto) const
{
    return (x == otroPunto.x) && (y == otroPunto.y);
}

Punto & Punto::operator=(const Punto & otroPunto)
{
    this->x = otroPunto.x;
    this->y = otroPunto.y;

    return *this;
}
