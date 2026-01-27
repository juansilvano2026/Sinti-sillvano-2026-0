#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a, b, c, p, area;

    cout << "Ingrese el lado a: ";
    cin >> a;

    cout << "Ingrese el lado b: ";
    cin >> b;

    cout << "Ingrese el lado c: ";
    cin >> c;

    p = (a + b + c) / 2;
    area = sqrt(p * (p - a) * (p - b) * (p - c));

    cout << "\nSemiperimetro: " << p << endl;
    cout << "Area: " << area << endl;

    return 0;
}