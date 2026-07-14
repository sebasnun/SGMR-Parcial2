#ifndef RESCATISTA_H
#define RESCATISTA_H

#include "RecursoHumano.h"

class Rescatista : public RecursoHumano {
public:
    Rescatista(int id, const string &nombre, const string &especialidad);
    ~Rescatista() override;

    void ejecutarAccion() const override;
    void mostrarInfo() const override;
};

#endif
