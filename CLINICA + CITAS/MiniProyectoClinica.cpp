#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

using namespace std;

/* ================= EXCEPCIÓN PERSONALIZADA ================= */

class EntidadNoEncontrada : public runtime_error {
public:
    EntidadNoEncontrada(string msg) : runtime_error(msg) {}
};

/* ================= COMPOSICIÓN ================= */

class EntradaHistoria {
public:
    string fecha;
    string nota;

    EntradaHistoria(string f, string n) : fecha(f), nota(n) {}
};

class HistoriaClinica {
private:
    vector<unique_ptr<EntradaHistoria>> entradas;

public:
    void agregarEntrada(string fecha, string nota) {
        entradas.push_back(make_unique<EntradaHistoria>(fecha, nota));
    }
};

/* ================= HERENCIA ================= */

class Persona {
protected:
    string nombre;

public:
    Persona(string n) : nombre(n) {}
    virtual ~Persona() = default;

    virtual void mostrar() const = 0;

    string getNombre() const {
        return nombre;
    }
};

/* ================= PACIENTE ================= */

class Paciente : public Persona {

private:
    string dni;
    int edad;
    string telefono;
    HistoriaClinica historia;

public:
    Paciente(string n, string d, int e, string t)
        : Persona(n), dni(d), edad(e), telefono(t) {

        if (d.length() != 8)
            throw invalid_argument("DNI debe tener 8 digitos");

        if (e < 0 || e > 120)
            throw invalid_argument("Edad invalida");

        if (t.length() != 9)
            throw invalid_argument("Telefono debe tener 9 digitos");
    }

    void mostrar() const override {
        cout << "[Paciente] " << nombre << " | DNI: " << dni << endl;
    }

    string getDni() const {
        return dni;
    }
};

/* ================= DOCTOR ================= */

class Doctor : public Persona {

private:
    string codigo;
    string especialidad;
    double tarifa;

public:
    Doctor(string n, string c, string e, double t)
        : Persona(n), codigo(c), especialidad(e), tarifa(t) {

        if (t <= 0)
            throw invalid_argument("Tarifa debe ser mayor que 0");
    }

    void mostrar() const override {
        cout << "[Doctor] " << nombre << " | Especialidad: " << especialidad << endl;
    }

    string getCodigo() const {
        return codigo;
    }

    string getEspecialidad() const {
        return especialidad;
    }
};

/* ================= ASOCIACIÓN ================= */

class Cita {

private:
    int id;
    Paciente* paciente;
    Doctor* doctor;
    string fecha;
    string hora;
    string motivo;

public:
    Cita(int i, Paciente* p, Doctor* d, string f, string h, string m)
        : id(i), paciente(p), doctor(d), fecha(f), hora(h), motivo(m) {

        if (f.empty() || h.empty())
            throw invalid_argument("Fecha y hora obligatorias");
    }

    int getId() const { return id; }
    Paciente* getPaciente() const { return paciente; }
    Doctor* getDoctor() const { return doctor; }
    string getFecha() const { return fecha; }
    string getHora() const { return hora; }

    void mostrar() const {
        cout << "ID: " << id
             << " | " << fecha << " " << hora
             << " | Paciente: " << paciente->getNombre()
             << " | Doctor: " << doctor->getNombre()
             << endl;
    }
};

/* ================= CLINICA ================= */

class Clinica {

private:
    vector<unique_ptr<Paciente>> pacientes;
    vector<unique_ptr<Doctor>> doctores;
    vector<unique_ptr<Cita>> citas;

public:

    void registrarPaciente(unique_ptr<Paciente> p) {
        pacientes.push_back(move(p));
    }

    void registrarDoctor(unique_ptr<Doctor> d) {
        doctores.push_back(move(d));
    }

    Paciente* buscarPaciente(string dni) {
        for (auto& p : pacientes)
            if (p->getDni() == dni)
                return p.get();

        throw EntidadNoEncontrada("Paciente no encontrado");
    }

    Doctor* buscarDoctor(string cod) {
        for (auto& d : doctores)
            if (d->getCodigo() == cod)
                return d.get();

        throw EntidadNoEncontrada("Doctor no encontrado");
    }

    void agendarCita(int id, string dni, string cod,
                     string f, string h, string m) {

        Paciente* p = buscarPaciente(dni);
        Doctor* d = buscarDoctor(cod);

        for (auto& c : citas)
            if (c->getDoctor() == d && c->getFecha() == f && c->getHora() == h)
                throw runtime_error("Cita duplicada");

        citas.push_back(make_unique<Cita>(id, p, d, f, h, m));
    }

