#include <iostream>
using namespace std;

class Persona {
public:
    virtual void rol() {
        cout << "Soy una persona\n";
    }
};

class Estudiante : public Persona {
public:
    void rol() override {
        cout << "Soy estudiante\n";
    }
};

class Profesor : public Persona {
public:
    void rol() override {
        cout << "Soy profesor\n";
    }
};

int main() {

    Estudiante e;
    Profesor p;

    Persona* personas[2];

    personas[0] = &e;
    personas[1] = &p;

    cout << "--- Probando Polimorfismo ---\n";

    for (int i = 0; i < 2; i++) {
        personas[i]->rol();
    }

    return 0;
}

/* RPTA: El polimorfismo permite que diferentes objetos respondan de manera distinta al mismo método y
esto hace el código más flexible y permite tratar distintos objetos como si fueran del mismo tipo base.
*/