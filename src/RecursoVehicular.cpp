#include "../include/RecursoVehicular.h"
#include <iostream>
using namespace std;

RecursoVehicular::RecursoVehicular(int id, const string &nombre, const string &placa, int capacidad)
    : Recurso(id, nombre) {
    this->placa = placa;
    this->capacidad = capacidad;
}

RecursoVehicular::~RecursoVehicular() {
}

void RecursoVehicular::mostrarInfo() const {
    Recurso::mostrarInfo();
    cout << " | Placa: " << placa << " | Capacidad: " << capacidad;
}

string RecursoVehicular::getPlaca() const {
    return placa;
}

int RecursoVehicular::getCapacidad() const {
    return capacidad;
}
