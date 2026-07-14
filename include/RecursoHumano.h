#ifndef RECURSOHUMANO_H
#define RECURSOHUMANO_H

#include "Recurso.h"

/*
    Clase intermedia abstracta para recursos de tipo personal
    (Medico, Rescatista). Sigue siendo abstracta porque no
    implementa ejecutarAccion().
*/
class RecursoHumano : public Recurso {
protected:
    string especialidad;

public:
    RecursoHumano(int id, const string &nombre, const string &especialidad);
    virtual ~RecursoHumano();

    void mostrarInfo() const override;

    string getEspecialidad() const;
};

#endif
