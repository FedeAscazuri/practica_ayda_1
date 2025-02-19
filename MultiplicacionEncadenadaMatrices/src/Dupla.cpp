#include "Dupla.h"

Dupla::Dupla(int elem1, int elem2)
{
    primerElem = elem1;
    segundoElem = elem2;
}

int Dupla::accederPrimero() const
{
    return primerElem;
}

int Dupla::accederSegundo() const
{
    return segundoElem;
}

void Dupla::modificarPrimero(int nuevoElem)
{
    primerElem = nuevoElem;
}

void Dupla::modificarSegundo(int nuevoElem)
{
    segundoElem = nuevoElem;
}

void Dupla::multiplicar(int valor)
{
    primerElem = primerElem * valor;
    segundoElem = segundoElem * valor;
}

void Dupla::sumar(Dupla otraDupla)
{
    primerElem = primerElem + otraDupla.accederPrimero();
    segundoElem = segundoElem + otraDupla.accederSegundo();
}

void Dupla::restar(Dupla otraDupla)
{
    primerElem = primerElem - otraDupla.accederPrimero();
    segundoElem = segundoElem - otraDupla.accederSegundo();
}

