#ifndef AMBULANCIA_H
#define AMBULANCIA_H

#include "RecursoVehicular.h"

class Ambulancia : public RecursoVehicular {
public:
    Ambulancia(int id, const string &nombre, const string &placa, int capacidad);
    ~Ambulancia() override;

    void ejecutarAccion() const override;
    void mostrarInfo() const override;
};

#endif

