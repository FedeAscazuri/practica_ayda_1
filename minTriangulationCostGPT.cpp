#include <iostream>
#include <vector>
#include <cmath>  
#include <limits>

using namespace std;

// Función para calcular la distancia euclidiana entre dos puntos
double dist(pair<double, double> a, pair<double, double> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + 
                (a.second - b.second) * (a.second - b.second));
}

// Función que encuentra el costo mínimo para triangular un polígono convexo
double minTriangulationCost(const vector<pair<double, double>>& puntos) {
    int n = puntos.size();
    if (n < 3) return 0;  // No se puede triangular un polígono con menos de 3 vértices

    // Matriz DP donde dp[i][j] almacena el costo mínimo de triangulación del subpolígono entre i y j
    vector<vector<double>> dp(n, vector<double>(n, 0));

    // Llenamos la tabla de programación dinámica
    for (int size = 2; size < n; size++) {  // `size` representa el tamaño del subpolígono
        for (int i = 0; i + size < n; i++) { // `i` es el índice inicial del subpolígono
            int j = i + size;  // `j` es el índice final del subpolígono

            dp[i][j] = 10000; // Inicializamos con un valor muy alto

            // Probamos todas las posibles diagonales k entre `i` y `j` para minimizar el costo
            for (int k = i + 1; k < j; k++) {
                // Calculamos el costo de agregar la diagonal (i, j) usando el punto `k`
                double costo = dist(puntos[i], puntos[j]) * dist(puntos[i], puntos[k]) * dist(puntos[k], puntos[j]);
                costo += dp[i][k] + dp[k][j]; // Sumar costos previos de triangulaciones menores

                // Guardamos el menor costo posible
                dp[i][j] = min(dp[i][j], costo);
            }
        }
    }

    return dp[0][n-1]; // Retornamos el costo mínimo de triangular todo el polígono
}

int main() {
    // Definimos un polígono con coordenadas (x, y)
    vector<pair<double, double>> puntos = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}};

    // Calculamos el costo mínimo de triangulación
    double resultado = minTriangulationCost(puntos);
    
    // Mostramos el resultado
    cout << "Costo mínimo de triangulación: " << resultado << endl;

    return 0;
}
