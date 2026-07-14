#ifndef HELICOPTERO_H
#define HELICOPTERO_H

#include "RecursoVehicular.h"

class Helicoptero : public RecursoVehicular {
public:
    Helicoptero(int id, const string &nombre, const string &placa, int capacidad);
    ~Helicoptero() override;

    void ejecutarAccion() const override;
    void mostrarInfo() const override;
};

#endif
