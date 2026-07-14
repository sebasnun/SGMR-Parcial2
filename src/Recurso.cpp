#include "../include/Recurso.h"
#include <iostream>
using namespace std;

Recurso::Recurso(int id, const string &nombre) {
    this->id = id;
    this->nombre = nombre;
}

Recurso::~Recurso() {
    // No hay memoria dinamica propia que liberar aqui, pero se declara
    // para permitir que las clases derivadas liberen la suya correctamente.
}

void Recurso::mostrarInfo() const {
    cout << "  [ID: " << id << "] Nombre: " << nombre;
}

int Recurso::getId() const {
    return id;
}

string Recurso::getNombre() const {
    return nombre;
}
