#include <iostream>
using namespace std;

int main() {
    float B, b, h, area;

    cout << "Ingrese la base mayor: ";
    cin >> B;

    cout << "Ingrese la base menor: ";
    cin >> b;

    cout << "Ingrese la altura: ";
    cin >> h;

    area = (B + b) * h / 2;

    cout << "\nArea del trapecio: " << area << endl;

    return 0;
}