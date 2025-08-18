#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "Nodo.h"
#include <string>

class ListaDoble {
private:
    Nodo* cabeza; // Puntero al primer nodo de la lista -- Primer huesped
    Nodo* cola;   // Puntero al último nodo de la lista -- Último huesped

public:
    // Constructor y Destructor
    ListaDoble();
    ~ListaDoble();

    // Funciones principales
    //Permite cargar los datos desde un archivo al iniciar el programa.
    void cargarDesdeArchivo(const std::string& nombreArchivo);
    // Permite agregar un nuevo huésped al final de la lista.
    void agregarHuesped(const std::string& nombre, int habitacion);
    // Guarda un nuevo huésped en el archivo de texto.
    void guardarEnArchivo(const std::string& nombre, int habitacion, const std::string& nombreArchivo);

    // Funciones de búsqueda
    // Busca un huésped por su nombre.
    Nodo* buscarPorNombre(const std::string& nombre);
    // Busca un huésped por su número de habitación.
    Nodo* buscarPorHabitacion(int habitacion) const;

    // Funciones de visualización
    // Muestra la lista de huéspedes en orden de llegada.
    void mostrarPorOrdenLlegada() const;
    // Muestra la lista de huéspedes ordenada alfabéticamente por nombre.
    void mostrarAlfabeticamente() const;
    // Muestra los vecinos de una habitación específica.
    // Si la habitación no existe o está vacía, informa al usuario.
    void consultarVecinos(int habitacion) const;

    // Función de utilidad para verificar si una habitación está ocupada
    bool habitacionOcupada(int habitacion) const;
};

#endif // LISTADOBLE_H
