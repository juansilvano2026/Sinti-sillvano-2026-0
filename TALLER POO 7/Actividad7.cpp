#include <iostream>
using namespace std;

// ================= CLASE BASE =================
class Vehiculo {
private:
    string marca;
    int velocidadMax;

public:
    // Constructor
    Vehiculo(string marca, int velocidadMax) {
        this->marca = marca;
        setVelocidadMax(velocidadMax);
    }

    // Getters
    string getMarca() const {
        return marca;
    }

    int getVelocidadMax() const {
        return velocidadMax;
    }

    // Setters con validación
    void setMarca(string marca) {
        this->marca = marca;
    }

    void setVelocidadMax(int velocidadMax) {
        if (velocidadMax > 0)
            this->velocidadMax = velocidadMax;
        else {
            cout << "Velocidad invalida. Se asignara 0.\n";
            this->velocidadMax = 0;
        }
    }

    // Método mostrar
    virtual void mostrarInfo() const {
        cout << "Marca: " << marca
             << " | Velocidad Max: " << velocidadMax;
    }
};

// ================= CLASE DERIVADA CARRO =================
class Carro : public Vehiculo {
private:
    int puertas;

public:
    // Constructor
    Carro(string marca, int velocidadMax, int puertas)
        : Vehiculo(marca, velocidadMax) {
        setPuertas(puertas);
    }

    // Getter
    int getPuertas() const {
        return puertas;
    }

    // Setter con validación
    void setPuertas(int puertas) {
        if (puertas > 0)
            this->puertas = puertas;
        else {
            cout << "Numero de puertas invalido. Se asignara 4.\n";
            this->puertas = 4;
        }
    }

    // Override
    void mostrarInfo() const override {
        Vehiculo::mostrarInfo();
        cout << " | Puertas: " << puertas << endl;
    }
};

// ================= CLASE DERIVADA MOTO =================
class Moto : public Vehiculo {
private:
    int cilindraje;

public:
    // Constructor
    Moto(string marca, int velocidadMax, int cilindraje)
        : Vehiculo(marca, velocidadMax) {
        setCilindraje(cilindraje);
    }

    // Getter
    int getCilindraje() const {
        return cilindraje;
    }

    // Setter con validación
    void setCilindraje(int cilindraje) {
        if (cilindraje > 0)
            this->cilindraje = cilindraje;
        else {
            cout << "Cilindraje invalido. Se asignara 100.\n";
            this->cilindraje = 100;
        }
    }

    // Override
    void mostrarInfo() const override {
        Vehiculo::mostrarInfo();
        cout << " | Cilindraje: " << cilindraje << "cc" << endl;
    }
};

// ================= MAIN =================
int main() {

    // Crear objetos
    Carro carro1("Toyota", 180, 4);
    Moto moto1("Honda", 200, 600);

    // Mostrar información
    cout << "--- INFORMACION DEL CARRO ---\n";
    carro1.mostrarInfo();

    cout << "\n--- INFORMACION DE LA MOTO ---\n";
    moto1.mostrarInfo();

    return 0;
}

/* RPTA; Sí cumple la estructura de herencia con clase base Vehiculo y derivadas Carro y Moto, con encapsulamiento y constructores.
 Solo faltaría agregar getters y setters en las clases derivadas para cumplir al 100% el enunciado."
*/