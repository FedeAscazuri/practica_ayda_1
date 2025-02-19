#include <iostream>

using namespace std;

//Encontrar el valor máximo y mínimo de un arreglo de n enteros aplicando la técnica Divide y
//Conquista dividiendo el problema en tres partes balanceadas.

void maxMinArrTri( int arr[], int i, int j, int & min,int & max )
{
    if (j-i+1 <= 3){ //Tamaño 3 o menos
        for(int k = i ; k <= j ; k++){
            if (arr[k] < min){
                min = arr[k];
            }
            if (arr[k] > max){
                max = arr[k];
            }
        }
    }
    else{
        int tercio = (i + j+1) / 3;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        int min3 = INT_MAX;
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        maxMinArrTri(arr, i, i + tercio - 1, min1, max1);
        maxMinArrTri(arr,i+tercio,i + 2*tercio-1,min2,max2);
        maxMinArrTri(arr,i + 2 * tercio,j,min3,max3);
        min = menor(min1,min2,min3);
        max = mayor(max1,max2,max3);
    }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
