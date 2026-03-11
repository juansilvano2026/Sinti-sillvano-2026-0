#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// =======================
// EXCEPCION PERSONALIZADA
// =======================
class CuentaNoEncontrada : public runtime_error {
public:
    CuentaNoEncontrada(const string& mensaje)
        : runtime_error(mensaje) {}
};

// =======================
// CLASE CUENTA BANCARIA
// =======================
class CuentaBancaria {
private:
    int numeroCuenta;
    string titular;
    double saldo;

public:
    CuentaBancaria(int numero, string nombre, double saldoInicial)
        : numeroCuenta(numero), titular(nombre), saldo(saldoInicial) {}

    void depositar(double monto) {
        if (monto <= 0) {
            throw invalid_argument("El monto a depositar debe ser positivo.");
        }
        saldo += monto;
    }

    void retirar(double monto) {
        if (monto <= 0) {
            throw invalid_argument("El monto a retirar debe ser positivo.");
        }
        if (monto > saldo) {
            throw runtime_error("Saldo insuficiente.");
        }
        saldo -= monto;
    }

    double consultarSaldo() const {
        return saldo;
    }

    int getNumeroCuenta() const {
        return numeroCuenta;
    }

    void mostrarInfo() const {
        cout << "Cuenta: " << numeroCuenta
             << " | Titular: " << titular
             << " | Saldo: S/ " << saldo << endl;
    }
};

// =======================
// CLASE BANCO
// =======================
class Banco {
private:
    vector<CuentaBancaria> cuentas;

public:
    void agregarCuenta(int numero, string titular, double saldoInicial) {
        cuentas.push_back(CuentaBancaria(numero, titular, saldoInicial));
    }

    CuentaBancaria& buscarCuenta(int numero) {
        for (auto& cuenta : cuentas) {
            if (cuenta.getNumeroCuenta() == numero) {
                return cuenta;
            }
        }
        throw CuentaNoEncontrada("La cuenta no existe.");
    }

    void mostrarCuentas() const {
        if (cuentas.empty()) {
            cout << "No hay cuentas registradas.\n";
            return;
        }

        for (const auto& cuenta : cuentas) {
            cuenta.mostrarInfo();
        }
    }
};

// =======================
// PROGRAMA PRINCIPAL
// =======================
int main() {
    Banco banco;
    int opcion;

    do {
        try {
            cout << "\n===== SISTEMA BANCARIO =====\n";
            cout << "1. Crear cuenta\n";
            cout << "2. Depositar dinero\n";
            cout << "3. Retirar dinero\n";
            cout << "4. Consultar saldo\n";
            cout << "5. Mostrar todas las cuentas\n";
            cout << "6. Salir\n";
            cout << "Seleccione una opcion: ";

            if (!(cin >> opcion)) {
                cin.clear();
                cin.ignore(1000, '\n');
                throw invalid_argument("Debe ingresar un numero.");
            }

            if (opcion < 1 || opcion > 6) {
                throw out_of_range("Opcion fuera de rango.");
            }

            int numero;
            string nombre;
            double monto;

            switch (opcion) {
            case 1:
                cout << "Numero de cuenta: ";
                cin >> numero;
                cout << "Titular: ";
                cin >> nombre;
                cout << "Saldo inicial: ";
                cin >> monto;

                banco.agregarCuenta(numero, nombre, monto);
                cout << "Cuenta creada exitosamente.\n";
                break;

            case 2:
                cout << "Numero de cuenta: ";
                cin >> numero;
                cout << "Monto a depositar: ";
                cin >> monto;

                banco.buscarCuenta(numero).depositar(monto);
                cout << "Deposito realizado.\n";
                break;

            case 3:
                cout << "Numero de cuenta: ";
                cin >> numero;
                cout << "Monto a retirar: ";
                cin >> monto;

                banco.buscarCuenta(numero).retirar(monto);
                cout << "Retiro realizado.\n";
                break;

            case 4:
                cout << "Numero de cuenta: ";
                cin >> numero;

                cout << "Saldo actual: S/ "
                     << banco.buscarCuenta(numero).consultarSaldo()
                     << endl;
                break;

            case 5:
                banco.mostrarCuentas();
                break;

            case 6:
                cout << "Saliendo del sistema...\n";
                break;
            }

        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const CuentaNoEncontrada& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (...) {
            cout << "Error inesperado.\n";
        }

    } while (opcion != 6);

    return 0;
}