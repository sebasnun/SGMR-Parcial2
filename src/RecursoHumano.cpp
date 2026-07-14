#include "../include/RecursoHumano.h"
#include <iostream>
using namespace std;

RecursoHumano::RecursoHumano(int id, const string &nombre, const string &especialidad)
    : Recurso(id, nombre) {
    this->especialidad = especialidad;
}

RecursoHumano::~RecursoHumano() {
}

void RecursoHumano::mostrarInfo() const {
    Recurso::mostrarInfo();
    cout << " | Especialidad: " << especialidad;
}

string RecursoHumano::getEspecialidad() const {
    return especialidad;
}
