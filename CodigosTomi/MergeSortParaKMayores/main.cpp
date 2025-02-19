#include <iostream>

using namespace std;

void mergeSort( vector arr, int i, int j, vector rdo, int k)
{
    if (i < j) {
        int m = i + (j - i) / 2;
        mergeSort(arr, i, m, rdo, k);
        mergeSort(arr, m + 1, j, rdo, k );
        return rdo;
    }
}

void k_mejores (int k, rdo, int arr[])
{
    mergeSort(arr,i,j,k);
    for(i= inicio hasta fin){
        agregar_rdo(rdo, arr, i)
    }
        return;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