    void cancelarCita(int id) {

        for (auto it = citas.begin(); it != citas.end(); ++it) {

            if ((*it)->getId() == id) {
                citas.erase(it);
                cout << "Cita cancelada\n";
                return;
            }
        }

        throw runtime_error("Cita no encontrada");
    }

    void listarCitasPorPaciente(string dni) {

        bool encontrada = false;

        for (auto& c : citas)
            if (c->getPaciente()->getDni() == dni) {
                c->mostrar();
                encontrada = true;
            }

        if (!encontrada)
            cout << "No hay citas para ese paciente\n";
    }

    void listarCitasPorDoctor(string codigo) {

        bool encontrada = false;

        for (auto& c : citas)
            if (c->getDoctor()->getCodigo() == codigo) {
                c->mostrar();
                encontrada = true;
            }

        if (!encontrada)
            cout << "No hay citas para ese doctor\n";
    }

    const vector<unique_ptr<Cita>>& getCitas() const {
        return citas;
    }
};

/* ================= REPORTE ================= */

class Reporte {

public:

    static void generarPorEspecialidad(const Clinica& c) {

        cout << "\n--- REPORTE POR ESPECIALIDAD ---\n";

        for (const auto& cita : c.getCitas()) {

            cout << "Especialidad: "
                 << cita->getDoctor()->getEspecialidad()
                 << " | Cita ID: "
                 << cita->getId()
                 << endl;
        }
    }
};

/* ================= MENU ================= */

int main() {

    Clinica clinica;
    int opcion;
    int idCita = 1;

    do {

        try {

            cout << "\n=== CLINICA SALUD+ ===\n";
            cout << "1 Registrar paciente\n";
            cout << "2 Registrar doctor\n";
            cout << "3 Agendar cita\n";
            cout << "4 Cancelar cita\n";
            cout << "5 Listar citas por paciente\n";
            cout << "6 Listar citas por doctor\n";
            cout << "7 Reporte por especialidad\n";
            cout << "8 Salir\n";
            cout << "Opcion: ";

            cin >> opcion;

            if (opcion < 1 || opcion > 8)
                throw out_of_range("Opcion fuera de rango");

            if (opcion == 1) {

                string n, d, t;
                int e;

                cout << "Nombre: ";
                cin >> n;

                cout << "DNI: ";
                cin >> d;

                cout << "Edad: ";
                cin >> e;

                cout << "Telefono: ";
                cin >> t;

                clinica.registrarPaciente(
                    make_unique<Paciente>(n, d, e, t)
                );

                cout << "Paciente registrado\n";
            }

            else if (opcion == 2) {

                string n, c, e;
                double t;

                cout << "Nombre: ";
                cin >> n;

                cout << "Codigo: ";
                cin >> c;

                cout << "Especialidad: ";
                cin >> e;

                cout << "Tarifa: ";
                cin >> t;

                clinica.registrarDoctor(
                    make_unique<Doctor>(n, c, e, t)
                );

                cout << "Doctor registrado\n";
            }

            else if (opcion == 3) {

                string d, c, f, h, m;

                cout << "DNI paciente: ";
                cin >> d;

                cout << "Codigo doctor: ";
                cin >> c;

                cout << "Fecha (YYYY-MM-DD): ";
                cin >> f;

                cout << "Hora (HH:MM): ";
                cin >> h;

                cout << "Motivo: ";
                cin >> m;

                clinica.agendarCita(idCita++, d, c, f, h, m);

                cout << "Cita registrada\n";
            }

            else if (opcion == 4) {

                int id;

                cout << "ID cita: ";
                cin >> id;

                clinica.cancelarCita(id);
            }

            else if (opcion == 5) {

                string dni;

                cout << "DNI paciente: ";
                cin >> dni;

                clinica.listarCitasPorPaciente(dni);
            }

            else if (opcion == 6) {

                string cod;

                cout << "Codigo doctor: ";
                cin >> cod;

                clinica.listarCitasPorDoctor(cod);
            }

            else if (opcion == 7) {

                Reporte::generarPorEspecialidad(clinica);
            }

        }
        catch (const exception& e) {

            cout << "Error: " << e.what() << endl;
        }

    } while (opcion != 8);

    return 0;
}