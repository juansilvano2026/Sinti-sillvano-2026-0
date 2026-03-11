#include <iostream>
using namespace std;

class Celular {
private:
    string marca;
    string modelo;
    int bateria;

public:
    // Getters
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getBateria() const { return bateria; }

    // Setters usando mismo nombre + this->
    void setMarca(string marca) {
        this->marca = marca;
    }

    void setModelo(string modelo) {
        this->modelo = modelo;
    }

    void setBateria(int bateria) {
        if (bateria >= 0 && bateria <= 100) {
            this->bateria = bateria;
        } else {
            cout << "Bateria invalida\n";
        }
    }

    void mostrarInfo() const {
        cout << "Marca: " << marca
             << " | Modelo: " << modelo
             << " | Bateria: " << bateria << "%\n";
    }
};

int main() {

    Celular cel1;

    cel1.setMarca("Samsung");
    cel1.setModelo("J4");
    cel1.setBateria(85);

    cel1.mostrarInfo();

    return 0;
}

/* RPTA; Si no usamos this cuando el parámetro y el atributo tienen el mismo nombre, 
el compilador no puede diferenciarlos correctamente.
 this permite referirse específicamente al atributo de la clase
*/