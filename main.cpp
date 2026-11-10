#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Objeto {
    char nombre;
    double valor;
    double peso;
    double relacion;
};

bool compararObjetos(const Objeto& a, const Objeto& b) {
    return a.relacion > b.relacion;
}

void mochilaFraccional(double capacidad, vector<Objeto>& objetos) {
    sort(objetos.begin(), objetos.end(), compararObjetos);

    double valorTotal = 0.0;
    double pesoActual = 0.0;

    for (const auto& obj : objetos) {
        if (pesoActual + obj.peso <= capacidad) {
            pesoActual += obj.peso;
            valorTotal += obj.valor;
            cout << "Objeto " << obj.nombre << " completo (Peso: " << obj.peso << ", Valor: " << obj.valor << ")\n";
        }
        else {
            double espacioRestante = capacidad - pesoActual;
            double fraccion = espacioRestante / obj.peso;
            pesoActual += espacioRestante;
            valorTotal += obj.valor * fraccion;
            cout << fixed << setprecision(2);
            cout << fraccion * obj.peso << "/" << obj.peso << " Parte del objeto " << obj.nombre
                << " (Valor obtenido: " << (obj.valor * fraccion) << ")\n";
            break;
        }
    }
    cout << "Valor total aproximado: " << valorTotal << "\n";
}

void coberturaAntenas(vector<int>& casas, int R) {
    if (casas.empty()) return;

    sort(casas.begin(), casas.end());

    vector<int> antenas;
    int i = 0;
    int n = casas.size();

    while (i < n) {
        int izquierda = casas[i];

        int j = i;
        while (j < n && casas[j] <= izquierda + R) {
            j++;
        }
        int posicionAntena = casas[j - 1] + R;
        antenas.push_back(posicionAntena);

        int siguienteCasaCubierta = posicionAntena + R;
        while (i < n && casas[i] <= siguienteCasaCubierta) {
            i++;
        }
    }

    cout << "Antenas colocadas aproximadamente en:\n";
    for (int antena : antenas) {
        cout << antena << "\n";
    }
    cout << "Cantidad total: " << antenas.size() << "\n";
}

int main() {
    double capacidadMochila = 50;
    vector<Objeto> objetosMochila = {
        {'A', 60, 10, 60.0 / 10.0},
        {'B', 100, 20, 100.0 / 20.0},
        {'C', 120, 30, 120.0 / 30.0}
    };
    mochilaFraccional(capacidadMochila, objetosMochila);

    vector<int> casas = { 1, 2, 7, 11, 20, 21, 30 };
    int R = 5;
    coberturaAntenas(casas, R);

    return 0;
}