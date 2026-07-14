#ifndef RECURSO_H
#define RECURSO_H

#include <string>
using namespace std;

/*
    Clase base abstracta que representa cualquier recurso del sistema
    (vehicular o humano). Define la interfaz común que se usara de forma
    polimorfica desde la clase Mision.
*/
class Recurso {
protected:
    int id;
    string nombre;

public:
    Recurso(int id, const string &nombre);
    virtual ~Recurso(); // destructor virtual: obligatorio para jerarquias polimorficas 

    // Metodo virtual puro: cada recurso concreto define su propia accion
    virtual void ejecutarAccion() const = 0;

    // Metodo virtual con implementacion por defecto, las subclases lo extienden
    virtual void mostrarInfo() const;

    int getId() const;
    string getNombre() const;
};

#endif
