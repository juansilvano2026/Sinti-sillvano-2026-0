#include <iostream>
using namespace std;

int main() {
    const int EST = 3, DIAS = 5;
    int numero;
    int totalAula = 0;

    for(int i = 0; i < EST; i++) {
        cin >> numero;  // Ejemplo: 11111

        int total = 0;

        for(int j = 0; j < DIAS; j++) {
            total += numero % 10;  // obtiene último dígito
            numero /= 10;          // elimina último dígito
        }

        totalAula += total;

        cout << "Estudiante " << i+1 << ": " << total
             << (total == DIAS ? " (Perfecta)" : "") << endl;
    }

    cout << "Total aula: " << totalAula;

    return 0;
}
