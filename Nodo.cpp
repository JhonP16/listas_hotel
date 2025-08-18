// Nodo.cpp
#include "Nodo.h" // Se incluye el archivo de cabecera para enlazar la implementación con su declaración.

// Implementación del constructor del Nodo.
Nodo::Nodo(std::string nombre, int habitacion)
    : nombreHuesped(nombre),
      numeroHabitacion(habitacion),
      siguiente(nullptr),
      anterior(nullptr) {
    // El cuerpo del constructor puede permanecer vacío, ya que toda la
    // inicialización se realiza en la lista de inicialización de arriba.
}
