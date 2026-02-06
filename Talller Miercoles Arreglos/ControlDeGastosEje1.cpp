#include <iostream>
using namespace std;

int main() {
    float gastos[7];
    float total = 0, promedio;
    int mayorPromedio = 0;

    cout << "Ingrese los gastos de la semana:\n";
    for(int i = 0; i < 7; i++) {
        cin >> gastos[i];
        total += gastos[i];
    }

    promedio = total / 7;

    for(int i = 0; i < 7; i++) {
        if(gastos[i] > promedio) {
            mayorPromedio++;
        }
    }

    cout << "Total: " << total << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Dias con gasto mayor al promedio: " << mayorPromedio << endl;

    return 0;
}
