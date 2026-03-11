#include <iostream>
#include <string>

using namespace std;

class Celular {
private:
    string marca;
    string modelo;
    int bateria;

public:
    // Constructor por defecto
    Celular() {
        marca = "Desconocida";
        modelo = "Generico";
        bateria = 100;
    }

    // Constructor con 2 parametros
    Celular(string marca, string modelo) {
        this->marca = marca;
        this->modelo = modelo;
        bateria = 100;
    }

    // Constructor con 3 parametros
    Celular(string marca, string modelo, int bateria) {
        this->marca = marca;
        this->modelo = modelo;
        setBateria(bateria);
    }

    // Getters
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getBateria() const { return bateria; }

    // Setters
    void setMarca(string marca) { this->marca = marca; }
    void setModelo(string modelo) { this->modelo = modelo; }

    void setBateria(int bateria) {
        if (bateria >= 0 && bateria <= 100) {
            this->bateria = bateria;
        } else {
            cout << "Bateria invalida. Debe estar entre 0 y 100.\n";
        }
    }

    void mostrarInfo() const {
        cout << "Marca: " << marca
             << " | Modelo: " << modelo
             << " | Bateria: " << bateria << "%\n";
    }
};

int main() {
    string marca, modelo;
    int bateria;

    cout << "=== CREAR CELULAR 1 ===\n";
    cout << "Ingrese marca: "; cin >> marca;
    cout << "Ingrese modelo: "; cin >> modelo;
    cout << "Ingrese bateria: "; cin >> bateria;

    Celular cel1(marca, modelo, bateria);

    cout << "\n=== CREAR CELULAR 2 ===\n";
    cout << "Ingrese marca: "; cin >> marca;
    cout << "Ingrese modelo: "; cin >> modelo;

    Celular cel2(marca, modelo);

    cout << "\n=== CELULAR 3 (Por defecto) ===\n";
    Celular cel3;

    cout << "\n--- INFORMACION ---\n";
    cel1.mostrarInfo();
    cel2.mostrarInfo();
    cel3.mostrarInfo();

    return 0;
}