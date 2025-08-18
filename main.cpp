#include <iostream>
#include <limits>
#include "ListaDoble.h"

// Función que muestra el menú
void mostrarMenu() {
    std::cout << "\n===== MENU DEL HOTEL =====" << std::endl;
    std::cout << "1. Ingresar un nuevo huesped" << std::endl;
    std::cout << "2. Buscar un huesped existente" << std::endl;
    std::cout << "3. Mostrar lista por orden de llegada" << std::endl;
    std::cout << "4. Mostrar lista por orden alfabetico" << std::endl;
    std::cout << "5. Consultar vecinos de una habitacion" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Seleccione una opcion: ";
}

int main() {
    ListaDoble hotel;
    const std::string archivoDatos = "hotel.txt";
    hotel.cargarDesdeArchivo(archivoDatos);

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;

        // Evitar problemas con getline
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = -1; // Opción inválida para que vuelva a mostrar el menú
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        

        switch (opcion) {
            case 1: { // Ingresar nuevo huésped
                std::string nombre;
                int habitacion;
                std::cout << "Ingrese el nombre del nuevo huesped: ";
                std::getline(std::cin, nombre);
                std::cout << "Ingrese el numero de habitacion: ";
                std::cin >> habitacion;
                
                while(hotel.habitacionOcupada(habitacion)) {
                    std::cout << "La habitacion " << habitacion << " ya esta ocupada." << std::endl;
                    
                    bool sugerenciaAceptada = false;
                    // Sugerir habitación anterior si está libre
                    if (!hotel.habitacionOcupada(habitacion - 1) && habitacion > 1) {
                        char respuesta;
                        std::cout << "La habitacion " << habitacion - 1 << " esta libre. Desea tomarla? (s/n): ";
                        std::cin >> respuesta;
                        if (respuesta == 's' || respuesta == 'S') {
                            habitacion = habitacion - 1;
                            sugerenciaAceptada = true;
                        }
                    }

                    // Si no aceptó la anterior, sugerir la siguiente si está libre
                    if (!sugerenciaAceptada && !hotel.habitacionOcupada(habitacion + 1)) {
                         char respuesta;
                        std::cout << "La habitacion " << habitacion + 1 << " esta libre. Desea tomarla? (s/n): ";
                        std::cin >> respuesta;
                        if (respuesta == 's' || respuesta == 'S') {
                            habitacion = habitacion + 1;
                            sugerenciaAceptada = true;
                        }
                    }

                    // Si ninguna sugerencia fue aceptada o posible, pedir otro número
                    if (!sugerenciaAceptada) {
                         std::cout << "Por favor, elija un numero de habitacion diferente: ";
                         std::cin >> habitacion;
                    }
                }
                
                hotel.agregarHuesped(nombre, habitacion);
                hotel.guardarEnArchivo(nombre, habitacion, archivoDatos);
                std::cout << "Huesped '" << nombre << "' agregado en la habitacion " << habitacion << "." << std::endl;
                break;
            }
            case 2: { // Buscar huésped
                int criterio;
                std::cout << "Buscar por: \n1. Nombre\n2. Numero de Habitacion\nOpcion: ";
                std::cin >> criterio;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (criterio == 1) {
                    std::string nombre;
                    std::cout << "Ingrese el nombre a buscar: ";
                    std::getline(std::cin, nombre);
                    Nodo* huesped = hotel.buscarPorNombre(nombre);
                    if (huesped) {
                        std::cout << "Huesped encontrado: " << huesped->nombreHuesped << " esta en la habitacion " << huesped->numeroHabitacion << "." << std::endl;
                    } else {
                        std::cout << "Ese huesped no fue encontrado." << std::endl;
                    }
                } else if (criterio == 2) {
                    int habitacion;
                    std::cout << "Ingrese el numero de habitacion a buscar: ";
                    std::cin >> habitacion;
                    Nodo* huesped = hotel.buscarPorHabitacion(habitacion);
                    if (huesped) {
                         std::cout << "Habitacion encontrada: " << huesped->nombreHuesped << " se hospeda en la habitacion " << huesped->numeroHabitacion << "." << std::endl;
                    } else {
                        std::cout << "Esa habitacion esta libre o no existe." << std::endl;
                    }
                } else {
                    std::cout << "Criterio no valido." << std::endl;
                }
                break;
            }
            case 3: { // Mostrar lista por orden de llegada
                hotel.mostrarPorOrdenLlegada();
                break;
            }
            case 4: { // Mostrar lista en orden alfabético
                hotel.mostrarAlfabeticamente();
                break;
            }
            case 5: { // Consultar vecinos
                int habitacion;
                std::cout << "Ingrese el numero de habitacion para consultar sus vecinos: ";
                std::cin >> habitacion;
                hotel.consultarVecinos(habitacion);
                break;
            }
            case 0: { // Salir
                std::cout << "Saliendo del programa. ¡Hasta luego!" << std::endl;
                break;
            }
            default: {
                std::cout << "Opcion no valida. Por favor, intente de nuevo." << std::endl;
                break;
            }
        }
        std::cout << "\nPresione Enter para continuar...";
        std::cin.get();

    } while (opcion != 0);

    return 0;
}

