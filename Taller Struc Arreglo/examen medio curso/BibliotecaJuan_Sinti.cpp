#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
==================== BITÁCORA IA ====================
Herramienta IA usada: chatGPT

Objetivo del uso:
Verificar que el manejo de memoria esté bien, que las validaciones no fallen y que la búsqueda funcione aunque escriban en mayúsculas o minúsculas.
Preguntas que hice a la IA:
1) Cómo evitar que se repitan los IDs cuando uso arreglos dinámicos?
2) Cómo hacer que un libro no se pueda prestar dos veces
3) Como implementar búsqueda sin distinguir mayúsculas y minúsculas

Qué sugerencias acepté y por qué:
a) que antes de agregar algo al sistema, verificar si ya extistia, y gracias a ello pude evitar errores como
Libros con el mismo ID, Usuarios duplicados y Prestar libros que no existen.
b) Convertir el texto a minúsculas antes de comparar, Lo acepte porque permite
 que la búsqueda funcione sin importar cómo el usuario escriba el texto.
c) Mostrar préstamos con datos completos (usuario + libro)

Qué sugerencias rechacé y por qué:
- Uso de std::vector (porque no esta permitido Jeje).

Test manual diseñado por mí:
Entrada:
- Agregar Libro 101
- Agregar Usuario 1
- Prestar 101 a 1
- Intente prestar 101 nuevamente
- Devolver 101

Salida esperada:
- Primer préstamo exitoso
- Segundo préstamo rechazado
- Libro vuelve a disponible tras devolución

Declaro que entiendo el código entregado y puedo explicarlo.
====================================================
*/

struct Libro {
    int id;
    string titulo;
    string autor;
    int anio;
    bool disponible;
};

struct Usuario {
    int id;
    string nombre;
    string carrera;
};

struct Prestamo {
    int idLibro;
    int idUsuario;
};

template <typename T>
void redimensionar(T*& arreglo, int& capacidad) {
    int nuevaCapacidad = capacidad * 2;
    T* nuevo = new T[nuevaCapacidad];
    for (int i = 0; i < capacidad; i++)
        nuevo[i] = arreglo[i];
    delete[] arreglo;
    arreglo = nuevo;
    capacidad = nuevaCapacidad;
}

Libro* buscarLibroPorId(Libro* libros, int cantidad, int id) {
    for (int i = 0; i < cantidad; i++)
        if (libros[i].id == id)
            return &libros[i];
    return nullptr;
}

Usuario* buscarUsuarioPorId(Usuario* usuarios, int cantidad, int id) {
    for (int i = 0; i < cantidad; i++)
        if (usuarios[i].id == id)
            return &usuarios[i];
    return nullptr;
}

bool existePrestamo(Prestamo* prestamos, int cantidad, int idLibro) {
    for (int i = 0; i < cantidad; i++)
        if (prestamos[i].idLibro == idLibro)
            return true;
    return false;
}

void agregarLibro(Libro*& libros, int& cantidad, int& capacidad) {
    if (cantidad == capacidad) redimensionar(libros, capacidad);

    int id;
    cout << "ID Libro: ";
    cin >> id;

    if (buscarLibroPorId(libros, cantidad, id) != nullptr) {
        cout << "ID repetido.\n";
        return;
    }

    Libro nuevo;
    nuevo.id = id;
    cin.ignore();
    cout << "Titulo: ";
    getline(cin, nuevo.titulo);
    cout << "Autor: ";
    getline(cin, nuevo.autor);
    cout << "Anio: ";
    cin >> nuevo.anio;
    nuevo.disponible = true;

    libros[cantidad++] = nuevo;
    cout << "Libro agregado correctamente.\n";
}

void listarLibros(Libro* libros, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << libros[i].id << " | "
             << libros[i].titulo << " | "
             << libros[i].autor << " | "
             << libros[i].anio << " | "
             << (libros[i].disponible ? "Disponible" : "Prestado") << endl;
    }
}

void agregarUsuario(Usuario*& usuarios, int& cantidad, int& capacidad) {
    if (cantidad == capacidad) redimensionar(usuarios, capacidad);

    int id;
    cout << "ID Usuario: ";
    cin >> id;

    if (buscarUsuarioPorId(usuarios, cantidad, id) != nullptr) {
        cout << "ID repetido.\n";
        return;
    }

    Usuario nuevo;
    nuevo.id = id;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, nuevo.nombre);
    cout << "Carrera: ";
    getline(cin, nuevo.carrera);

    usuarios[cantidad++] = nuevo;
    cout << "Usuario agregado correctamente.\n";
}

