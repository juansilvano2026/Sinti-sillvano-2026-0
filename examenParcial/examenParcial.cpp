#include <iostream>

using namespace std;

int main() {
    int opcion = 0;
    bool diaCerrado = false;

    // Variables para el Reporte de Ventas (Opción 2)
    double ingresoNeto = 0;
    int ventasValidas = 0;
    int devoluciones = 0;
    int transInv = 0;
    double mayorIngreso = 0;
    double menorIngreso = 0;
    double sumaIngresosVentas = 0;
    bool primeraTransValida = true;

    // Variables para la Opción 1
    int unidades, codigo;
    double precio;

    do {
        cout << "\n--- MENU DEL SISTEMA ---" << endl;
        cout << "1) Registrar transaccion" << endl;
        cout << "2) Reporte de ventas del dia" << endl;
        cout << "3) Reporte por transaccion (A / B / C / D)" << endl;
        cout << "4) Cerrar dia" << endl;
        cout << "5) Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            if (diaCerrado) {
                cout << "NO SE PUEDEN REGISTRAR MAS TRANSACCIONES. DIA CERRADO." << endl; // [cite: 32]
            } else {
                cout << "Ingrese unidades, precio y codigo: ";
                cin >> unidades >> precio >> codigo;

                // Validación de transacción [cite: 12, 13]
                if (unidades != 0 && precio > 0) {
                    double ingresoActual = unidades * precio;
                    ingresoNeto += ingresoActual;

                    if (unidades > 0) {
                        ventasValidas++;
                        sumaIngresosVentas += ingresoActual;
                    } else {
                        devoluciones++;
                    }

                    // Cálculo de mayor y menor ingreso [cite: 15]
                    if (primeraTransValida) {
                        mayorIngreso = ingresoActual;
                        menorIngreso = ingresoActual;
                        primeraTransValida = false;
                    } else {
                        if (ingresoActual > mayorIngreso) mayorIngreso = ingresoActual;
                        if (ingresoActual < menorIngreso) menorIngreso = ingresoActual;
                    }

                    // Opción 3: Reporte por transacción "al vuelo" 
                    // (Como no podemos usar arreglos, el reporte se genera conforme se registra)
                    int tempCodigo = codigo;
                    if (tempCodigo < 0) tempCodigo = -tempCodigo;

                    int sumaDigitos = 0;
                    int contadorDigitos = 0;
                    int aux = tempCodigo;

                    // Procesar dígitos con % y / 
                    if (aux == 0) contadorDigitos = 1;
                    while (aux > 0) {
                        sumaDigitos += (aux % 10);
                        aux /= 10;
                        contadorDigitos++;
                    }

                    // Lógica de letras A, B, C, D
                    if (sumaDigitos % 2 == 0 && tempCodigo % 4 == 0) {
                        cout << "-> Clasificacion: A" << endl;
                    } else if (sumaDigitos % 2 != 0 && tempCodigo % 6 == 0) {
                        cout << "-> Clasificacion: B" << endl;
                    } else if (contadorDigitos == 3) {
                        cout << "-> Clasificacion: C" << endl;
                    } else {
                        cout << "-> Clasificacion: D" << endl;
                    }

                } else {
                    transInv++; // [cite: 12]
                }
            }
        } 
        else if (opcion == 2) {
            // [cite: 15]
            cout << "INGRESO_NETO=" << ingresoNeto << endl;
            cout << "VENTAS_VALIDAS=" << ventasValidas << endl;
            cout << "DEVOLUCIONES=" << devoluciones << endl;
            cout << "TRANS_INVALIDAS=" << transInv << endl;
            cout << "MAYOR_ING=" << mayorIngreso << endl;
            cout << "MENOR_ING=" << menorIngreso << endl;

            if (ventasValidas > 0) {
                cout << "PROM_VENTA=" << (sumaIngresosVentas / ventasValidas) << endl;
            } else {
                cout << "PROM_VENTA=NO EXISTE" << endl;
            }
        }
        else if (opcion == 3) {
            cout << "(Nota: Las letras se mostraron al registrar cada transaccion valida segun la regla de 'orden registrado')" << endl;
        }
        else if (opcion == 4) {
            diaCerrado = true; // [cite: 22]
            cout << "Dia cerrado. No se admiten mas transacciones." << endl;
        }

    } while (opcion != 5);

    return 0;
}