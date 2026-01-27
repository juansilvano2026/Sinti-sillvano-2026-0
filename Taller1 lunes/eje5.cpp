#include <iostream>
using namespace std;

int main() {
    float a, b, c, h, area, perimetro;

    cout << "Ingrese el lado a: ";
    cin >> a;

    cout << "Ingrese el lado b (base): ";
    cin >> b;

    cout << "Ingrese el lado c: ";
    cin >> c;

    cout << "Ingrese la altura: ";
    cin >> h;

    area = (b * h) / 2;
    perimetro = a + b + c;

    cout << "\nArea: " << area << endl;
    cout << "Perimetro: " << perimetro << endl;

    return 0;
}