#include "../include/Controlador.h"
#include "../include/Ambulancia.h"
#include "../include/Helicoptero.h"
#include "../include/Medico.h"
#include "../include/Rescatista.h"
#include <iostream>
#include <limits>
using namespace std;

Controlador::Controlador() {
    capacidadRecursos = 10;
    cantidadRecursos = 0;
    listaRecursos = new Recurso *[capacidadRecursos];

    capacidadMisiones = 5;
    cantidadMisiones = 0;
    listaMisiones = new Mision *[capacidadMisiones];

    siguienteIdRecurso = 1;
    siguienteIdMision = 1;

    cargarDatosPrueba();
}

Controlador::~Controlador() {
    // Libera cada Recurso individualmente y luego el arreglo de punteros
    for (int i = 0; i < cantidadRecursos; i++) {
        delete listaRecursos[i];
    }
    delete[] listaRecursos;

    // Libera cada Mision (su destructor solo limpia su propio arreglo interno)
    for (int i = 0; i < cantidadMisiones; i++) {
        delete listaMisiones[i];
    }
    delete[] listaMisiones;

    cout << "\n[Controlador] Memoria liberada correctamente. Hasta pronto." << endl;
}

void Controlador::redimensionarRecursos() {
    int nuevaCapacidad = capacidadRecursos * 2;
    Recurso **nuevoArreglo = new Recurso *[nuevaCapacidad];
    for (int i = 0; i < cantidadRecursos; i++) {
        nuevoArreglo[i] = listaRecursos[i];
    }
    delete[] listaRecursos;
    listaRecursos = nuevoArreglo;
    capacidadRecursos = nuevaCapacidad;
}

void Controlador::redimensionarMisiones() {
    int nuevaCapacidad = capacidadMisiones * 2;
    Mision **nuevoArreglo = new Mision *[nuevaCapacidad];
    for (int i = 0; i < cantidadMisiones; i++) {
        nuevoArreglo[i] = listaMisiones[i];
    }
    delete[] listaMisiones;
    listaMisiones = nuevoArreglo;
    capacidadMisiones = nuevaCapacidad;
}

void Controlador::cargarDatosPrueba() {
    // HU05: al menos 2 misiones, 2 ambulancias, 1 helicoptero, 2 medicos y 2 rescatistas
    if (cantidadRecursos >= capacidadRecursos - 1) redimensionarRecursos();
    listaRecursos[cantidadRecursos++] = new Ambulancia(siguienteIdRecurso++, "Ambulancia-01", "POO026", 2);
    listaRecursos[cantidadRecursos++] = new Ambulancia(siguienteIdRecurso++, "Ambulancia-02", "VAL002", 2);
    listaRecursos[cantidadRecursos++] = new Helicoptero(siguienteIdRecurso++, "HK-01", "HEL777", 4);
    listaRecursos[cantidadRecursos++] = new Medico(siguienteIdRecurso++, "Dra. Ana Gomez", "Medicina de emergencias");
    listaRecursos[cantidadRecursos++] = new Medico(siguienteIdRecurso++, "Dr. Luis Rios", "Trauma");
    listaRecursos[cantidadRecursos++] = new Rescatista(siguienteIdRecurso++, "Carlos Perez", "Busqueda y rescate");
    listaRecursos[cantidadRecursos++] = new Rescatista(siguienteIdRecurso++, "Marta Diaz", "Rescate en alturas");

    listaMisiones[cantidadMisiones++] = new Mision(siguienteIdMision++, "Deslizamiento Siloe", "Comuna 20 - Cali");
    listaMisiones[cantidadMisiones++] = new Mision(siguienteIdMision++, "Inundacion Rio Cauca", "Jamundi");

    cout << "[Controlador] Datos de prueba cargados: " << cantidadRecursos
         << " recursos y " << cantidadMisiones << " misiones." << endl;
}

Mision* Controlador::buscarMisionPorId(int id) const {
    for (int i = 0; i < cantidadMisiones; i++) {
        if (listaMisiones[i]->getId() == id) return listaMisiones[i];
    }
    return nullptr;
}

void Controlador::verRecursos() const {
    cout << "\n--- Inventario de recursos (" << cantidadRecursos << ") ---" << endl;
    for (int i = 0; i < cantidadRecursos; i++) {
        listaRecursos[i]->mostrarInfo();
    }
    cout << "\n--- Misiones registradas (" << cantidadMisiones << ") ---" << endl;
    for (int i = 0; i < cantidadMisiones; i++) {
        listaMisiones[i]->mostrarInfo();
    }
}

