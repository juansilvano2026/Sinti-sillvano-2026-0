#include <iostream>
using namespace std;

int main() {
    int opcion;
    cout << "Menu:\n";
    cout << "1. Sumar\n";
    cout << "2. Restar\n";
    cout << "3. Multiplicar\n";
    cout << "4. Dividir\n";
    cout << "Elija una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Suma";
            break;
        case 2:
            cout << "Resta";
            break;
        case 3:
            cout << "Multiplicacion";
            break;
        case 4:
            cout << "Division";
            break;
        default:
            cout << "Opcion no valida";
    }

    return 0;
}