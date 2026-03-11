#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    // Constructor
    Persona(string nombre, int edad) {
        this->nombre = nombre;
        setEdad(edad);
    }

    // Getters
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }

    // Setter con validacion
    void setEdad(int edad) {
        if (edad >= 0) {
            this->edad = edad;
        } else {
            cout << "Edad invalida. Se asigna 0.\n";
            this->edad = 0;
        }
    }

    void mostrar() const {
        cout << "Nombre: " << nombre
             << " | Edad: " << edad << endl;
    }
};

// Clase derivada Estudiante
class Estudiante : public Persona {
private:
    string carrera;

public:
    Estudiante(string nombre, int edad, string carrera)
        : Persona(nombre, edad) {
        this->carrera = carrera;
    }

    void estudiar() {
        cout << "Estoy estudiando " << carrera << endl;
    }
};

// Clase derivada Profesor
class Profesor : public Persona {
private:
    string materia;

public:
    Profesor(string nombre, int edad, string materia)
        : Persona(nombre, edad) {
        this->materia = materia;
    }

    void ensenar() {
        cout << "Estoy ensenando " << materia << endl;
    }
};

int main() {

    string nombre, carrera, materia;
    int edad;

    cout << "=== CREAR ESTUDIANTE ===\n";
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Edad: ";
    cin >> edad;
    cout << "Carrera: ";
    cin >> carrera;

    Estudiante e(nombre, edad, carrera);

    cout << "\n=== CREAR PROFESOR ===\n";
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Edad: ";
    cin >> edad;
    cout << "Materia: ";
    cin >> materia;

    Profesor p(nombre, edad, materia);

    cout << "\n--- DATOS ---\n";
    e.mostrar();
    e.estudiar();

    cout << endl;

    p.mostrar();
    p.ensenar();

    return 0;
}
/* RPTA: Estudiante y Profesor comparten los atributos nombre y edad,
 asi como el método mostrar, gracias a que heredan de la clase Persona
*/