#include <iostream>
#include <vector>
using namespace std;

// -------- INTERFAZ --------
class Notificador {
public:
    virtual void enviar(string mensaje) = 0;
    virtual ~Notificador() {}
};

class NotificadorEmail : public Notificador {
public:
    void enviar(string mensaje) override {
        cout << "Email: " << mensaje << endl;
    }
};

class NotificadorSMS : public Notificador {
public:
    void enviar(string mensaje) override {
        cout << "SMS: " << mensaje << endl;
    }
};

// -------- ITEMS --------
class ItemPrestable {
protected:
    string titulo;
public:
    ItemPrestable(string t) : titulo(t) {}
    virtual int diasPrestamo() = 0;
    virtual ~ItemPrestable() {}
};

class Libro : public ItemPrestable {
public:
    Libro(string t) : ItemPrestable(t) {}
    int diasPrestamo() override { return 15; }
};

class Revista : public ItemPrestable {
public:
    Revista(string t) : ItemPrestable(t) {}
    int diasPrestamo() override { return 7; }
};

// -------- USUARIOS --------
class Usuario {
protected:
    string nombre;
public:
    Usuario(string n) : nombre(n) {}
    virtual int getMaxPrestamos() = 0;
    virtual ~Usuario() {}
};

class Estudiante : public Usuario {
public:
    Estudiante(string n) : Usuario(n) {}
    int getMaxPrestamos() override { return 3; }
};

class Docente : public Usuario {
public:
    Docente(string n) : Usuario(n) {}
    int getMaxPrestamos() override { return 5; }
};

// -------- EJEMPLAR --------
class Ejemplar {
private:
    int codigo;
    ItemPrestable* item;
public:
    Ejemplar(int c, ItemPrestable* i) : codigo(c), item(i) {}
    ItemPrestable* getItem() { return item; }
};

// -------- PRESTAMO --------
class Prestamo {
private:
    Usuario* usuario;
    Ejemplar* ejemplar;
public:
    Prestamo(Usuario* u, Ejemplar* e)
        : usuario(u), ejemplar(e) {}
};

// -------- BIBLIOTECA --------
class Biblioteca {
private:
    vector<Ejemplar> ejemplares;      // COMPOSICIÓN
    vector<Usuario*> usuarios;        // AGREGACIÓN
    Notificador* notificador;

public:
    Biblioteca(Notificador* n) : notificador(n) {}

    void agregarEjemplar(Ejemplar e) {
        ejemplares.push_back(e);
    }

    void registrarUsuario(Usuario* u) {
        usuarios.push_back(u);
    }

    void notificar(string msg) {
        notificador->enviar(msg);   // POLIMORFISMO
    }
};

// -------- MAIN --------
int main() {
    Notificador* notif = new NotificadorEmail();

    Biblioteca biblio(notif);

    Usuario* u1 = new Estudiante("Juan");
    biblio.registrarUsuario(u1);

    ItemPrestable* libro = new Libro("POO en C++");
    Ejemplar ej1(1, libro);

    biblio.agregarEjemplar(ej1);

    biblio.notificar("Prestamo realizado");

    return 0;
}