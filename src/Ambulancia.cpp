#include "../include/Ambulancia.h"
#include <iostream>
using namespace std;

Ambulancia::Ambulancia(int id, const string &nombre, const string &placa, int capacidad)
    : RecursoVehicular(id, nombre, placa, capacidad) {
}

Ambulancia::~Ambulancia() {
}

void Ambulancia::ejecutarAccion() const {
    cout << "  >> Ambulancia [" << nombre << "]: Transportando paciente via terrestre." << endl;
}

void Ambulancia::mostrarInfo() const {
    cout << "  [AMBULANCIA] ";
    RecursoVehicular::mostrarInfo();
    cout << endl;
}

