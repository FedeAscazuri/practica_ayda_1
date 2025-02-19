#include <iostream>

using namespace std;

void mostrarMatriz(int matriz[9][8], int filas, int columnas){
    for(int f = 0; f < filas; f++){
        for(int c = 0; c < columnas; c++){
            cout<< " " << matriz[f][c];
        }
        cout<<endl;
    }
}

void torneoDeTenis(int matrizTorneo[9][8], int cantJugadores){
    if (cantJugadores == 2){
        matrizTorneo[cantJugadores][cantJugadores-1] = cantJugadores-1;
        matrizTorneo[cantJugadores-1][cantJugadores-1] = cantJugadores;
    }
    else{
        int mitadJ = cantJugadores/2;
        torneoDeTenis(matrizTorneo, mitadJ);
        //Para los cuadrantes izquierdos la cantidad de dias es de (n/2)-1.
        //Para los cuadrantes derechos, la cantidad de dias es de n/2.

        //Llenado del cuadrante INFERIOR IZQUIERDO:
        for (int i = mitadJ+1; i <= cantJugadores; i++){ //iteracion de los jugadores.
            for (int j = 1; j < mitadJ; j++){ //iteracion de los dias.
                matrizTorneo[i][j] = matrizTorneo[i-mitadJ][j] + mitadJ;
            }
        }

        //Llenado del cuadrante SUPERIOR DERECHO:
        for (int i = 1; i <= mitadJ; i++){ //Cargo la primer columna (cantJugadores/2).
            matrizTorneo[i][mitadJ] = i + mitadJ;
        }
        for (int i = 1; i <= mitadJ; i++){ //Cargo las columnas que siguen.
            for (int j = mitadJ+1; j <= cantJugadores-1; j++){
                if ((matrizTorneo[i][j-1] + 1) <= cantJugadores){
                    matrizTorneo[i][j] = matrizTorneo[i][j-1] + 1;
                }
                else{
                    matrizTorneo[i][j] = matrizTorneo[1][mitadJ];
                }
            }
        }

        //Llenado del cuadrante INFERIOR DERECHO:
        for (int i = mitadJ+1; i <= cantJugadores; i++){ //Cargo la primer columna (cantJugadores/2).
            matrizTorneo[i][mitadJ] = i - mitadJ;
        }
        for (int i = mitadJ+1; i <= cantJugadores; i++){ //Cargo las columnas que siguen.
            for (int j = mitadJ+1; j <= cantJugadores-1; j++){
                if ((matrizTorneo[i][j-1] -1) > 0){
                    matrizTorneo[i][j] = matrizTorneo[i][j-1] -1;
                }
                else{
                    matrizTorneo[i][j] = matrizTorneo[cantJugadores][mitadJ];
                }
            }
        }
    }
}

int main()
{
    //Declaracion de variables:
    int cantJugadores = 8;
    int matrizTorneo[9][8]; //NO uso ni la fila ni la columna 0.
    for (int i = 0; i <= cantJugadores; i++){
        for (int j = 0; j < cantJugadores; j++){
            matrizTorneo[0][j] = 0;
            matrizTorneo[i][0] = 0;
        }
    }
    torneoDeTenis(matrizTorneo, cantJugadores);
    mostrarMatriz(matrizTorneo, 9, 8);
    return 0;
}
