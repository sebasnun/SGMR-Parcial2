#include "../include/Helicoptero.h"
#include <iostream>
using namespace std;

Helicoptero::Helicoptero(int id, const string &nombre, const string &placa, int capacidad)
    : RecursoVehicular(id, nombre, placa, capacidad) {
}

Helicoptero::~Helicoptero() {
}

void Helicoptero::ejecutarAccion() const {
    cout << "  >> Helicoptero [" << nombre << "]: Realizando extraccion aerea." << endl;
}

void Helicoptero::mostrarInfo() const {
    cout << "  [HELICOPTERO] ";
    RecursoVehicular::mostrarInfo();
    cout << endl;
}

