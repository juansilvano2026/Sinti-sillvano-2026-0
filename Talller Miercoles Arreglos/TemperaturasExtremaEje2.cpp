#include <iostream>
using namespace std;

int main() {
    int temp[7], mayores30 = 0;
    
    cout << "Ingrese las temperaturas:\n";
    for(int i = 0; i < 7; i++) cin >> temp[i];

    int max = temp[0], min = temp[0], diaMax = 0, diaMin = 0;

    for(int i = 0; i < 7; i++) {
        if(temp[i] > max) max = temp[i], diaMax = i;
        if(temp[i] < min) min = temp[i], diaMin = i;
        mayores30 += (temp[i] > 30);
    }

    cout << "Maxima: " << max << " (dia " << diaMax + 1 << ")\n";
    cout << "Minima: " << min << " (dia " << diaMin + 1 << ")\n";
    cout << "Dias mayores a 30: " << mayores30;

    return 0;
}
