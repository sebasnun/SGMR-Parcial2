#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Recurso.h"
#include "Mision.h"

/*
    Clase Controlador: unico punto de entrada de la logica del
    programa. main.cpp solo instancia un Controlador e invoca iniciar().
    Es duena de la memoria de TODOS los Recurso* y Mision* creados con
    new . Su destructor libera esa memoria.
*/
class Controlador {
private:
    // Inventario general de recursos (arreglo dinamico de punteros, sin vector)
    Recurso **listaRecursos;
    int capacidadRecursos;
    int cantidadRecursos;

    // Lista de misiones creadas
    Mision **listaMisiones;
    int capacidadMisiones;
    int cantidadMisiones;

    int siguienteIdRecurso;
    int siguienteIdMision;

    void redimensionarRecursos();
    void redimensionarMisiones();
    void cargarDatosPrueba(); //  datos quemados al iniciar

    // Helpers del menu
    void verRecursos() const;
    void registrarRecurso();
    void crearMision();
    void asignarRecursoAMision();
    void ejecutarMision();
    Mision* buscarMisionPorId(int id) const;

public:
    Controlador();
    ~Controlador();

    void iniciar(); // despliega el ciclo de menu 
};

#endif
