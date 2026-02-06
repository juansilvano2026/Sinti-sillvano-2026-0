#include <iostream>
using namespace std;

int main() {
    int numero = 20;
    int *p = &numero;

    cout << "Direccion guardada en p: " << p << endl;
    cout << "Valor al que apunta p: " << *p << endl;

    return 0;
}