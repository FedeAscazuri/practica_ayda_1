#include <iostream>
using namespace std;

int Factible(int d[], int J[], int n) {
    // Retorna la cantidad de elementos (k) de la solución factible
    // y la solución en los k primeros elementos J

    d[0] = 0;
    J[0] = 0;
    J[1] = 1;
    int k = 1;
    
    for (int i = 2; i <= n; i++) {
        int r = k;
        while ((d[J[r]] > d[i]) && (d[J[r]] != r))
            r--;

        if ((d[J[r]] <= d[i]) && (d[i] > r)) {
            for (int q = k; q >= (r + 1); q--)
                J[q + 1] = J[q];

            J[r + 1] = i;
            k++;
        }
    }
    return k;
}

int main() {
    // Test simple de Factible
    // Ganancias ordenadas descendentemente
    int ganancia[8] = {0, 13, 12, 10, 8, 6, 4, 1};
    
    // Plazos correspondientes
    int deadline[8] = {0, 2, 1, 3, 2, 1, 1, 4};
    int tareas[8];
    int n = 7;

    int cant_elem = Factible(deadline, tareas, n);
    int ganancia_total = 0;

    for (int m = 1; m < cant_elem; m++) {
        ganancia_total = ganancia_total + ganancia[tareas[m]];
        cout << "Tarea " << m << " = " << tareas[m] << endl;
    }

    cout << "La ganancia total es: " << ganancia_total << endl;
    return 0;
}
