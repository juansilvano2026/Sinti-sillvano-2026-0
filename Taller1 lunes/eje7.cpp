#include <iostream>
using namespace std;

int main() {
    float a, b, c, r, p, area;

    cout << "Ingrese el lado a: ";
    cin >> a;

    cout << "Ingrese el lado b: ";
    cin >> b;

    cout << "Ingrese el lado c: ";
    cin >> c;

    cout << "Ingrese el radio r: ";
    cin >> r;

    p = (a + b + c) / 2;
    area = r * p;

    cout << "\nSemiperimetro: " << p << endl;
    cout << "Area: " << area << endl;

    return 0;
}