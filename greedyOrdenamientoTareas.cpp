#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tarea {
    int id;
    int beneficio;
    int plazo;
};

// Comparador para ordenar las tareas por beneficio en orden descendente
bool comparar(Tarea a, Tarea b) {
    return a.beneficio > b.beneficio;
}

vector<int> planificarTareas(vector<Tarea> tareas, int n) {
    sort(tareas.begin(), tareas.end(), comparar); // Ordenar por beneficio

    vector<int> resultado(n, -1); // -1 indica espacio vacío
    vector<bool> ocupado(n, false); // Marca si un tiempo está ocupado

    for (int i = 0; i < tareas.size(); i++) {
        int j = min(n, tareas[i].plazo) - 1;
        while (j >= 0 && ocupado[j]) {
            j--; // Buscar el primer espacio libre
        }
        if (j >= 0) {
            resultado[j] = tareas[i].id;
            ocupado[j] = true;
        }
    }

    vector<int> seleccionadas;
    for (int i = 0; i < n; i++) {
        if (resultado[i] != -1) {
            seleccionadas.push_back(resultado[i]);
        }
    }
    return seleccionadas;
}

int main() {
    vector<Tarea> tareas = {
        {1, 50, 2},
        {2, 10, 1},
        {3, 15, 2},
        {4, 30, 1},
        {5, 1,3}
    };

    int n = tareas.size();
    vector<int> seleccionadas = planificarTareas(tareas, n);

    cout << "Tareas seleccionadas para maximizar beneficio: ";
    for (int i = 0; i < seleccionadas.size(); i++) {
        cout << seleccionadas[i] << " ";
    }
    cout << endl;

    return 0;
}
