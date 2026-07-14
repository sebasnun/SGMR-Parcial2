#include "../include/Medico.h"
#include <iostream>
using namespace std;

Medico::Medico(int id, const string &nombre, const string &especialidad)
    : RecursoHumano(id, nombre, especialidad) {
}

Medico::~Medico() {
}

void Medico::ejecutarAccion() const {
    cout << "  >> Medico [" << nombre << "]: Estabilizando signos vitales." << endl;
}

void Medico::mostrarInfo() const {
    cout << "  [MEDICO] ";
    RecursoHumano::mostrarInfo();
    cout << endl;
}
