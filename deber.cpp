/*
Mini Proyecto c++
Author: Paul Arias

Enunciado: Se ha realizado un sistema de registro de notas en consola, esta elaborado con menu, 
arreglos, funciones, validaciones, procesamiento y presentacion clara. Clasifica al estudiante 
segun su promedio.





*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_ESTUDIANTES = 30;
const int MAX_NOTAS = 3;

// Arreglos principales
string nombres[MAX_ESTUDIANTES];
float notas[MAX_ESTUDIANTES][MAX_NOTAS];
float promedios[MAX_ESTUDIANTES];
bool registroActivo[MAX_ESTUDIANTES] = {false};

int cantidadEstudiantes = 0;

//creacion de las funciones

// Prototipos
void mostrarMenu();
int leerOpcion();
string leerNombre();
float leerNota(int numeroNota);
void registrarEstudiante();
void mostrarEstudiantes();
void calcularPromedios();
void mostrarResumenGeneral();
void buscarEstudiante();
string clasificarPromedio(float promedio);
void pausar();

//creacion del menu

int main() {
    int opcion;

    do {
        mostrarMenu();
        opcion = leerOpcion();

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;
            case 2:
                mostrarEstudiantes();
                break;
            case 3:
                calcularPromedios();
                cout << "\nPromedios calculados correctamente.\n";
                pausar();
                break;
            case 4:
                mostrarResumenGeneral();
                break;
            case 5:
                buscarEstudiante();
                break;
            case 0:
                cout << "\nSaliendo del sistema...\n";
                break;
            default:
                cout << "\nOpcion invalida. Intente de nuevo.\n";
                pausar();
        }

    } while (opcion != 0);

    return 0;
}
