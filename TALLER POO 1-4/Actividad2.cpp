#include <iostream>
using namespace std;

class Celular {
private:
    string marca;
    string modelo;
    int bateria;

public:
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getBateria() const { return bateria; }

    void setMarca(string m) { marca = m; }
    void setModelo(string m) { modelo = m; }

    void setBateria(int b) {
        if (b >= 0 && b <= 100) {
            bateria = b;
        } else {
            cout << "Valor de bateria invalido. Debe estar entre 0 y 100.\n";
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
    int bateriaIngresada;

    cel1.setMarca("Samsung");
    cel1.setModelo("J4");

    cout << "Ingrese nivel de bateria (0-100): ";
    cin >> bateriaIngresada;

    cel1.setBateria(bateriaIngresada);

    cel1.mostrarInfo();

    return 0;
}
/*Rpta reflexion; El encapsulamiento evita que los atributos de una clase se modifiquen directamente desde fuera.
Esto protege los datos y permite controlar los valores mediante validaciones en los setters, 
y esto evita errores como asignar valores invalidos a la batería*/