#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    float b, h, area, perimetro, diagonal;

    cout << "Ingrese la base del rectangulo: ";
    cin >> b;

    cout << "Ingrese la altura del rectangulo: ";
    cin >> h;

    area = b * h;
    perimetro = 2 * (b + h);
    diagonal = sqrt((b * b) + (h * h));

    cout << "\nResultados:\n";
    cout << "Area: " << area << endl;
    cout << "Perimetro: " << perimetro << endl;
    cout << "Diagonal: " << diagonal << endl;

    return 0;
}