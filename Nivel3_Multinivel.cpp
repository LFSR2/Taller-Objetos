NIVEL 3===============================================================================

3.1

#include <iostream>
#include <string>

using namespace std;

// ==========================================
// CLASES (Animal, Mamifero, Ave, etc.)
// ==========================================

class Animal {
protected:
    string nombre;
    int edad;
    double peso;

public:
    Animal(string _nombre, int _edad, double _peso) {
        nombre = _nombre;
        edad = _edad;
        peso = _peso;
    }

    virtual void hacerSonido() {
        cout << "El animal hace un sonido generico..." << endl;
    }

    virtual void mostrarInfo() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << ", Peso: " << peso << "kg";
    }
};

class Mamifero : public Animal {
protected:
    bool tienePelo;

public:
    Mamifero(string _nombre, int _edad, double _peso, bool _tienePelo)
        : Animal(_nombre, _edad, _peso) {
        tienePelo = _tienePelo;
    }

    void mostrarInfo() override {
        Animal::mostrarInfo();
        cout << ", Tipo: Mamifero, Tiene Pelo: " << (tienePelo ? "Si" : "No") << endl;
    }
};

class Ave : public Animal {
protected:
    double envergaduraAlas;

public:
    Ave(string _nombre, int _edad, double _peso, double _envergadura)
        : Animal(_nombre, _edad, _peso) {
        envergaduraAlas = _envergadura;
    }

    void mostrarInfo() override {
        Animal::mostrarInfo();
        cout << ", Tipo: Ave, Envergadura: " << envergaduraAlas << "m" << endl;
    }
};

class Perro : public Mamifero {
public:
    Perro(string _nombre, int _edad, double _peso, bool _tienePelo)
        : Mamifero(_nombre, _edad, _peso, _tienePelo) {}

    void hacerSonido() override {
        cout << nombre << " dice: GUAU GUAU!" << endl;
    }
};

class Gato : public Mamifero {
public:
    Gato(string _nombre, int _edad, double _peso, bool _tienePelo)
        : Mamifero(_nombre, _edad, _peso, _tienePelo) {}

    void hacerSonido() override {
        cout << nombre << " dice: MIAU MIAU!" << endl;
    }
};

class Loro : public Ave {
public:
    Loro(string _nombre, int _edad, double _peso, double _envergadura)
        : Ave(_nombre, _edad, _peso, _envergadura) {}

    void hacerSonido() override {
        cout << nombre << " dice: Quiere galleta!" << endl;
    }
};

class Aguila : public Ave {
public:
    Aguila(string _nombre, int _edad, double _peso, double _envergadura)
        : Ave(_nombre, _edad, _peso, _envergadura) {}

    void hacerSonido() override {
        cout << nombre << " hace: Screeeech!" << endl;
    }
};

// ==========================================
// MAIN (PUNTO DE ENTRADA OBLIGATORIO)
// ==========================================
int main() {
    cout << "=== ZOOLOGICO VIRTUAL ===" << endl;
    
    Perro miPerro("Firulais", 5, 12.5, true);
    Gato miGato("Michi", 3, 4.2, true);
    Loro miLoro("Pepe", 2, 0.5, 0.3);
    Aguila miAguila("Cazadora", 4, 6.0, 2.1);

    miPerro.mostrarInfo();
    miPerro.hacerSonido();
    cout << endl;

    miGato.mostrarInfo();
    miGato.hacerSonido();
    cout << endl;

    miLoro.mostrarInfo();
    miLoro.hacerSonido();
    cout << endl;

    miAguila.mostrarInfo();
    miAguila.hacerSonido();

    return 0;
}




---------------------------------------------------------------------

3.2

#include <iostream>
#include <string>  // Necesaria para usar 'string'
#include <cmath>   // Necesaria para usar 'abs' (valor absoluto)

using namespace std; // Necesario para no escribir std::string o std::cout

// ==========================================
// CLASE BASE: CUENTA
// ==========================================
class Cuenta {
protected:
    string numeroCuenta;
    string propietario;
    double saldo;

public:
    Cuenta(string _num, string _prop, double _saldo) {
        numeroCuenta = _num;
        propietario = _prop;
        saldo = _saldo;
    }

    virtual void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            cout << "Deposito de $" << monto << " exitoso." << endl;
        } else {
            cout << "Error: Monto invalido." << endl;
        }
    }

    virtual void retirar(double monto) {
        if (monto > 0 && saldo >= monto) {
            saldo -= monto;
            cout << "Retiro de $" << monto << " exitoso. Saldo restante: $" << saldo << endl;
        } else {
            cout << "Error: Fondos insuficientes." << endl;
        }
    }

    virtual void mostrarInfo() {
        cout << "Cuenta: " << numeroCuenta << " | Propietario: " << propietario 
             << " | Saldo: $" << saldo << endl;
    }
};

// ==========================================
// CUENTA DE AHORRO
// ==========================================
class CuentaAhorro : public Cuenta {
private:
    double tasaInteres; 

public:
    CuentaAhorro(string _num, string _prop, double _saldo, double _tasa)
        : Cuenta(_num, _prop, _saldo) {
        tasaInteres = _tasa;
    }

    void generarInteres() {
        double interes = saldo * tasaInteres;
        saldo += interes; 
        cout << "Interes generado: $" << interes << ". Nuevo Saldo: $" << saldo << endl;
    }

    void mostrarInfo() override {
        cout << "[AHORRO] ";
        Cuenta::mostrarInfo();
    }
};

// ==========================================
// CUENTA CORRIENTE
// ==========================================
class CuentaCorriente : public Cuenta {
private:
    double limiteDescubierto; 

public:
    CuentaCorriente(string _num, string _prop, double _saldo, double _limite)
        : Cuenta(_num, _prop, _saldo) {
        limiteDescubierto = _limite;
    }

    void retirar(double monto) override {
        double capacidadTotal = saldo + limiteDescubierto;

        if (monto > 0 && monto <= capacidadTotal) {
            saldo -= monto;
            cout << "Retiro de $" << monto << " exitoso." << endl;
            if (saldo < 0) {
                // Aqui usamos abs() que requiere <cmath>
                cout << "ATENCION: Estas usando tu sobregiro. Saldo actual: -$" << abs(saldo) << endl;
            } else {
                cout << "Saldo restante: $" << saldo << endl;
            }
        } else {
            cout << "Error: Excedes tu limite de sobregiro." << endl;
        }
    }

    void mostrarInfo() override {
        cout << "[CORRIENTE] ";
        Cuenta::mostrarInfo();
        cout << "Limite de descubierto disponible: $" << limiteDescubierto << endl;
    }
};

// ==========================================
// MAIN PRINCIPAL
// ==========================================
int main() {
    cout << "=== SISTEMA BANCARIO ===" << endl;

    CuentaAhorro miAhorro("AH-100", "Carlos Perez", 5000, 0.05);
    CuentaCorriente miCorriente("CC-200", "Ana Gomez", 1000, 500);

    // Pruebas Ahorro
    miAhorro.mostrarInfo();
    miAhorro.generarInteres();
    
    cout << "------------------" << endl;

    // Pruebas Corriente
    miCorriente.mostrarInfo();
    cout << "Intentando retirar $1200 (teniendo 1000 + 500 cupo)..." << endl;
    miCorriente.retirar(1200); 
    
    cout << "Intentando retirar $400 mas..." << endl;
    miCorriente.retirar(400); 

    return 0;
}
