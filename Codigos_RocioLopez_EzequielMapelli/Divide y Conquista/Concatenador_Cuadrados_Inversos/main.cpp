#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string cuadrados(int numero){
    string resultado = "";
    if (numero > 0){
        int resto = numero%10; //numero mod 10.
        cout << "Resto = " << resto <<endl;
        int result = pow(resto, 2);
        cout << "-Result = " << result << endl;
        resultado = to_string(result) += cuadrados(numero/10);
    }
    cout << "RESULTADO = " << resultado << endl;
    return resultado;
}

int main()
{
    cout << "Para el 4321 ---> " << cuadrados(4321) << endl;
    return 0;
}
