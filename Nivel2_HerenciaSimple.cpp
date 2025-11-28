
NIVEL 2=====================================================================

#include <iostream>
#include <string>

using namespace std;

// ==========================================
// EJERCICIO 2.1: HERENCIA DE VEHICULOS
// ==========================================

// Clase Base
class Vehiculo {
protected: // Cambiado de private a protected para herencia
    string marca;
    string modelo;
    int anio;
    double velocidadMaxima;

public:
    Vehiculo(string _marca, string _modelo, int _anio, double _velocidad) {
        marca = _marca;
        modelo = _modelo;
        anio = _anio;
        velocidadMaxima = _velocidad;
    }

    // Metodo virtual para permitir sobrescritura (override)
    virtual void mostrarInfo() {
        cout << "- Vehiculo Generico -" << endl;
        cout << "Marca: " << marca << ", Modelo: " << modelo 
             << ", Anio: " << anio << ", Vel. Max: " << velocidadMaxima << " km/h" << endl;
    }

    // Getters y Setters necesarios se heredan automaticamente
    void setVelocidadMaxima(double v) { velocidadMaxima = v; }
};

// Clase Derivada: Auto
class Auto : public Vehiculo {
private:
    int numeroPuertas;
    string tipoCombustible;

public:
    // Constructor: Pasa los datos comunes al constructor de Vehiculo
    Auto(string _marca, string _modelo, int _anio, double _velocidad, int _puertas, string _combustible)
        : Vehiculo(_marca, _modelo, _anio, _velocidad) {
        numeroPuertas = _puertas;
        tipoCombustible = _combustible;
    }

    // Sobrescritura de mostrarInfo
    void mostrarInfo() override {
        cout << "--- Ficha de Automovil ---" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Anio: " << anio << endl;
        cout << "Velocidad Maxima: " << velocidadMaxima << " km/h" << endl;
        cout << "Puertas: " << numeroPuertas << endl;
        cout << "Combustible: " << tipoCombustible << endl;
        cout << "--------------------------" << endl;
    }
};

// Clase Derivada: Motocicleta
class Motocicleta : public Vehiculo {
private:
    bool tieneAleron;
    int cilindrada;

public:
    Motocicleta(string _marca, string _modelo, int _anio, double _velocidad, bool _aleron, int _cc)
        : Vehiculo(_marca, _modelo, _anio, _velocidad) {
        tieneAleron = _aleron;
        cilindrada = _cc;
    }

    void mostrarInfo() override {
        cout << "--- Ficha de Motocicleta ---" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
        cout << "Tiene aleron: " << (tieneAleron ? "Si" : "No") << endl;
        cout << "----------------------------" << endl;
    }
};

// ==========================================
// EJERCICIO 2.2: SISTEMA DE EMPLEADOS
// ==========================================

// Clase Base
class Empleado {
protected:
    string nombreCompleto;
    string numeroEmpleado;
    double salarioBase;

public:
    Empleado(string _nombre, string _id, double _salario) {
        nombreCompleto = _nombre;
        numeroEmpleado = _id;
        salarioBase = _salario;
    }

    virtual void mostrarInfo() {
        cout << "Empleado: " << nombreCompleto << " (ID: " << numeroEmpleado << ")" << endl;
    }

    // Virtual puro o normal? Lo dejamos normal por ahora.
    virtual double calcularSalarioTotal() {
        return salarioBase;
    }
};

// Clase Derivada: Tiempo Completo
class EmpleadoTiempoCompleto : public Empleado {
private:
    string beneficios;
    double bono;

public:
    EmpleadoTiempoCompleto(string _nombre, string _id, double _salario, string _beneficios, double _bono)
        : Empleado(_nombre, _id, _salario) {
        beneficios = _beneficios;
        bono = _bono;
    }

    double calcularSalarioTotal() override {
        return salarioBase + bono;
    }

    void mostrarInfo() override {
        cout << "--- Empleado Tiempo Completo ---" << endl;
        cout << "Nombre: " << nombreCompleto << endl;
        cout << "Beneficio: " << beneficios << endl;
        cout << "Salario Base: $" << salarioBase << endl;
        cout << "Bono: $" << bono << endl;
        cout << "TOTAL A PAGAR: $" << calcularSalarioTotal() << endl;
        cout << "--------------------------------" << endl;
    }
};

// Clase Derivada: Por Horas
class EmpleadoPorHoras : public Empleado {
private:
    int horasTrabajadas;
    double tarifaPorHora;

public:
    // Nota: Pasamos 0 en salarioBase porque este empleado cobra por horas
    EmpleadoPorHoras(string _nombre, string _id, int _horas, double _tarifa)
        : Empleado(_nombre, _id, 0) {
        horasTrabajadas = _horas;
        tarifaPorHora = _tarifa;
    }

    double calcularSalarioTotal() override {
        return horasTrabajadas * tarifaPorHora;
    }

    void mostrarInfo() override {
        cout << "--- Empleado Por Horas ---" << endl;
        cout << "Nombre: " << nombreCompleto << endl;
        cout << "Horas trabajadas: " << horasTrabajadas << endl;
        cout << "Tarifa por hora: $" << tarifaPorHora << endl;
        cout << "TOTAL A PAGAR: $" << calcularSalarioTotal() << endl;
        cout << "--------------------------" << endl;
    }
};

// ==========================================
// MAIN - PRUEBAS
// ==========================================

int main() {
    cout << "=== PRUEBA EJERCICIO 2.1: VEHICULOS ===" << endl;
    
    Auto miAuto("Ford", "Mustang", 2023, 220, 2, "Gasolina");
    Motocicleta miMoto("Harley-Davidson", "Sportster", 2023, 200, true, 1200);

    miAuto.mostrarInfo();
    cout << endl;
    miMoto.mostrarInfo();

    cout << endl << "=======================================" << endl << endl;

    cout << "=== PRUEBA EJERCICIO 2.2: EMPLEADOS ===" << endl;
    
    EmpleadoTiempoCompleto emp1("Juan Lopez", "001", 2000, "Seguro Medico", 500);
    EmpleadoPorHoras emp2("Maria Garcia", "002", 40, 15);

    emp1.mostrarInfo();
    cout << endl;
    emp2.mostrarInfo();

    return 0;
}
