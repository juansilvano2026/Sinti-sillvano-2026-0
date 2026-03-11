#include <iostream>
using namespace std;

class Celular {
private:
    string marca;
    string modelo;
    int bateria;

public:
    // 1️⃣ Constructor por defecto
    Celular() {
        marca = "Desconocida";
        modelo = "Generico";
        bateria = 100;
    }

    // 2️⃣ Constructor con 2 parametros
    Celular(string marca, string modelo) {
        this->marca = marca;
        this->modelo = modelo;
        bateria = 100;
    }

    // 3️⃣ Constructor con 3 parametros
    Celular(string marca, string modelo, int bateria) {
        this->marca = marca;
        this->modelo = modelo;

        if (bateria >= 0 && bateria <= 100) {
            this->bateria = bateria;
        } else {
            cout << "Bateria invalida. Se asigna 100 por defecto.\n";
            this->bateria = 100;
        }
    }

    void mostrarInfo() const {
        cout << "Marca: " << marca
             << " | Modelo: " << modelo
             << " | Bateria: " << bateria << "%\n";
    }
};

int main() {

    // 4️⃣ Crear objetos usando cada constructor
    Celular cel1;  // constructor por defecto
    Celular cel2("Samsung", "J4");  // 2 parametros
    Celular cel3("Apple", "iPhone 13", 80);  // 3 parametros

    cel1.mostrarInfo();
    cel2.mostrarInfo();
    cel3.mostrarInfo();

    return 0;
}
/*rpta: Los constructores sobrecargados son utiles porque permiten crear objetos de diferentes maneras,
 dependiendo de la información que se tenga disponible al momento de crear el objeto.
*/