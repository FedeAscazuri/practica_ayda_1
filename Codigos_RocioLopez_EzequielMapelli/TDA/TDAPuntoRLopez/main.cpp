#include <iostream>
#include "Arbin.h"
#include "Pila.h"
#include "Lista.h"

using namespace std;


template <typename T>
void listarElementos (Arbin<T> *arb, Lista<T> & lis)
{
   if (arb->es_vacio() == false)
   {
       cout << "entra" <<endl;
       if (arb->es_hoja() == false)
            lis.agregar_al_final(arb->raiz());
       listarElementos(arb->arbol_izquierdo(), lis);
       listarElementos(arb->arbol_derecho(), lis);
   }
}

template <typename T>
void imprimirLista (Lista <T> lis)
{
    unsigned int pos; pos = 1;
    while (pos <= lis.longitud())
    {
        cout << lis.recuperar(pos) << endl;
        pos++;
    }
}



int main()
{
    // --------------   parte 1  ------------------------------------
    Arbin<int>* a1= new Arbin<int>;   //             35
	Arbin<int>* a2= new Arbin<int>;               //     \\

	Arbin<int>* a12= new Arbin<int>;  //       15          20
	a12->construir(a1,a2,10);                //   \\     //
                                      //   10       5    15
	Arbin<int>* a3= new Arbin<int>;   //               //   \\

	Arbin<int>* a4= new Arbin<int>;   //               10     5
	Arbin<int>* a34= new Arbin<int>;
	a34->construir(a3,a4,5);

	Arbin<int>* a1234= new Arbin<int>;
	a1234->construir(a12,a34,15);

    Arbin<int>* a6= new Arbin<int>;
	Arbin<int>* a12346= new Arbin<int>;
	a12346->construir(a1234,a6,20);

	Arbin<int>* a123456= new Arbin<int>;
	a123456->construir(a1234,a12346,35);

   	cout<< "la altura del árbol es: "<< a123456->Altura_Arbol()<< endl;

	Lista<int> lis;  // verificar nombre del tipo Lista
	listarElementos(a123456,lis);

	cout<< "\n Los elementos de la lista son: "<< endl;
	imprimirLista(lis);

//// --------------   parte 2  ------------------------------------

    Lista<int> l;
    l.agregar_al_final(1);
    l.agregar_al_final(2);
    l.agregar_al_final(3);
    l.agregar_al_final(4);
    l.agregar_al_final(5);
    l.agregar_al_final(6);
    l.agregar_al_final(7);
    l.agregar_al_final(8);
    l.agregar_al_final(9);
    l.agregar_al_final(10);

    Lista<int> auxiliar;

    auxiliar.agregar_al_final(-1);
    auxiliar.agregar_al_final(5);
    auxiliar.agregar_al_final(10);
    auxiliar.agregar_al_final(15);
    auxiliar.agregar_al_final(9);
    auxiliar.agregar_al_final(-11);

    //implementar en la clase lista el método modificar según consigna
    l.modificar(auxiliar);

	cout << "\n Los elementos de la lista modificada son: "<< endl;

	imprimirLista(l);
	int pos;
	pos = 1;
	while (l.longitud() != 0){
        l.eliminar(pos);
	}
	cout << "lista eliminada:" << endl;
    imprimirLista(l);

}

