#include <iostream>

using namespace std;

int main()
{
    int tamanio = 8;
    int matriz[9][9]; //No usamos la fila/columna 0.
    for (int p = 0; p <= tamanio; p++){
        matriz[0][p] = -1;
        matriz[p][0] = -1;
    }
    int direcciones[(tamanio*tamanio)/2];
    int valores[tamanio*tamanio];
    int indiceDirec = 1;
    int indiceVal = 1;
    int inicF = 1;
    int finF = 8;
    int inicC = 1;
    int finC = 8;
    return 0;
}

bool tieneCeroMatriz(int matriz[9][9], int inicF, int finF, int inicC, int finC){
    bool tieneCero = false;
    int f = inicF;
    int c = inicC;
    while ((!tieneCero) && (f <= finF)){
        while ((!tieneCero) && (c <= finC)){
            if (matriz[f][c] == 0){
                tieneCero = true;
            }
            f+2;
            c+2;
        }
    }
    return tieneCero;
}

bool esCeroCuadrante(int matriz[9][9], int inicF, int finF, int inicC, int finC){
    bool ceroCuadrante = true;
    int f = inicF;
    int c = inicC;
    while ((!ceroCuadrante) && (f <= finF)){
        while ((!ceroCuadrante) && (c <= finC)){
            if (matriz[f][c] != 0){
                ceroCuadrante = false;
            }
            f+2;
            c+2;
        }
    }
    return ceroCuadrante;
}

void quadTree(int matriz[9][9], int direcciones[], int valores[], int tamanio, int inicF, int finF, int inicC, int finC, int indiceDirec, int & indiceVal){
    if(inicF < finF){
        if (!tieneCeroMatriz(matriz, inicF, finF, inicC, finC)){
            direcciones[indiceDirec] = -indiceVal;
            int indiceValActual = indiceVal;
            for (int f = inicF; f <= finF; f++){
                for (int c = inicC; c <= finC; c++){
                    valores[indiceValActual] = matriz[f][c];
                    indiceValActual++;
                }
            }
            indiceVal = indiceValActual;
        }
        else{
            if(esCeroCuadrante(matriz, inicF, finF, inicC, finC)){
                direcciones[indiceDirec] = 0;
            }
            else{
                int mitad = tamanio/2;
                quadTree(matriz, direcciones, valores, tamanio/2, inicF, mitad, inicC, mitad, (indiceDirec*4)+1, indiceVal);
                quadTree(matriz, direcciones, valores, tamanio/2, inicF, mitad, mitad, finC, ((indiceDirec+1)*4)+1, indiceVal);
                quadTree(matriz, direcciones, valores, tamanio/2, mitad, finF, inicC, mitad, ((indiceDirec+2)*4)+1, indiceVal);
                quadTree(matriz, direcciones, valores, tamanio/2, mitad, finF, mitad, finC, ((indiceDirec+3)*4)+1, indiceVal);
            }
        }
    }
}
