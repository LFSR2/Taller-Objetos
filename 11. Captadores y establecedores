#include <iostream>
#include <string>

using namespace std;

// ==========================================
// EJERCICIO 1.1: CLASE VEHICULO
// ==========================================

class Vehiculo {
private:
    string marca;
    string modelo;
    int anio;
    double velocidadMaxima;

public:
    // Constructor
    Vehiculo(string _marca, string _modelo, int _anio, double _velocidadMaxima) {
        marca = _marca;
        modelo = _modelo;
        // Usamos los setters para aplicar las validaciones desde el inicio
        setAnio(_anio);
        setVelocidadMaxima(_velocidadMaxima);
    }

    // Getters
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getAnio() const { return anio; }
    double getVelocidadMaxima() const { return velocidadMaxima; }

    // Setters con validaciones
    void setMarca(string _marca) { marca = _marca; }
    
    void setModelo(string _modelo) { modelo = _modelo; }

    void setAnio(int _anio) {
        if (_anio > 1886) {
            anio = _anio;
        } else {
            cout << "Error: El anio debe ser mayor a 1886." << endl;
            // Asignamos un valor por defecto o mantenemos el anterior en caso de error
            // Aqui, para el ejemplo, si falla en el constructor podriamos poner 2000 por defecto
            if (anio < 1886) anio = 2000; 
        }
    }

    void setVelocidadMaxima(double _velocidad) {
        if (_velocidad > 0) {
            velocidadMaxima = _velocidad;
        } else {
            cout << "Error: La velocidad debe ser positiva." << endl;
            if (velocidadMaxima <= 0) velocidadMaxima = 100; // Valor por defecto
        }
    }

    // Metodos solicitados
    void mostrarInfo() {
        cout << "--- Informacion del Vehiculo ---" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Anio: " << anio << endl;
        cout << "Velocidad Maxima: " << velocidadMaxima << " km/h" << endl;
        cout << "--------------------------------" << endl;
    }

    void acelerar(double incremento) {
        if (incremento > 0) {
            velocidadMaxima += incremento;
            cout << "El vehiculo ha acelerado. Nueva velocidad maxima: " 
                 << velocidadMaxima << " km/h" << endl;
        } else {
            cout << "El incremento debe ser positivo." << endl;
        }
    }
};

// ==========================================
// EJERCICIO 1.2: CLASE PRODUCTO
// ==========================================

class Producto {
private:
    string codigo;
    string nombre;
    double precio;
    int cantidad;

public:
    // Constructor
    Producto(string _codigo, string _nombre, double _precio, int _cantidad) {
        codigo = _codigo;
        nombre = _nombre;
        setPrecio(_precio);
        setCantidad(_cantidad);
    }

    // Getters
    string getCodigo() const { return codigo; }
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }

    // Setters con validaciones
    void setCodigo(string _codigo) { codigo = _codigo; }
    void setNombre(string _nombre) { nombre = _nombre; }

    void setPrecio(double _precio) {
        if (_precio >= 0) {
            precio = _precio;
        } else {
            cout << "Error: El precio no puede ser negativo." << endl;
            if (precio < 0) precio = 0;
        }
    }

    void setCantidad(int _cantidad) {
        if (_cantidad >= 0) {
            cantidad = _cantidad;
        } else {
            cout << "Error: La cantidad no puede ser negativa." << endl;
            if (cantidad < 0) cantidad = 0;
        }
    }

    // Metodos de logica de negocio
    double calcularValorTotal() {
        return precio * cantidad;
    }

    void aplicarDescuento(double porcentaje) {
        if (porcentaje >= 0 && porcentaje <= 100) {
            double descuento = precio * (porcentaje / 100);
            precio -= descuento;
            cout << "Descuento del " << porcentaje << "% aplicado. Nuevo precio: $" << precio << endl;
        } else {
            cout << "Error: Porcentaje de descuento invalido." << endl;
        }
    }

    void mostrarInfo() {
        cout << "--- Informacion del Producto ---" << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Precio Unitario: $" << precio << endl;
        cout << "Cantidad en Stock: " << cantidad << endl;
        cout << "--------------------------------" << endl;
    }
};

// ==========================================
// MAIN - PRUEBAS
// ==========================================

int main() {
    // Prueba Ejercicio 1.1: Vehiculo
    cout << "=== PRUEBA NIVEL 1.1: VEHICULO ===" << endl;
    Vehiculo auto1("Toyota", "Corolla", 2023, 180);
    
    auto1.mostrarInfo();
    
    // Probando validacion (anio incorrecto)
    cout << "Intentando poner anio 1800..." << endl;
    auto1.setAnio(1800); 
    
    // Acelerando
    auto1.acelerar(20);
    auto1.mostrarInfo();

    cout << endl;

    // Prueba Ejercicio 1.2: Producto
    cout << "=== PRUEBA NIVEL 1.2: PRODUCTO ===" << endl;
    Producto laptop("001", "Laptop HP", 850.00, 5);
    
    laptop.mostrarInfo();
    cout << "Valor total del inventario: $" << laptop.calcularValorTotal() << endl;
    
    // Aplicando descuento
    laptop.aplicarDescuento(10); // 10%
    laptop.mostrarInfo();

    return 0;
