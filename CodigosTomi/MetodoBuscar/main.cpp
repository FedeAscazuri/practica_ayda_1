#include <iostream>

using namespace std;


void buscar (const int a[], int primero, int ultimo, int clave, bool & pertenece,int & posicion)
{
        int mitad;
        if (primero > ultimo){
                pertenece = false;
        }
        else{
            mitad = (primero + ultimo) /2;
            if (clave == a[mitad]){
                 pertenece= true;
                 posicion = mitad;
            }
            else{
                 if (clave < a[mitad]){
                      buscar ( a, primero, mitad -1, clave, pertenece, posicion);
                }
                else{
                    if (clave > a[mitad]){
                            buscar ( a, mitad+1, ultimo, clave, pertenece, posicion);
                    }
                }
            }
        }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
