NIVEL 4==============================================================

#include <iostream>
#include <string>
#include <vector> // Necesario para las listas de cursos

using namespace std;

// ==========================================
// 1. CLASE BASE: PERSONA
// ==========================================
class Persona {
protected:
    string nombre;
    int edad;
    string cedula;

public:
    Persona(string _nombre, int _edad, string _cedula) {
        nombre = _nombre;
        edad = _edad;
        cedula = _cedula;
    }

    virtual void mostrarInfo() {
        cout << "--- Datos Personales ---" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Cedula: " << cedula << endl;
    }
};

// ==========================================
// 2. CLASE DERIVADA: ESTUDIANTE
// ==========================================
class Estudiante : public Persona {
public:
    // Definimos la estructura Curso DENTRO del Estudiante
    struct Curso {
        string codigo;
        string nombreMateria;
        int creditos;
        double notaFinal;
    };

private:
    string carrera;
    int semestre;
    vector<Curso> listaCursos; // Lista dinamica de cursos

public:
    Estudiante(string _nombre, int _edad, string _cedula, string _carrera, int _semestre)
        : Persona(_nombre, _edad, _cedula) {
        carrera = _carrera;
        semestre = _semestre;
    }

    // Metodo para matricular/agregar un curso
    void matricularCurso(string _cod, string _nom, int _creditos, double _nota) {
        Curso nuevoCurso;
        nuevoCurso.codigo = _cod;
        nuevoCurso.nombreMateria = _nom;
        nuevoCurso.creditos = _creditos;
        nuevoCurso.notaFinal = _nota;

        // Lo agregamos al vector
        listaCursos.push_back(nuevoCurso);
        cout << "Curso '" << _nom << "' matriculado exitosamente." << endl;
    }

    double calcularPromedioActual() {
        if (listaCursos.empty()) return 0.0;

        double sumaNotas = 0;
        for (int i = 0; i < listaCursos.size(); i++) {
            sumaNotas += listaCursos[i].notaFinal;
        }
        return sumaNotas / listaCursos.size();
    }

    void mostrarInfo() override {
        Persona::mostrarInfo(); // Llama al padre
        cout << "Rol: Estudiante" << endl;
        cout << "Carrera: " << carrera << endl;
        cout << "Semestre: " << semestre << endl;
        cout << "Promedio acumulado: " << calcularPromedioActual() << endl;
        
        cout << "--- Cursos Inscritos ---" << endl;
        if (listaCursos.empty()) {
            cout << "No tiene cursos matriculados." << endl;
        } else {
            for (int i = 0; i < listaCursos.size(); i++) {
                cout << "  * " << listaCursos[i].nombreMateria 
                     << " (Nota: " << listaCursos[i].notaFinal << ")" << endl;
            }
        }
        cout << "------------------------" << endl;
    }
};

// ==========================================
// 3. CLASE DERIVADA: PROFESOR
// ==========================================
class Profesor : public Persona {
private:
    string especialidad;
    int aniosExperiencia;

public:
    Profesor(string _nombre, int _edad, string _cedula, string _esp, int _exp)
        : Persona(_nombre, _edad, _cedula) {
        especialidad = _esp;
        aniosExperiencia = _exp;
    }

    // Logica: Esta disponible si es horario laboral (8 a 16 horas)
    bool estaDisponible(int horaDelDia) {
        return (horaDelDia >= 8 && horaDelDia <= 16);
    }

    void mostrarInfo() override {
        Persona::mostrarInfo();
        cout << "Rol: Profesor" << endl;
        cout << "Especialidad: " << especialidad << endl;
        cout << "Experiencia: " << aniosExperiencia << " anios" << endl;
        cout << "------------------------" << endl;
    }
};

// ==========================================
// 4. CLASE DERIVADA: PERSONAL ADMINISTRATIVO
// ==========================================
class Personal : public Persona {
private:
    string puesto;
    string departamento;
    double salarioMensual;

public:
    Personal(string _nombre, int _edad, string _cedula, string _puesto, string _depto, double _salario)
        : Persona(_nombre, _edad, _cedula) {
        puesto = _puesto;
        departamento = _depto;
        salarioMensual = _salario;
    }

    void calcularSalarioConBono() {
        // Digamos que si es de "Sistemas", tiene un bono del 10%
        double total = salarioMensual;
        if (departamento == "Sistemas") {
            total += (salarioMensual * 0.10);
            cout << "Incluye bono de Sistemas." << endl;
        }
        cout << "Salario a pagar: $" << total << endl;
    }

    void mostrarInfo() override {
        Persona::mostrarInfo();
        cout << "Rol: Personal Administrativo" << endl;
        cout << "Puesto: " << puesto << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "------------------------" << endl;
    }
};

// ==========================================
// MAIN (PRUEBA FINAL)
// ==========================================
int main() {
    cout << "=== SISTEMA DE GESTION UNIVERSITARIA ===" << endl << endl;

    // 1. Crear un Estudiante
    Estudiante estudiante1("David Rios", 21, "1098765432", "Ingenieria de Sistemas", 5);
    
    // Matriculamos materias
    estudiante1.matricularCurso("PROG-1", "Programacion C++", 3, 4.5);
    estudiante1.matricularCurso("CALC-2", "Calculo Integral", 4, 3.8);
    estudiante1.matricularCurso("FIS-1", "Fisica Mecanica", 3, 4.0);

    // Mostramos info completa
    estudiante1.mostrarInfo();
    cout << endl;

    // 2. Crear un Profesor
    Profesor profe1("Jorge Ramirez", 45, "76543210", "Inteligencia Artificial", 15);
    profe1.mostrarInfo();
    
    // Probamos disponibilidad
    int horaConsulta = 10; // 10 AM
    cout << "El profesor esta disponible a las " << horaConsulta << ":00? " 
         << (profe1.estaDisponible(horaConsulta) ? "SI" : "NO") << endl;
    
    horaConsulta = 19; // 7 PM
    cout << "El profesor esta disponible a las " << horaConsulta << ":00? " 
         << (profe1.estaDisponible(horaConsulta) ? "SI" : "NO") << endl << endl;

    // 3. Crear Personal
    Personal admin1("Maria Lopez", 30, "123456789", "Tecnico de Soporte", "Sistemas", 1500);
    admin1.mostrarInfo();
    admin1.calcularSalarioConBono();

    return 0;
}
