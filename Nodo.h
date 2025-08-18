#ifndef NODO_H
#define NODO_H

#include <string>

// La estructura del Nodo que contiene los datos del huésped y los punteros
// para la lista doblemente enlazada.
struct Nodo {
    // --- Miembros de Datos ---
    std::string nombreHuesped;
    int numeroHabitacion;
    Nodo* siguiente; // Puntero al siguiente nodo en la lista
    Nodo* anterior;  // Puntero al nodo previo en la lista

    // --- Declaración del Constructor ---
    // Solo se declara la firma. La implementación estará en el archivo .cpp.
    Nodo(std::string nombre, int habitacion);
};

#endif // NODO_H
