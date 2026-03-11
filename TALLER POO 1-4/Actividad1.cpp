#include <iostream>
using namespace std;

class Celular {
public:
    string marca;
    string modelo;
    int bateria;

    void mostrarInfo() {
        cout << "Marca: " << marca
             << " | Modelo: " << modelo
             << " | Bateria: " << bateria << "%\n";
    }
};

int main() {

    // Crear objetos
    Celular cel1;
    Celular cel2;

    // Asignar valores
    cel1.marca = "Samsung";
    cel1.modelo = "J4";
    cel1.bateria = 80;

    cel2.marca = "Apple";
    cel2.modelo = "iPhone 13";
    cel2.bateria = 90;

    // Mostrar información
    cel1.mostrarInfo();
    cel2.mostrarInfo();

    return 0;
}
/*Respuesta a la reflexion: Significa que el objeto fue creado a partir de una clase, 
usando esa clase como plantilla, en pocas palabras la clase viene siendo una plantilla
y el objeto algo creado a travez de esa plantilla */