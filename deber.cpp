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