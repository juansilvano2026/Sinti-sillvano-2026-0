#include <iostream>
using namespace std;

int main() {
    float a, b, c, R, area;

    cout << "Ingrese el lado a: ";
    cin >> a;

    cout << "Ingrese el lado b: ";
    cin >> b;

    cout << "Ingrese el lado c: ";
    cin >> c;

    cout << "Ingrese el radio R: ";
    cin >> R;

    area = (a * b * c) / (4 * R);

    cout << "\nArea del triangulo inscrito: " << area << endl;

    return 0;
}