void listarUsuarios(Usuario* usuarios, int cantidad) {
    for (int i = 0; i < cantidad; i++)
        cout << usuarios[i].id << " | "
             << usuarios[i].nombre << " | "
             << usuarios[i].carrera << endl;
}

void prestarLibro(Libro* libros, int cantL,
                  Prestamo*& prestamos, int& cantP, int& capP,
                  Usuario* usuarios, int cantU) {

    int idL, idU;
    cout << "ID Libro: ";
    cin >> idL;
    cout << "ID Usuario: ";
    cin >> idU;

    Libro* libro = buscarLibroPorId(libros, cantL, idL);
    Usuario* usuario = buscarUsuarioPorId(usuarios, cantU, idU);

    if (!libro) {
        cout << "Libro no existe.\n";
        return;
    }

    if (!usuario) {
        cout << "Usuario no existe.\n";
        return;
    }

    if (!libro->disponible || existePrestamo(prestamos, cantP, idL)) {
        cout << "Libro no disponible.\n";
        return;
    }

    if (cantP == capP) redimensionar(prestamos, capP);

    prestamos[cantP++] = {idL, idU};
    libro->disponible = false;

    cout << "Prestamo realizado correctamente.\n";
}

void devolverLibro(Libro* libros, int cantL,
                   Prestamo* prestamos, int& cantP) {

    int idL;
    cout << "ID Libro a devolver: ";
    cin >> idL;

    Libro* libro = buscarLibroPorId(libros, cantL, idL);

    if (!libro || libro->disponible) {
        cout << "Libro no prestado o inexistente.\n";
        return;
    }

    libro->disponible = true;

    for (int i = 0; i < cantP; i++) {
        if (prestamos[i].idLibro == idL) {
            prestamos[i] = prestamos[cantP - 1];
            cantP--;
            break;
        }
    }

    cout << "Devolucion exitosa.\n";
}

void listarPrestamos(Prestamo* prestamos, int cantP,
                     Libro* libros, int cantL,
                     Usuario* usuarios, int cantU) {

    cout << "\n--- PRESTAMOS ACTIVOS ---\n";

    for (int i = 0; i < cantP; i++) {
        Libro* libro = buscarLibroPorId(libros, cantL, prestamos[i].idLibro);
        Usuario* usuario = buscarUsuarioPorId(usuarios, cantU, prestamos[i].idUsuario);

        if (libro && usuario) {
            cout << "Usuario: " << usuario->nombre
                 << " | Libro: " << libro->titulo << endl;
        }
    }
}

string aMinusculas(string texto) {
    transform(texto.begin(), texto.end(), texto.begin(), ::tolower);
    return texto;
}

void buscarPorTexto(Libro* libros, int cantidad) {
    string busqueda;
    cin.ignore();
    cout << "Texto a buscar: ";
    getline(cin, busqueda);

    busqueda = aMinusculas(busqueda);

    for (int i = 0; i < cantidad; i++) {
        string titulo = aMinusculas(libros[i].titulo);
        string autor = aMinusculas(libros[i].autor);

        if (titulo.find(busqueda) != string::npos ||
            autor.find(busqueda) != string::npos) {
            cout << "Encontrado: "
                 << libros[i].titulo
                 << " - " << libros[i].autor << endl;
        }
    }
}

int main() {

    int capL = 5, cantL = 0;
    Libro* biblioteca = new Libro[capL];

    int capU = 5, cantU = 0;
    Usuario* usuarios = new Usuario[capU];

    int capP = 5, cantP = 0;
    Prestamo* prestamos = new Prestamo[capP];

    int opcion;

    do {
        cout << "\n--- SISTEMA BIBLIOTECA ---\n";
        cout << "1. Agregar Libro\n";
        cout << "2. Listar Libros\n";
        cout << "3. Agregar Usuario\n";
        cout << "4. Listar Usuarios\n";
        cout << "5. Prestar Libro\n";
        cout << "6. Devolver Libro\n";
        cout << "7. Buscar Libro\n";
        cout << "8. Mostrar Prestamos\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: agregarLibro(biblioteca, cantL, capL); break;
            case 2: listarLibros(biblioteca, cantL); break;
            case 3: agregarUsuario(usuarios, cantU, capU); break;
            case 4: listarUsuarios(usuarios, cantU); break;
            case 5: prestarLibro(biblioteca, cantL, prestamos, cantP, capP, usuarios, cantU); break;
            case 6: devolverLibro(biblioteca, cantL, prestamos, cantP); break;
            case 7: buscarPorTexto(biblioteca, cantL); break;
            case 8: listarPrestamos(prestamos, cantP, biblioteca, cantL, usuarios, cantU); break;
        }

    } while (opcion != 0);

    delete[] biblioteca;
    delete[] usuarios;
    delete[] prestamos;

    return 0;
}