void Controlador::registrarRecurso() {
    if (cantidadRecursos >= capacidadRecursos) redimensionarRecursos();

    cout << "\nTipo de recurso a registrar:\n";
    cout << " 1. Ambulancia\n 2. Helicoptero\n 3. Medico\n 4. Rescatista\n";
    cout << "Opcion: ";
    int tipo;
    cin >> tipo;

    string nombre;
    cout << "Nombre: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombre);

    Recurso *nuevo = nullptr;
    if (tipo == 1 || tipo == 2) {
        string placa;
        int capacidad;
        cout << "Placa: ";
        getline(cin, placa);
        cout << "Capacidad: ";
        cin >> capacidad;
        if (tipo == 1)
            nuevo = new Ambulancia(siguienteIdRecurso++, nombre, placa, capacidad);
        else
            nuevo = new Helicoptero(siguienteIdRecurso++, nombre, placa, capacidad);
    } else if (tipo == 3 || tipo == 4) {
        string especialidad;
        cout << "Especialidad: ";
        getline(cin, especialidad);
        if (tipo == 3)
            nuevo = new Medico(siguienteIdRecurso++, nombre, especialidad);
        else
            nuevo = new Rescatista(siguienteIdRecurso++, nombre, especialidad);
    } else {
        cout << "Opcion invalida. No se registro ningun recurso." << endl;
        return;
    }

    listaRecursos[cantidadRecursos++] = nuevo;
    cout << "Recurso registrado con exito (ID " << nuevo->getId() << ")." << endl;
}

void Controlador::crearMision() {
    if (cantidadMisiones >= capacidadMisiones) redimensionarMisiones();

    string nombre, zona;
    cout << "\nNombre de la mision: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombre);
    cout << "Zona: ";
    getline(cin, zona);

    Mision *nueva = new Mision(siguienteIdMision++, nombre, zona);
    listaMisiones[cantidadMisiones++] = nueva;
    cout << "Mision creada con exito (ID " << nueva->getId() << ")." << endl;
}

void Controlador::asignarRecursoAMision() {
    if (cantidadMisiones == 0) {
        cout << "No hay misiones creadas todavia." << endl;
        return;
    }
    if (cantidadRecursos == 0) {
        cout << "No hay recursos registrados todavia." << endl;
        return;
    }

    verRecursos();
    cout << "\nID de la mision: ";
    int idMision;
    cin >> idMision;
    Mision *m = buscarMisionPorId(idMision);
    if (m == nullptr) {
        cout << "Mision no encontrada." << endl;
        return;
    }

    cout << "ID del recurso a asignar: ";
    int idRecurso;
    cin >> idRecurso;

    Recurso *r = nullptr;
    for (int i = 0; i < cantidadRecursos; i++) {
        if (listaRecursos[i]->getId() == idRecurso) {
            r = listaRecursos[i];
            break;
        }
    }
    if (r == nullptr) {
        cout << "Recurso no encontrado." << endl;
        return;
    }

    m->asignarRecurso(r); // se pasa por puntero, sin clonar el objeto
    cout << "Recurso '" << r->getNombre() << "' asignado a la mision '" << m->getNombre() << "'." << endl;
}

void Controlador::ejecutarMision() {
    if (cantidadMisiones == 0) {
        cout << "No hay misiones creadas todavia." << endl;
        return;
    }
    for (int i = 0; i < cantidadMisiones; i++) {
        listaMisiones[i]->mostrarInfo();
    }
    cout << "\nID de la mision a ejecutar: ";
    int idMision;
    cin >> idMision;
    Mision *m = buscarMisionPorId(idMision);
    if (m == nullptr) {
        cout << "Mision no encontrada." << endl;
        return;
    }
    m->ejecutarMision(); // recorre sus recursos y llama ejecutarAccion() polimorficamente
}

void Controlador::iniciar() {
    int opcion = -1;
    do {
        cout << "\n=================================================\n";
        cout << " SGMR - Sistema de Gestion de Misiones de Rescate\n";
        cout << "=================================================\n";
        cout << " 1. Ver recursos y misiones\n";
        cout << " 2. Registrar recurso\n";
        cout << " 3. Crear mision\n";
        cout << " 4. Asignar recurso a mision\n";
        cout << " 5. Ejecutar mision\n";
        cout << " 6. Salir\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            // entrada no numerica: limpiar y continuar
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida." << endl;
            continue;
        }

        switch (opcion) {
            case 1: verRecursos(); break;
            case 2: registrarRecurso(); break;
            case 3: crearMision(); break;
            case 4: asignarRecursoAMision(); break;
            case 5: ejecutarMision(); break;
            case 6: cout << "\nCerrando el sistema..." << endl; break;
            default: cout << "Opcion invalida, intente de nuevo." << endl;
        }
    } while (opcion != 6);
}
