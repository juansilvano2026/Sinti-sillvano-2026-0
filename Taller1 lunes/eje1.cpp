#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    float l, area, perimetro, diagonal;

    cout << "Ingrese el lado del cuadrado: ";
    cin >> l;

    area = l * l;
    perimetro = 4 * l;
    diagonal = l * sqrt(2);

    cout << "\nResultados:\n";
    cout << "Lado: " << l << endl;
    cout << "Area: " << area << endl;
    cout << "Perimetro: " << perimetro << endl;
    cout << "Diagonal: " << diagonal << endl;

    return 0;
}