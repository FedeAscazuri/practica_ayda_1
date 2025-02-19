#include "Tabla.h"
#include <assert.h>

//Constructor
Tabla::Tabla(int cantFil, int cantCol)
{
    filas = cantFil;
    columnas = cantCol;
    tabla = new int*[filas]; //tabla apunta a un arreglo dinamico de punteros a enteros,
    //aunque sea en realidad un puntero a arreglo de enteros, lo que le interesa es el tipo
    //del valor que se encuentra al final, osea int.
    for (int pos=0; pos<filas; pos++){
        tabla[pos] = new int[columnas]; //creo un arreglo dinamico en el heap x cada puntero a entero.
    }
    //Inicializo con un valor discernible.
    for (int f=0; f<filas; f++){
        for (int c=0; c<columnas; c++){
            tabla[f][c] = -100;
        }
    }
}

void Tabla::agregar(int valor, int fil, int col)
{
    tabla[fil][col] = valor;
}

bool Tabla::vaciaCelda(int fil, int col) const
{
    if (tabla[fil][col] == -100){
        return true;
    }
    else{
        return false;
    }
}

int Tabla::valorCelda(int fil, int col) const
{
    assert(not vaciaCelda(fil,col));
    return tabla[fil][col];
}

int Tabla::mayorEntero() const
{
    int mayor = tabla[0][0];
    for (int f=0; f<filas; f++){
        for (int c=1; c<columnas; c++){
            if ((tabla[f][c] != -100) && (tabla[f][c] > mayor)){
                mayor = tabla[f][c];
            }
        }
    }
    return mayor;
}

int Tabla::sumaColum(int col) const
{
    int suma = 0;
    for (int f=0; f<filas; f++){
        if (tabla[f][col] != -100){
            suma = suma + tabla[f][col];
        }
    }
    return suma;
}

//Destructor
Tabla::~Tabla()
{
    int *aux;
    for (int pos=0; pos<filas; pos++){
        aux = tabla[pos];
        delete(aux);
    }
    delete(tabla);
}
