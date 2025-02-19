#include <iostream>
#include <limits>

using namespace std;

void crearMatrizDinamica(int ** & matriz, int filas, int columnas){
    matriz = new int*[filas];//matriz apunta a un arreglo dinamico de punteros a enteros,
    //aunque sea en realidad un puntero a arreglo de enteros, lo que le interesa es el tipo
    //del valor que se encuentra al final, osea int.
    for (int pos = 0; pos < filas; pos++){
        matriz[pos] = new int[columnas]; //creo un arreglo dinamico en el heap x cada puntero a entero.
    }
}

int sumaValoresArreglo(int arreglo[8], int comienzo, int fin){
    int suma = 0;
    for (int pos = comienzo; pos <= fin; pos++){
        suma = suma + arreglo[pos];
    }
    return suma;
}

void mostrarResultado(int ** mejorSolucion, int frontera[8], int i, int j){
    if (i == j){
        cout << "hoja: " << frontera[i] <<endl;
    }
    else{
        cout << "Raiz: " << sumaValoresArreglo(frontera, i, j) << endl;
        cout << " El lado IZQUIERDO de la raiz " << sumaValoresArreglo(frontera, i, j) << " es: " <<endl;
        mostrarResultado(mejorSolucion, frontera, i, mejorSolucion[i][j]);
         cout << " El lado DERECHO de la raiz " << sumaValoresArreglo(frontera, i, j) << " es: " << endl;
        mostrarResultado(mejorSolucion, frontera, mejorSolucion[i][j] + 1, j);
    }
}

void arbinMinimoCosto(int ** & costoArbin, int ** & mejorSolucion, int frontera[8], int cantHojas){
    //Inicializacion:
    for (int p = 0; p <= cantHojas; p++){
        //el costo de un arbol binario que usa los valores de hoja desde p hasta p es de 0.
        costoArbin[p][p] = 0;
        mejorSolucion[p][p] = 0;
    }

    //Resuelvo:
    for (int d = 1; d < cantHojas; d++){ // 1er for: representa la diagonal en la que estoy. Tengo cantHojas-1 diagonales.
        for (int i = 1; i <= cantHojas-d; i++){ // 2do for: representa la fila en la que estoy.
            int j = i+d; // declaracion que representa la columna en la que estoy.
            int menorCosto = INT_MAX;
            for (int k = i; k < j; k++){
                int sumaHojas = sumaValoresArreglo(frontera, i, j);
                int costoActual = costoArbin[i][k] + costoArbin[k+1][j] + sumaHojas;
                if (costoActual < menorCosto){
                    menorCosto = costoActual;
                    costoArbin[i][j] = costoActual;
                    mejorSolucion[i][j] = k;
                }
            }
        }
    }
    cout << "El costo del arbol binario de minimo costo es de: " << costoArbin[1][7] << endl;
    mostrarResultado(mejorSolucion, frontera, 1, cantHojas);
}
int main()
{
    //Declaracion de variables:
    int cantHojas = 7; //Valores
    int frontera[cantHojas+1]; //cantValores+1 porque el valor 0 de frontera no lo cuento.
    int **costoArbin; //costoArbin[i][j] me devuelve el costo del arbol óptimo con la secuencia de nodos hojas que va desde i hasta j.
    crearMatrizDinamica(costoArbin, cantHojas+1, cantHojas+1);
    int **mejorSolucion; //mejorSolucion[i][j] me devuelve un valor k que indica como separo los valores hoja para formar el arbon de minimo costo:
     // los valores desde i hasta k van a la izquierda y los valores desde k+1 hasta j van a la derecha. La raiz es la suma de los valores desde i hasta j.
    crearMatrizDinamica(mejorSolucion, cantHojas+1, cantHojas+1);

    //Cargo variables:
    for (int pos = 0; pos <= cantHojas; pos++){
        //NO uso la fila ni la columna 0.
        costoArbin[0][pos] = 0;
        costoArbin[pos][0] = 0;
        mejorSolucion[0][pos] = 0;
        mejorSolucion[pos][0] = 0;
    }
    frontera[0] = 0;
    frontera[1] = 4;
    frontera[2] = 4;
    frontera[3] = 8;
    frontera[4] = 5;
    frontera[5] = 4;
    frontera[6] = 3;
    frontera[7] = 5;

    arbinMinimoCosto(costoArbin, mejorSolucion, frontera, cantHojas);

    return 0;
}
