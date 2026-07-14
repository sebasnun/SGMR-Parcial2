#include "../include/Rescatista.h"
#include <iostream>
using namespace std;

Rescatista::Rescatista(int id, const string &nombre, const string &especialidad)
    : RecursoHumano(id, nombre, especialidad) {
}

Rescatista::~Rescatista() {
}

void Rescatista::ejecutarAccion() const {
    cout << "  >> Rescatista [" << nombre << "]: Buscando sobrevivientes en escombros." << endl;
}

void Rescatista::mostrarInfo() const {
    cout << "  [RESCATISTA] ";
    RecursoHumano::mostrarInfo();
    cout << endl;
}
