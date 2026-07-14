#ifndef MEDICO_H
#define MEDICO_H

#include "RecursoHumano.h"

class Medico : public RecursoHumano {
public:
    Medico(int id, const string &nombre, const string &especialidad);
    ~Medico() override;

    void ejecutarAccion() const override;
    void mostrarInfo() const override;
};

#endif
