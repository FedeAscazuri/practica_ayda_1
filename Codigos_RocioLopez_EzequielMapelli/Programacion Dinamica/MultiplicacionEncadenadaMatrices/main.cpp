#include <iostream>
#include <limits>

using namespace std;

void crearMatrizDinamica(int ** & matriz, int filas, int columnas){
    matriz = new int*[filas];//matriz apunta a un arreglo dinamico de punteros a enteros,
    //aunque sea en realidad un puntero a arreglo de enteros, lo que le interesa es el tipo
    //del valor que se encuentra al final, osea int.
    for (int pos=0; pos<filas; pos++){
        matriz[pos] = new int[columnas]; //creo un arreglo dinamico en el heap x cada puntero a entero.
    }
}

void mostrarSolucion(int ** mejorSolucion, int i, int j){
    if (i == j){
        cout << "M" << i;
    }
    else{
        cout << "(";
        mostrarSolucion(mejorSolucion, i, mejorSolucion[i][j]); //desde i a k.
        mostrarSolucion(mejorSolucion, mejorSolucion[i][j] + 1, j); //desde k+1 a j.
        cout << ")";
    }
}

void multEncadenadaMatrices(int ** & cantProductos, int ** & mejorSolucion, int dimensiones[6], int cantMatrices){
    //Inicializacion:
    for (int p = 1; p <= cantMatrices; p++){ //se carga la diagonal 0 con ceros.
    //el resultado de multiplicar desde la matriz Mp hasta la matriz Mp es 0.
        cantProductos[p][p] = 0;
        mejorSolucion[p][p] = 0;
    }
    //Resuelvo:
    for (int d = 1; d < cantMatrices; d++){ //d representa la diagonal en la que estoy. Tengo cantMatrices-1 diagonales.
        for(int i = 1; i <= cantMatrices-d; i++){ //i representa que valores de filas tengo q llenar en la diagonal en la que estoy.
            int j = i+d; //j representa que valores de columnas tengo que llenar en la diagonal en la que estoy.
            int minCantProduct = INT_MAX;
            for (int k = i; k < j; k++){ //k representa la particion, osea, de i hasta k hay una divisi�n y desde k+1 a j hay otra.
                int cantProductActual = cantProductos[i][k] + cantProductos[k+1][j] + (dimensiones[i-1] * dimensiones[k] * dimensiones[j]);
                if (minCantProduct > cantProductActual){
                    cantProductos[i][j] = cantProductActual;
                    mejorSolucion[i][j] = k;
                    minCantProduct = cantProductActual;
                }
            }
        }
    }
    cout << "La menor cantidad de productos para multiplicar matrices desde la matriz M1 hasta la matriz M" << cantMatrices << " es: " << cantProductos[1][cantMatrices] <<endl;
    cout << "El orden en el que se deben multiplicar es:" << endl;
    mostrarSolucion(mejorSolucion, 1, cantMatrices);
}

int main()
{
    //Declaracion de variables:
    int **cantProductos;
    int **mejorSolucion;
    int cantMatrices = 6; //6 matrices: M1,..., M6.
    crearMatrizDinamica(cantProductos, cantMatrices+1, cantMatrices+1); // cantMatrices+1 asi puedo tener las matrices de la 1 a la 6.
    crearMatrizDinamica(mejorSolucion, cantMatrices+1, cantMatrices+1);
    int dimensiones[cantMatrices+1]; //Guardo en un arreglo de enteros las dimensiones de las COLUMNAS de cada matriz.
    // --> en dimensiones[i] se encuentra la cantidad de COLUMNAS de la matriz Mi (M sub i) y se sabe que tiene dimensiones[i-1] FILAS.

    //Inicializacion de variables:
    dimensiones[0] = 30;
    dimensiones[1] = 35;
    dimensiones[2] = 15;
    dimensiones[3] = 5;
    dimensiones[4] = 10;
    dimensiones[5] = 20;
    dimensiones[6] = 25;
    for (int pos = 0; pos <= cantMatrices; pos++){
        //No usar� ni la fila ni la columna 0 ya que considero que no existe matriz M0.
        cantProductos[0][pos] = 0;
        cantProductos[pos][0] = 0;
        mejorSolucion[0][pos] = 0;
        mejorSolucion[pos][0] = 0;
    }

    multEncadenadaMatrices(cantProductos, mejorSolucion, dimensiones, cantMatrices);

    return 0;
}
