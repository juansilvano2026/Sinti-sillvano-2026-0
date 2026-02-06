#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Parte A: Modelado (struct)
struct Producto {
    int codigo;
    string nombre;
    float precio;
    int stock;
};

// Prototipos de funciones para mantener el orden
void registrarProductos(Producto inventario[], int &n);
void mostrarProductos(Producto inventario[], int n);
void buscarPorCodigo(Producto inventario[], int n);
void buscarPorNombre(Producto inventario[], int n);
void mayorStock(Producto inventario[], int n);
void masCaro(Producto inventario[], int n);
void valorTotalInventario(Producto inventario[], int n);

int main() {
    // Declaración del arreglo (máximo 50 productos por ejemplo)
    Producto inventario[50];
    int n = 0; // Cantidad actual de productos registrados
    int opcion;

    do {
        cout << "\n--- MENU DE TIENDA ---" << endl;
        cout << "1. Registrar productos" << endl;
        cout << "2. Mostrar productos" << endl;
        cout << "3. Buscar producto por codigo" << endl;
        cout << "4. Buscar producto por nombre" << endl;
        cout << "5. Mostrar producto con mayor stock" << endl;
        cout << "6. Mostrar producto mas caro" << endl;
        cout << "7. Calcular valor total del inventario" << endl;
        cout << "8. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: registrarProductos(inventario, n); break;
            case 2: mostrarProductos(inventario, n); break;
            case 3: buscarPorCodigo(inventario, n); break;
            case 4: buscarPorNombre(inventario, n); break;
            case 5: mayorStock(inventario, n); break;
            case 6: masCaro(inventario, n); break;
            case 7: valorTotalInventario(inventario, n); break;
            case 8: cout << "Saliendo del sistema..." << endl; break;
            default: cout << "Opcion no valida." << endl;
        }
    } while(opcion != 8);

    return 0;
}

// 2. Parte B: Registro de datos con validaciones
void registrarProductos(Producto inventario[], int &n) {
    int cantidad;
    cout << "Cuantos productos desea registrar? ";
    cin >> cantidad;

    for(int i = 0; i < cantidad; i++) {
        cout << "\nProducto " << n + 1 << ":" << endl;
        cout << "Codigo: "; cin >> inventario[n].codigo;
        cin.ignore(); // Limpiar buffer
        cout << "Nombre: "; getline(cin, inventario[n].nombre);
        
        // Validaciones
        do {
            cout << "Precio (mayor a 0): "; cin >> inventario[n].precio;
        } while(inventario[n].precio <= 0);

        do {
            cout << "Stock (no negativo): "; cin >> inventario[n].stock;
        } while(inventario[n].stock < 0);

        n++; // Aumentar contador global
    }
}

// 3. Parte D: Lógica de Negocio
void mostrarProductos(Producto inventario[], int n) {
    if(n == 0) { cout << "Inventario vacio." << endl; return; }
    cout << "\nID\tNOMBRE\t\tPRECIO\tSTOCK" << endl;
    for(int i = 0; i < n; i++) {
        cout << inventario[i].codigo << "\t" << inventario[i].nombre << "\t\t" 
             << inventario[i].precio << "\t" << inventario[i].stock << endl;
    }
}

void buscarPorCodigo(Producto inventario[], int n) {
    int cod;
    bool encontrado = false;
    cout << "Ingrese codigo a buscar: "; cin >> cod;
    for(int i = 0; i < n; i++) {
        if(inventario[i].codigo == cod) {
            cout << "Encontrado: " << inventario[i].nombre << " | Stock: " << inventario[i].stock << endl;
            encontrado = true;
        }
    }
    if(!encontrado) cout << "No encontrado." << endl;
}

void buscarPorNombre(Producto inventario[], int n) {
    string nom;
    bool encontrado = false;
    cin.ignore();
    cout << "Ingrese nombre a buscar: "; getline(cin, nom);
    for(int i = 0; i < n; i++) {
        if(inventario[i].nombre == nom) {
            cout << "Encontrado! Codigo: " << inventario[i].codigo << " | Precio: " << inventario[i].precio << endl;
            encontrado = true;
        }
    }
    if(!encontrado) cout << "No encontrado." << endl;
}

void mayorStock(Producto inventario[], int n) {
    if(n == 0) return;
    int maxIdx = 0;
    for(int i = 1; i < n; i++) {
        if(inventario[i].stock > inventario[maxIdx].stock) maxIdx = i;
    }
    cout << "Producto con mayor stock: " << inventario[maxIdx].nombre << " (" << inventario[maxIdx].stock << ")" << endl;
}

void masCaro(Producto inventario[], int n) {
    if(n == 0) return;
    int caroIdx = 0;
    for(int i = 1; i < n; i++) {
        if(inventario[i].precio > inventario[caroIdx].precio) caroIdx = i;
    }
    cout << "Producto mas caro: " << inventario[caroIdx].nombre << " ($" << inventario[caroIdx].precio << ")" << endl;
}

void valorTotalInventario(Producto inventario[], int n) {
    float total = 0;
    for(int i = 0; i < n; i++) {
        total += (inventario[i].precio * inventario[i].stock);
    }
    cout << "Valor total del inventario: $" << total << endl;
}