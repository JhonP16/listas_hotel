# Práctica I: Gestión de Huéspedes de Hotel con Listas Dobles

## Miembros del Equipo

* Yesid Hurtado Montoya
* Pablo José Benítez
* Jhon Jairo Pulgarin Restrepo

## URL del Video de Presentación

* **Enlace al video**: https://youtu.be/gfFpdXiOkS0

## Descripción del Proyecto

Este proyecto es una implementación en C++ de un sistema de gestión de huéspedes para un hotel, utilizando una lista doblemente enlazada como estructura de datos principal. El programa permite realizar operaciones sobre los registros de huéspedes, cargando y guardando la información en un archivo de texto (`hotel.txt`).

El objetivo principal es aplicar los conceptos de manejo de estructuras de datos dinámicas.

### Funcionalidades Implementadas

#### Tendremos tres clases principales:

**Nodo** → Representa a cada huésped (nombre y número de habitación).

**ListaDoble** → Maneja toda la lista doblemente enlazada (inserción, búsqueda, impresión, etc.).

**Main** -> Menú y ejecución del código

#### Algunas funciones

* **Ingresar Nuevo Huésped**: Agrega un nuevo huésped a la lista y al archivo. Si la habitación solicitada está ocupada, el sistema sugiere habitaciones contiguas disponibles.
* **Buscar Huésped**: Permite buscar un huésped por su nombre o por el número de habitación.
* **Mostrar Listas**:
    * Muestra a todos los huéspedes en el orden en que llegaron (orden de inserción).
    * Muestra a todos los huéspedes en orden alfabético.
* **Consultar Vecinos**: Dado un número de habitación, muestra quiénes ocupan las habitaciones anterior y posterior.
* **Persistencia de Datos**: La información se carga desde `hotel.txt` al iniciar y se actualiza en el mismo archivo al agregar un nuevo huésped.

## Aclaración sobre el archivo `hotel.txt`
Este archivo está localizado en cmake-build-debug y guardará todos los datos de los huéspedes del hotel-

## Información Técnica

* **Lenguaje**: C++
* **Compilador Utilizado**: g++ (GCC) versión 11.4.0 (o la versión que hayas usado, ej. MSVC para Visual Studio).
    * Para compilar desde la terminal, puedes usar: `g++ main.cpp ListaDoble.cpp -o programa_hotel -std=c++17`
* **Estructura de Datos**: Lista Doblemente Enlazada.

