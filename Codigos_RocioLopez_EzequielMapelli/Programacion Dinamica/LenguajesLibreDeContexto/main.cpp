#include <iostream>
#include <string>
#include "Conjunto.h"

using namespace std;

void mostrarConjunto(Conjunto<string> conjunto){
    if (conjunto.vacioConjunto()){
        cout << "El conjunto está vacio." << endl;
    }
    else{
        cout << endl;
        for (int p = 1; p <= conjunto.tamanio(); p++){
            cout << conjunto.recuperar(p) << ", ";
        }
    }
}

void decibilidadLengLibresContexto(Conjunto<string> matrizDecibilidad[6][6], Conjunto<string> reglasANoTerminales[5], Conjunto<string> reglasATerminales[5], string noTerminales[5], string cadena[6], int cantElemCadena, int cantNoTerminales){
    //Inicializacion (caso base):
    cout << "COMIENZO de la inicializacion... ";
    for (int j = 1; j <= cantElemCadena; j++){
        string caracterActual = cadena[j];
        cout << endl;
        cout << "Al terminal: " << cadena[j] << " lo generan los NoTerminales--> ";
        for (int noT = 1; noT <= cantNoTerminales; noT++){ //noT: no terminal
            if (reglasATerminales[noT].pertenece(caracterActual)){
                cout << noTerminales[noT] << " ";
                matrizDecibilidad[1][j].agregar(noTerminales[noT]);
            }
        }
    }
    cout << endl;
    cout << "FIN de la inicializacion." << endl;
    //Resolucion:
    for (int i = 2; i <= cantElemCadena; i++){ //Tamaño del problema.
        for (int j = 1; j <= cantElemCadena+1-i; j++){ //Desde que letra empiezo.
            for (int k = 1; k < i; k++){
                for (int noT = 1; noT <= cantNoTerminales; noT++){
                    for (int regla = 1; regla <= reglasANoTerminales[noT].tamanio(); regla++){
                        char caractIzq = reglasANoTerminales[noT].recuperar(regla)[0];
                        char caractDer = reglasANoTerminales[noT].recuperar(regla)[1];
                        std::string cI(1, caractIzq); //casting de char a string.
                        std::string cD(1, caractDer);
                        cout << "Caracter IZQ = " << cI << "  ";
                        cout << "Caracter DER = " << cD << endl;
                        if ((matrizDecibilidad[k][j].pertenece(cI)) && (matrizDecibilidad[i-k][j+k].pertenece(cD))){
                            string valorNoTerminal = noTerminales[noT];
                            if (!matrizDecibilidad[i][j].pertenece(valorNoTerminal)){
                                matrizDecibilidad[i][j].agregar(valorNoTerminal);
                            }
                        }
                    }
                }
            }
        }
    }
    Conjunto<string> solucion = matrizDecibilidad[5][1];
    mostrarConjunto(solucion);
}

int main()
{
    //Declaracion de variables:
    int cantElemCadena = 5;
    string cadena[cantElemCadena+1]; ////No usare la posicion 0.
    int cantNoTerminales = 4;
    string noTerminales[cantNoTerminales+1]; //No usare la posicion 0.
    Conjunto<string> reglasANoTerminales[cantNoTerminales+1];
    Conjunto<string> reglasATerminales[cantNoTerminales+1];
    Conjunto<string> matrizDecibilidad[6][6]; // cantElemCadena+1 pero NO usare las posiciones en 0.
    //Las filas (i) me dicen el tamaño del problema, y las columnas (j) desde que caracter de la cadena empiezo.

    Conjunto<string> conjuntoVacio;
    for (int p = 0; p <= cantElemCadena; p++){
        matrizDecibilidad[0][p] = conjuntoVacio;
        matrizDecibilidad[p][0] = conjuntoVacio;
    }

    //Carga de variables:
    cadena[0] = "V"; //Vacio.
    cadena[1] = "b";
    cadena[2] = "a";
    cadena[3] = "a";
    cadena[4] = "b";
    cadena[5] = "a";

    noTerminales[0] = "V";
    noTerminales[1] = "S";
    noTerminales[2] = "A";
    noTerminales[3] = "B";
    noTerminales[4] = "C";

    Conjunto<string> noT1;
    noT1.agregar("AB");
    noT1.agregar("BC");
    Conjunto<string> noT2;
    noT2.agregar("BA");
    Conjunto<string> noT3;
    noT3.agregar("CC");
    Conjunto<string> noT4;
    noT4.agregar("AB");

    reglasANoTerminales[0] = conjuntoVacio;
    reglasANoTerminales[1] = noT1;
    reglasANoTerminales[2] = noT2;
    reglasANoTerminales[3] = noT3;
    reglasANoTerminales[4] = noT4;

    Conjunto<string> t1; //Vacio.
    Conjunto<string> t2;
    t2.agregar("a");
    Conjunto<string> t3;
    t3.agregar("b");
    Conjunto<string> t4;
    t4.agregar("a");

    reglasATerminales[0] = conjuntoVacio;
    reglasATerminales[1] = t1;
    reglasATerminales[2] = t2;
    reglasATerminales[3] = t3;
    reglasATerminales[4] = t4;

    decibilidadLengLibresContexto(matrizDecibilidad, reglasANoTerminales, reglasATerminales, noTerminales, cadena, cantElemCadena, cantNoTerminales);
    return 0;
}
