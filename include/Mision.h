#ifndef MISION_H
#define MISION_H

#include <string>
#include "Recurso.h"
using namespace std;

/*
    Mision agrupa recursos heterogeneos bajo el tipo base Recurso*
    IMPORTANTE sobre memoria 
    Mision NO es dueña de los objetos Recurso; solo guarda punteros
    (referencias) a recursos creados y administrados por el Controlador.
    Por eso su destructor libera unicamente el arreglo de punteros
    (delete[]) y NUNCA los objetos Recurso apuntados, evitando doble
    liberacion (double free).
*/
class Mision {
private:
    int id;
    string nombre;
    string zona;

    Recurso **recursosAsignados; // arreglo dinamico de punteros 
    int capacidad;               // tamano actual del arreglo
    int cantidad;                // recursos realmente asignados

    void redimensionar(); // duplica la capacidad del arreglo dinamico

public:
    Mision(int id, const string &nombre, const string &zona, int capacidadInicial = 5);
    ~Mision();

    bool asignarRecurso(Recurso *r); // agrega un recurso por puntero 
    void ejecutarMision() const;     // recorre y llama ejecutarAccion() polimorficamente
    void mostrarInfo() const;

    int getId() const;
    string getNombre() const;
    int getCantidad() const;
};

#endif
