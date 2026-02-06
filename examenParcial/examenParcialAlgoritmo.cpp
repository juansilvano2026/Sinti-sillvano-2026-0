#include <iostream>
using namespace std;

// Función propia para verificar si un número es primo
bool esPrimo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    int num;
    int maximo, minimo;

    int contPrimos = 0;

    int sumaPosPares = 0;
    int contPosPares = 0;

    int mayorImparDig = 0;
    bool existeMayorImparDig = false;

    for (int i = 1; i <= N; i++) {
        cin >> num;

        // Máximo y mínimo
        if (i == 1) {
            maximo = minimo = num;
        } else {
            if (num > maximo) maximo = num;
            if (num < minimo) minimo = num;
        }

        // Contar primos
        if (esPrimo(num))
            contPrimos++;

        // Promedio positivos pares
        if (num > 0 && num % 2 == 0) {
            sumaPosPares += num;
            contPosPares++;
        }

        // Dígitos impares y pares
        int temp = num;
        if (temp < 0) temp = -temp;

        int digPar = 0, digImpar = 0;
        while (temp > 0) {
            int d = temp % 10;
            if (d % 2 == 0) digPar++;
            else digImpar++;
            temp /= 10;
        }

        if (digImpar > digPar) {
            if (!existeMayorImparDig || num > mayorImparDig) {
                mayorImparDig = num;
                existeMayorImparDig = true;
            }
        }
    }

    cout << "Maximo: " << maximo << endl;
    cout << "Minimo: " << minimo << endl;

    if (contPrimos == 0)
        cout << "Primos: NO EXISTE" << endl;
    else
        cout << "Primos: " << contPrimos << endl;

    if (contPosPares == 0)
        cout << "Promedio positivos pares: NO EXISTE" << endl;
    else
        cout << "Promedio positivos pares: "
             << (float)sumaPosPares / contPosPares << endl;

    if (!existeMayorImparDig)
        cout << "Mayor con mas digitos impares: NO EXISTE" << endl;
    else
        cout << "Mayor con mas digitos impares: " << mayorImparDig << endl;

    return 0;
}
