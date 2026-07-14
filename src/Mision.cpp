#include "../include/Mision.h"
#include <iostream>
using namespace std;

Mision::Mision(int id, const string &nombre, const string &zona, int capacidadInicial) {
    this->id = id;
    this->nombre = nombre;
    this->zona = zona;
    this->capacidad = capacidadInicial;
    this->cantidad = 0;
    this->recursosAsignados = new Recurso *[capacidad]; // arreglo en el Heap
}

Mision::~Mision() {
    // Solo se libera el arreglo de punteros, NO los objetos Recurso
    // (esos son propiedad del Controlador y se liberan alli).
    delete[] recursosAsignados;
}

void Mision::redimensionar() {
    int nuevaCapacidad = capacidad * 2;
    Recurso **nuevoArreglo = new Recurso *[nuevaCapacidad];
    for (int i = 0; i < cantidad; i++) {
        nuevoArreglo[i] = recursosAsignados[i];
    }
    delete[] recursosAsignados;
    recursosAsignados = nuevoArreglo;
    capacidad = nuevaCapacidad;
}

bool Mision::asignarRecurso(Recurso *r) {
    if (r == nullptr) return false;
    if (cantidad >= capacidad) {
        redimensionar();
    }
    recursosAsignados[cantidad] = r;
    cantidad++;
    return true;
}

void Mision::ejecutarMision() const {
    cout << "\n=== Ejecutando mision: " << nombre << " (Zona: " << zona << ") ===" << endl;
    if (cantidad == 0) {
        cout << "  Esta mision no tiene recursos asignados." << endl;
        return;
    }
    for (int i = 0; i < cantidad; i++) {
        // Llamada polimorfica: cada recurso concreto ejecuta su propia accion
        recursosAsignados[i]->ejecutarAccion();
    }
}

void Mision::mostrarInfo() const {
    cout << "Mision [ID: " << id << "] " << nombre << " | Zona: " << zona
         << " | Recursos asignados: " << cantidad << endl;
}

int Mision::getId() const {
    return id;
}

string Mision::getNombre() const {
    return nombre;
}

int Mision::getCantidad() const {
    return cantidad;
}
