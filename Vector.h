//
// Created by giuli on 7/3/2021.
//

#ifndef EJ8DYC___MEDIANA_DE_VECTORES_VECTOR_H
#define EJ8DYC___MEDIANA_DE_VECTORES_VECTOR_H


class Vector {
public:
    Vector(int t);
    Vector(int v[], int t);
    void agregar(int e);
    int getElem (int pos);
    int getPos (int elem);
    int longitud();
    void setLongitud(int t);
private:
    int t;
    int v[];
};


#endif //EJ8DYC___MEDIANA_DE_VECTORES_VECTOR_H
