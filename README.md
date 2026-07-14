# SGMR — Sistema de Gestión de Misiones de Rescate

Parcial 2 — Fundamentos de Programación Orientada a Objetos — Grupo 80
Universidad del Valle

## Integrantes

* JUAN SEBASTIAN PAREDES ARROYAVE — 202535230

## Descripción

Motor lógico en C++ para el registro de personal y vehículos de rescate, creación de misiones
de emergencia y asignación polimórfica de recursos. Proyecto realizado con base al requerimiento planteado en el parcial II de POO

Compilar y ejecutar

```consola
make
./sgmr
```

O manualmente:

```consola
g++ -Wall -std=c++17 src/\\\*.cpp -o sgmr
./sgmr
```

## Estructura del proyecto

```
SGMR/
├── include/          # Headers (.h)
│   ├── Recurso.h            (clase base abstracta)
│   ├── RecursoVehicular.h   (abstracta intermedia)
│   ├── RecursoHumano.h      (abstracta intermedia)
│   ├── Ambulancia.h
│   ├── Helicoptero.h
│   ├── Medico.h
│   ├── Rescatista.h
│   ├── Mision.h
│   └── Controlador.h
├── src/               # Implementaciones (.cpp) + main.cpp
├── uml/               # Diagrama de clases (dot + png)
├── Makefile
└── README.md
```
## Diagrama de clases

Ver diagrama_clases_SGMR.png


