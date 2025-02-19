#include <iostream>

using namespace std;

void crearMatrizDinamica(int ** & matriz, int filas, int columnas){
    matriz = new int*[filas];//matriz apunta a un arreglo dinamico de punteros a enteros,
    //aunque sea en realidad un puntero a arreglo de enteros, lo que le interesa es el tipo
    //del valor que se encuentra al final, osea int.
    for (int pos=0; pos<filas; pos++){
        matriz[pos] = new int[columnas]; //creo un arreglo dinamico en el heap x cada puntero a entero.
    }
}

void mostrarSubcadenaComunMax(char matrizConstruccion[8][7], char cadena1[8], int tam1, int tam2){
    int i = tam1 - 1;
    int j = tam2 - 1;
    char solucion[tam2]; //arreglo solucion es del tama�o de la cadena mas chica.
    int pos = 0;
    while ((matrizConstruccion[i][j] != 'V') && (i > 0) && (j > 0)){
        if (matrizConstruccion[i][j] == 'A'){
            i--;
        }
        else{
            if (matrizConstruccion[i][j] == 'I'){
                j--;
            }
            else{
                if (matrizConstruccion[i][j] == 'D'){
                    solucion[pos] = cadena1[i];
                    pos++;
                    i--;
                    j--;
                }
            }
        }
    }
    cout << "La subcadena comun maxima es:" << endl;
    for (int p = pos-1; p >= 0; p--){
        cout << solucion[p] << endl;
    }
}

void subsecuanciaComunMax(int ** & longSubcadenaMax, char matrizConstruccion[8][7], char cadena1[8], char cadena2[7], int tam1, int tam2){
    //Inicializaci�n de matrices:
    // si alguna de las subcadenas est� vac�a --> la long de la subcadena maxima es 0, ya que no hay subcadena en comun.
    for (int f = 0; f < tam1; f++){
        longSubcadenaMax[f][0] = 0;
    }
    for (int c = 0; c < tam2; c++){
        longSubcadenaMax[0][c] = 0;
    }
    // como los indices de matrizConstruccion representan lo mismo que los de longSubcadenaMax
    // --> cuando alguna subcadena este vacia --> no tengo soluci�n que devolver.
    for (int f = 0; f < tam1; f++){
        matrizConstruccion[f][0] = 'V'; //V = vacio.
    }
    for (int c = 0; c < tam2; c++){
        matrizConstruccion[0][c] = 'V';
    }

    //Resuelvo:
    for (int i = 1; i < tam1; i++){
        for (int j = 1; j < tam2; j++){
            if (cadena1[i] == cadena2[j]){
                longSubcadenaMax[i][j] = 1 + longSubcadenaMax[i-1][j-1];
                matrizConstruccion[i][j] = 'D';
            }
            else{
                int longCasoArriba = longSubcadenaMax[i-1][j];
                if (longSubcadenaMax[i][j-1] > longCasoArriba){
                    longSubcadenaMax[i][j] = longSubcadenaMax[i][j-1];
                    matrizConstruccion[i][j] = 'I';
                }
                else{
                    longSubcadenaMax[i][j] = longCasoArriba;
                    matrizConstruccion[i][j] = 'A';
                }
            }
        }
    }
    cout << "La longitud de la subcadena maxima es de: " << longSubcadenaMax[tam1-1][tam2-1] << endl;
    mostrarSubcadenaComunMax(matrizConstruccion, cadena1, tam1, tam2);
}

int main()
{
    //Declaraci�n de variables:

    int tam1 = 8; //filas de la matriz longSubcadenaMax.
    int tam2 = 7; //columnas de la matriz longSubcadenaMax.

    char cadena1[tam1]; //la cadena 1 tendra tam1-1 caracteres que van desde cadena1[1] hasta...
        //... cadena1[tam1-1]. La posicion cadena1[0] denota la cadena vacia.
    char cadena2[tam2]; //la cadena 2 tendra tam2-1 caracteres que van desde cadena2[1] hasta...
        //... cadena2[tam2-1]. La posicion cadena2[0] denota la cadena vacia.

    int **longSubcadenaMax; // longSubcadenaMax[i][j] me devuelve la longitud de la subcadena comun maxima
        // entre los caracteres 1 e i de la cadena1 y los caracteres 1 y j de la cadena2.
    crearMatrizDinamica(longSubcadenaMax, tam1, tam2);

    char matrizConstruccion[8][7];
        // matrizConstruccion[i][j] me dice que camino seguir para encontrar la solucion al problema i,j.
        // Para devolver la solucion debo ver si en matrizConstruccion[i][j] hay una:
        // caso 1): A --> tengo que mirar a donde me lleva matrizContruccion[i-1][j]
        // caso 2): I --> tengo que mirar a donde me lleva matrizContruccion[i][j-1]
        // caso 3): D --> el caracter que se encuentra en cadena1[i] y en cadena2[j] es el mismo...
                    //... y debo a�adirlo a la solucion.

    //Cargar cadenas:
    cadena1[0] = 'V';
    cadena1[1] = 'A';
    cadena1[2] = 'B';
    cadena1[3] = 'C';
    cadena1[4] = 'B';
    cadena1[5] = 'D';
    cadena1[6] = 'A';
    cadena1[7] = 'B';

    cadena2[0] = 'V';
    cadena2[1] = 'B';
    cadena2[2] = 'D';
    cadena2[3] = 'C';
    cadena2[4] = 'A';
    cadena2[5] = 'B';
    cadena2[6] = 'A';

    subsecuanciaComunMax(longSubcadenaMax, matrizConstruccion, cadena1, cadena2, tam1, tam2);

    return 0;
}
