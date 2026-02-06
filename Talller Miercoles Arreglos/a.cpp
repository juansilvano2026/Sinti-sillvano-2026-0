#include <iostream>
using namespace std;

int main() {

    int numero = 15;      // Variable normal
    int *puntero = &numero;  // El puntero guarda la dirección de numero

    cout << "Valor de numero: " << numero << endl;
    cout << "Direccion de numero: " << &numero << endl;
    cout << "Valor guardado en puntero: " << puntero << endl;
    cout << "Valor al que apunta el puntero: " << *puntero << endl;

    // Modificación indirecta
    *puntero = 30;

    cout << "Nuevo valor de numero: " << numero << endl;

    return 0;
}
