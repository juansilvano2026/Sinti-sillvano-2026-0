#include <iostream>
#include <vector>
using namespace std;

// =======================
// Clase Abstracta
// =======================
class Vehiculo {
protected:
    string id;
    double velocidad;

public:
    Vehiculo(string id, double velocidad) {
        this->id = id;
        this->velocidad = velocidad;
    }

    virtual void moverse() = 0; // Método virtual puro

    virtual void mostrarInfo() {
        cout << "ID: " << id << endl;
        cout << "Velocidad: " << velocidad << " km/h" << endl;
    }

    virtual ~Vehiculo() {
        cout << "Destruyendo Vehiculo " << id << endl;
    }

    friend class Reporte; // Clase amiga
};

// =======================
// Clase Auto
// =======================
class Auto : public Vehiculo {
private:
    int numeroPuertas;

public:
    Auto(string id, double velocidad, int puertas)
        : Vehiculo(id, velocidad) {
        numeroPuertas = puertas;
    }

    void moverse() override {
        cout << "El auto se mueve por carretera." << endl;
    }

    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << "Numero de puertas: " << numeroPuertas << endl;
    }
};

// =======================
// Clase Drone
// =======================
class Drone : public Vehiculo {
private:
    double alturaMaxima;

public:
    Drone(string id, double velocidad, double altura)
        : Vehiculo(id, velocidad) {
        alturaMaxima = altura;
    }

    void moverse() override {
        cout << "El drone vuela en el aire." << endl;
    }

    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << "Altura maxima: " << alturaMaxima << " metros" << endl;
    }
};

// =======================
// Clase Camion
// =======================
class Camion : public Vehiculo {
private:
    double capacidadCarga;

public:
    Camion(string id, double velocidad, double carga)
        : Vehiculo(id, velocidad) {
        capacidadCarga = carga;
    }

    void moverse() override {
        cout << "El camion transporta mercancia por carretera." << endl;
    }

    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << "Capacidad de carga: " << capacidadCarga << " toneladas" << endl;
    }
};

// =======================
// Polimorfismo Estático (Template)
// =======================
template <typename T>
T calcularEficiencia(T consumo, T distancia) {
    return distancia / consumo;
}

// =======================
// Clase Amiga
// =======================
class Reporte {
public:
    static void generarReporte(Vehiculo* v) {
        cout << "\n--- REPORTE DEL VEHICULO ---" << endl;
        cout << "ID: " << v->id << endl;
        cout << "Velocidad: " << v->velocidad << endl;
    }
};

// =======================
// MAIN
// =======================
int main() {

    vector<Vehiculo*> flota;

    flota.push_back(new Auto("A1", 120, 4));
    flota.push_back(new Drone("D1", 80, 500));
    flota.push_back(new Camion("C1", 90, 10));

    cout << "===== POLIMORFISMO DINAMICO =====" << endl;

    for (Vehiculo* v : flota) {
        v->moverse();
        v->mostrarInfo();
        cout << "----------------------" << endl;
    }

    cout << "\n===== POLIMORFISMO ESTATICO =====" << endl;
    cout << "Eficiencia: " << calcularEficiencia(10.0, 200.0) << endl;

    cout << "\n===== REPORTE =====" << endl;
    Reporte::generarReporte(flota[0]);

    // Liberar memoria
    for (Vehiculo* v : flota) {
        delete v;
    }

    return 0;
}

/* Reflexion 1: Si eliminamos virtual, cuando eliminamos un objeto derivado usando un puntero base (Vehiculo*),
no se llamará correctamente el destructor de la clase hija, lo que puede causar fugas de memoria.


Reflexion 2: Si quitamos override, el programa puede seguir compilando,
pero perdemos una protección muy importante.


Reflexion 3: La diferencia es que los objetos directos no permiten aprovechar correctamente el polimorfismo dinámico
 y pueden causar pérdida de información (object slicing). En cambio,
  los punteros permiten manejar diferentes tipos derivados mediante una clase base y ejecutar el método correcto en tiempo de ejecución.
*/