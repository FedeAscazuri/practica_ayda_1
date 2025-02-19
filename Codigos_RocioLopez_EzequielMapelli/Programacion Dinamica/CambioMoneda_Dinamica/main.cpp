#include <iostream>

using namespace std;

void devolverMonedas(int cantMonedasMin[3][9], int valores[3], int n, int vuelto){
    int j = vuelto;
    int i = n-1;
    int numeroIteracion = 0;
    cout << "Las monedas a devolver son las siguientes: " << endl;
    while (cantMonedasMin[i][j] != 0){
        if (cantMonedasMin[i][j] == cantMonedasMin[i-1][j]){
            i = i-1;
        }
        else{
            if (cantMonedasMin[i][j] == 1 + cantMonedasMin[i][j-valores[i]]){
                cout << valores[i] << endl;
                j = j - valores[i];
            }
        }
    }
}

void cambioMonedas(int cantMonedasMin[3][9], int valores[3], int n, int vuelto){
    //Inicializacion de cantMonedasMin:
    //para dar un vuelto j = 0 --> para cualquier valor de i la cantidad de monedas a dar es 0.
    for (int i = 0; i < n; i++){
        cantMonedasMin[i][0] = 0;
    }
    //Resuelvo:
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= vuelto; j++){
            int vueltoDado;
            if (i == 0){ //Estoy en la moneda de menor valor, por ende puedo usar esta unica moneda como vuelto.
                if (j < valores[i]){ //si el vuelto que tengo que dar es menor al valor de mi moneda de mas chica (de menor valor)...
                    cantMonedasMin[i][j] = -1; //... --> no puedo dar un vuelto.
                }
                else{ //si el vuelto que tengo que dar es mayor al valor de mi moneda más chica --> puedo dar un vuelto solo usando esa moneda.
                    vueltoDado = valores[i];
                    //doy una moneda de valor v0 y sumo la cantidad de monedas que tengo que dar usando...
                    //... monedas de hasta valor v0 y con un vuelto de j - el vuelto que ya di cuando sume una moneda de valor v0, osea, el resto del vuelto que me falta dar.
                    cantMonedasMin[i][j] = 1 + cantMonedasMin[i][j-vueltoDado];
                }
            }
            else{ //No estoy en mi moneda más chica --> puedo usar monedas de hasta valor vi.
                if (j < valores[i]){ //si el vuelto que tengo que dar es menor al valor de la moneda vi (la de mayor valor en esta instancia)...
                    cantMonedasMin[i][j] = cantMonedasMin[i-1][j]; //... me fijo si puedo dar el vuelto con monedas de menor valor (i-1).
                }
                else{//si el vuelto que tengo que dar es mayor o igual al valor de la moneda vi (la de mayor valor en esta instancia)...
                    //... debo elegir el caso que menor cantidad de monedas use:
                    //Caso 1: usar monedas de menor valor a vi.
                    //Caso 2: usar al menos una moneda de valor vi.
                    vueltoDado = valores[i];
                    int cantMonedasCaso2 = 1 + cantMonedasMin[i][j-vueltoDado];
                    if (cantMonedasMin[i-1][j] < cantMonedasCaso2){
                        cantMonedasMin[i][j] = cantMonedasMin[i-1][j];
                    }
                    else{
                        cantMonedasMin[i][j] = cantMonedasCaso2;
                    }
                }
            }
        }
    }
    cout << "La cantidad de monedas que se deben usar son: " << cantMonedasMin[n-1][vuelto] << endl;
    devolverMonedas(cantMonedasMin, valores, n, vuelto);
}

int main()
{
    //Definicion de estructuras:

    int n = 3; //cantidad de diferentes valores de monedas.
    //valores[i] = valor de la moneda referenciada por i.
    int valores[3]; //van desde i = 0 hasta i = n-1.
    int vuelto = 8;
    //cantMonedasMin[i][j] = cantidad de monedas de hasta valor vi (valores[i]) minima
    // para dar un vuelto j.
    int cantMonedasMin[3][9];//Las filas (i) van de 0 a n-1, por lo tanto son n filas.
    //Las columnas (j) van de 0 a vuelto, por lo tanto son vuelto+1 columnas.
    //En la posicion cantMonedasMin[n-1][vuelto] tendré la solución.

    //Cargo Valores:
    valores[0] = 1;
    valores[1] = 4;
    valores[2] = 6;

    cambioMonedas(cantMonedasMin, valores, n, vuelto);

    return 0;
}
