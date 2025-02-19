//
// Created by giuli on 7/3/2021.
//

#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector(int t){
    this->t = t;
    for(int i = 0; i < t; i++)
        v[i] = INT_MAX;
}

Vector::Vector(int v[], int t) {
    for (int i = 0; i < t; i++)
        this->v[i] = v[i];
    this->t = t;
}

void Vector::setLongitud(int t) {
    this->t = t;
}

int Vector::longitud() {return t;}

void Vector::agregar(int e) {
    int i = 0;
    while ((i < t) && (v[i] < INT16_MAX))
        i++;
    if (i < t)
        v[i] = e;
}

int Vector::getElem(int pos) {
    return v[pos];
}

int Vector::getPos(int elem) {
    for(int i = 0; i < t && v[i] < INT16_MAX; i++)
        if(v[i] == elem) return v[i];
    return INT_MAX;
}
