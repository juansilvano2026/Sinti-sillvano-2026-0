#include <iostream>
using namespace std;

int main() {
    int M;
    cin >> M;

    for (int i = 1; i <= M; i++) {
        int x;
        cin >> x;

        int temp = x;
        if (temp < 0) temp = -temp;

        int suma = 0;
        int digitos = 0;

        while (temp > 0) {
            suma += temp % 10;
            temp /= 10;
            digitos++;
        }

        if (suma % 2 == 0 && x % 4 == 0) {
            cout << "A" << endl;
        }
        else if (suma % 2 != 0 && x % 6 == 0) {
            cout << "B" << endl;
        }
        else if (digitos == 3) {
            cout << "C" << endl;
        }
        else {
            cout << "D" << endl;
        }
    }

    return 0;
}
