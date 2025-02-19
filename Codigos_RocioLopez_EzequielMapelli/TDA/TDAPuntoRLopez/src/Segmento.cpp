#include "Segmento.h"

Segmento::Segmento(const Punto& ext1, const Punto& ext2)
{
    this->ext1 = ext1;
    this->ext2 = ext2;
}

const Punto & Segmento::extremo1() const
{
    return ext1;
}

const Punto & Segmento::extremo2() const
{
    return ext2;
}

void Segmento::trasladar(float x, float y)
{
    ext1.trasladar(x, y);
    ext2.trasladar(x, y);
}

float Segmento::longitud() const
{
    return ext1.distancia(ext2);
}

bool Segmento::operator==(const Segmento & otroSegmento) const
{
    return (ext1 == otroSegmento.ext1) && (ext2 == otroSegmento.ext2);
}
