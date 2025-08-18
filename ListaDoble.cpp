// ListaDoble.cpp
#include "ListaDoble.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits> // Necesario para std::numeric_limits

// Constructor: inicializa una lista vacía.
ListaDoble::ListaDoble() : cabeza(nullptr), cola(nullptr) {}

// Destructor: libera toda la memoria de los nodos para evitar fugas.
ListaDoble::~ListaDoble() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

// Carga los datos desde 'hotel.txt' al iniciar el programa.
void ListaDoble::cargarDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cout << "Advertencia: No se pudo abrir el archivo '" << nombreArchivo << "'. Se creara uno nuevo al guardar." << std::endl;
        return;
    }

    std::string nombre;
    int habitacion;
    std::string lineaHabitacion;

    // Lee línea por línea: primero el nombre, luego el número de habitación.
    while (std::getline(archivo, nombre) && std::getline(archivo, lineaHabitacion)) {
        try {
            habitacion = std::stoi(lineaHabitacion);
            agregarHuesped(nombre, habitacion);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Dato de habitacion invalido en el archivo para: " << nombre << std::endl;
        }
    }
    archivo.close();
}

// Agrega un huésped al final de la lista (orden de llegada).
void ListaDoble::agregarHuesped(const std::string& nombre, int habitacion) {
    Nodo* nuevoNodo = new Nodo(nombre, habitacion);
    if (cabeza == nullptr) { // Si la lista está vacía
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    } else { // Si la lista ya tiene nodos
        cola->siguiente = nuevoNodo;
        nuevoNodo->anterior = cola;
        cola = nuevoNodo;
    }
}

// Guarda un nuevo huésped en el archivo de texto.
void ListaDoble::guardarEnArchivo(const std::string& nombre, int habitacion, const std::string& nombreArchivo) {
    // std::ios::app (append) para añadir al final sin borrar el contenido.
    std::ofstream archivo(nombreArchivo, std::ios::app);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para guardar." << std::endl;
        return;
    }
    archivo << nombre << std::endl;
    archivo << habitacion << std::endl;
    archivo.close();
}

// Busca un huésped por su nombre. Retorna el nodo si lo encuentra, o nullptr si no.
Nodo* ListaDoble::buscarPorNombre(const std::string& nombre) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->nombreHuesped == nombre) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

// Busca un huésped por número de habitación.
Nodo* ListaDoble::buscarPorHabitacion(int habitacion) const {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->numeroHabitacion == habitacion) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

// Muestra la lista en el orden en que se agregaron los huéspedes.
void ListaDoble::mostrarPorOrdenLlegada() const {
    std::cout << "\n--- Lista de Huespedes (Orden de Llegada) ---" << std::endl;
    if (cabeza == nullptr) {
        std::cout << "La lista esta vacia." << std::endl;
        return;
    }
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << "Habitacion: " << actual->numeroHabitacion << " - Huesped: " << actual->nombreHuesped << std::endl;
        actual = actual->siguiente;
    }
    std::cout << "---------------------------------------------" << std::endl;
}

// Muestra la lista ordenada alfabéticamente por nombre de huésped.
void ListaDoble::mostrarAlfabeticamente() const {
    std::cout << "\n--- Lista de Huespedes (Orden Alfabetico) ---" << std::endl;
    if (cabeza == nullptr) {
        std::cout << "La lista esta vacia." << std::endl;
        return;
    }

    // Copiamos los datos a un vector para ordenarlos sin modificar la lista original.
    std::vector<std::pair<std::string, int>> huespedes;
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        huespedes.push_back({actual->nombreHuesped, actual->numeroHabitacion});
        actual = actual->siguiente;
    }

    // Ordenamos el vector usando una función lambda.
    std::sort(huespedes.begin(), huespedes.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    for (const auto& huesped : huespedes) {
        std::cout << "Huesped: " << huesped.first << " - Habitacion: " << huesped.second << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
}

// Muestra los ocupantes de las habitaciones contiguas a la dada.
void ListaDoble::consultarVecinos(int habitacion) const {
    std::cout << "\n--- Consulta de Vecinos para la Habitacion " << habitacion << " ---" << std::endl;
    Nodo* vecinoAnterior = buscarPorHabitacion(habitacion - 1);
    Nodo* vecinoSiguiente = buscarPorHabitacion(habitacion + 1);

    if (vecinoAnterior) {
        std::cout << "Habitacion " << habitacion - 1 << ": " << vecinoAnterior->nombreHuesped << std::endl;
    } else {
        std::cout << "La habitacion " << habitacion - 1 << " esta libre o no existe." << std::endl;
    }

    if (vecinoSiguiente) {
        std::cout << "Habitacion " << habitacion + 1 << ": " << vecinoSiguiente->nombreHuesped << std::endl;
    } else {
        std::cout << "La habitacion " << habitacion + 1 << " esta libre o no existe." << std::endl;
    }
    std::cout << "-------------------------------------------------" << std::endl;
}

// Verifica si una habitación ya tiene un huésped.
bool ListaDoble::habitacionOcupada(int habitacion) const {
    return buscarPorHabitacion(habitacion) != nullptr;
}