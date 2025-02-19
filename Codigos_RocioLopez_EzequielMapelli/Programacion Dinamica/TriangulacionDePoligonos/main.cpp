#include <iostream>
#include <limits>

void mostrarSolucion(int solucion[6][5], int s);
void triangulacionPoligonos(int distancias[5][5], int costos[6][5], int solucion[5][5], int s);

using namespace std;

int main(){
    //Declaracion de estructuras

    int s = 5; //Cuantos vertices tiene el poligono
    int distancias[5][5];
    //costos:
    // 6 (s + 1) filas porque puedo tener desde 0 a 5 vertices (representan a s en la formula). Tamaño del problema.
    // 5 columnas porque puedo arrancar del vertice 0 al 4 (representan a i en la formula).
    int costos[6][5];
    int solucion[6][5];

    //Carga de distancias
    for (int p = 0; p < 5; p++){
        distancias[p][p] = 0;
    }
    distancias[0][1] = 1;
    distancias[0][2] = 4;
    distancias[0][3] = 4;
    distancias[0][4] = 3;
    distancias[1][2] = 2;
    distancias[1][3] = 3;
    distancias[1][4] = 4;
    distancias[2][3] = 2;
    distancias[2][4] = 4;
    distancias[3][4] = 1;

    triangulacionPoligonos(distancias, costos, solucion, s);

    return 0;
}

void mostrarSolucion(int solucion[6][5], int i, int s){
    if (i == 3){
        cout << "Hay una diagonal entre los vertices: " << "V" << s << ", " << "V" << s+i-1 << endl;
    }
    else{
        int k = solucion[i][s];
        mostrarSolucion(solucion, i-k, k);
        mostrarSolucion(solucion, k+1, s);
    }

}

void triangulacionPoligonos(int distancias[5][5], int costos[6][5], int solucion[6][5], int s){
    //Inicializacion de costos:
        //cuando tengo 0 vertices (f = 0, o s = 0 en la formula) no tiene sentido --> pongo 0;
        //la distancia desde cualquier vertice y teniendo un solo vertice (f = 1, o s = 1 en la formula) es la distancia a si mismo --> pongo 0;
    for (int f = 0; f < 2; f++){
        for (int c = 0; c < s; c++){
            costos [f][c] = 0;
            solucion [f][c] = 0;
        }
    }
    //Resolucion de caso base:
        //cuando tengo (f = 2, osea s = 2 en la formula) entonces el costo es 0.
        //cuando tengo (f = 3, osea s = 3 en la formula) entonces el costo es 0. Triangular un triangulo no tiene costo.
    for (int c = 0; c < s; c++){
        costos[2][c] = 0;
        costos[3][c] = 0;
        solucion[2][c] = 0;
        solucion[3][c] = 0;
    }
    //Resolucion:
    for (int f = 4; f <= s; f++){
        for(int c = 0; c <= s - f; c++){
            int minCosto = INT_MAX;
            int kMin = 0;
            for(int k = 1; k <= f-2; k++){
                cout<<endl;
                cout<< "Voy a calcular al poligono  " << f << ", " << c << " con k " << k <<endl;
                cout<< "      Utiliza el costo de  " << k+1 << ", " << c << " que es " << costos[k+1][c] <<endl;
                cout<< "      Utiliza el costo de  " << f-k << ", " << c+k << " que es " << costos[f-k][c+k] <<endl;
                cout<< "      Utiliza la distancia de  " << c << ", " << c+k << " que es " << distancias[c][c+k] <<endl;
                cout<< "      Utiliza la distancia de  " << c+k << ", " << c+f-1 << " que es " << distancias[c+k][c+f-1] <<endl;
                int costo = costos[k+1][c] + costos[f-k][c+k] + distancias[c][c+k] + distancias[c+k][c+f-1];
                if (costo < minCosto){
                    minCosto = costo;
                    solucion[f][c] = k;
                    kMin = k;
                }
            }
            cout<< "          El costo minimo en el poligono " << f << ", " << c << " es de " << minCosto << " con k = " << kMin <<endl;
            costos[f][c] = minCosto;
        }
    }
    cout << "El costo minimo del poligono de 5 vertices y que empieza en 0 es de: " << costos[5][0] << endl;
    mostrarSolucion(solucion, 5, 0);
}
