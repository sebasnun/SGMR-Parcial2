#ifndef RECURSOVEHICULAR_H
#define RECURSOVEHICULAR_H

#include "Recurso.h"

/*
    Clase intermedia abstracta para recursos de tipo vehiculo
    (Ambulancia, Helicoptero). Sigue siendo abstracta porque no
    implementa ejecutarAccion().
*/
class RecursoVehicular : public Recurso {
protected:
    string placa;
    int capacidad; // numero de personas que puede transportar

public:
    RecursoVehicular(int id, const string &nombre, const string &placa, int capacidad);
    virtual ~RecursoVehicular();

    void mostrarInfo() const override;

    string getPlaca() const;
    int getCapacidad() const;
};

#endif
