//calcular rombo
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float D, d, area, lado, perimetro;

    cout << "Ingrese la diagonal mayor: ";
    cin >> D;

    cout << "Ingrese la diagonal menor: ";
    cin >> d;

    area = (D * d) / 2;
    lado = sqrt(pow(D/2, 2) + pow(d/2, 2));
    perimetro = 4 * lado;

    cout << "\nArea: " << area << endl;
    cout << "Lado: " << lado << endl;
    cout << "Perimetro: " << perimetro << endl;

    return 0;
}