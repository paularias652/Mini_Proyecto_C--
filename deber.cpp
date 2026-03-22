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


//Elaboracion de las funciones


void mostrarMenu() {
    cout << "\n=====================================\n";
    cout << "   SISTEMA DE REGISTRO DE NOTAS\n";
    cout << "=====================================\n";
    cout << "1. Registrar estudiante\n";
    cout << "2. Mostrar estudiantes\n";
    cout << "3. Calcular promedios\n";
    cout << "4. Mostrar resumen general\n";
    cout << "5. Buscar estudiante por nombre\n";
    cout << "0. Salir\n";
    cout << "=====================================\n";
    cout << "Seleccione una opcion: ";
}

int leerOpcion() {
    int opcion;

    while (!(cin >> opcion)) {
        cout << "Error: ingrese un numero valido: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return opcion;
}

string leerNombre() {
    string nombre;

    do {
        cout << "Ingrese el nombre del estudiante: ";
        getline(cin, nombre);

        if (nombre.empty()) {
            cout << "Error: el nombre no puede estar vacio.\n";
        }
    } while (nombre.empty());

    return nombre;
}

float leerNota(int numeroNota) {
    float nota;

    do {
        cout << "Ingrese la nota " << numeroNota << " (0 a 10): ";
        while (!(cin >> nota)) {
            cout << "Error: ingrese un numero valido: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (nota < 0 || nota > 10) {
            cout << "Error: la nota debe estar entre 0 y 10.\n";
        }

    } while (nota < 0 || nota > 10);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return nota;
}

void registrarEstudiante() {
    if (cantidadEstudiantes >= MAX_ESTUDIANTES) {
        cout << "\nNo se pueden registrar mas estudiantes. Limite alcanzado.\n";
        pausar();
        return;
    }

    cout << "\n----- REGISTRO DE ESTUDIANTE -----\n";

    nombres[cantidadEstudiantes] = leerNombre();

    for (int i = 0; i < MAX_NOTAS; i++) {
        notas[cantidadEstudiantes][i] = leerNota(i + 1);
    }

    promedios[cantidadEstudiantes] = 0;
    registroActivo[cantidadEstudiantes] = true;
    cantidadEstudiantes++;

    cout << "\nEstudiante registrado correctamente.\n";
    pausar();
}

void mostrarEstudiantes() {
    if (cantidadEstudiantes == 0) {
        cout << "\nNo hay estudiantes registrados.\n";
        pausar();
        return;
    }

    cout << "\n----------- LISTA DE ESTUDIANTES -----------\n";

    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (registroActivo[i]) {
            cout << "\nEstudiante #" << i + 1 << endl;
            cout << "Nombre: " << nombres[i] << endl;
            cout << "Nota 1: " << notas[i][0] << endl;
            cout << "Nota 2: " << notas[i][1] << endl;
            cout << "Nota 3: " << notas[i][2] << endl;
            cout << "Promedio: " << promedios[i] << endl;
            cout << "Estado: " << clasificarPromedio(promedios[i]) << endl;
        }
    }

    pausar();
}

void calcularPromedios() {
    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (registroActivo[i]) {
            float suma = 0;
            for (int j = 0; j < MAX_NOTAS; j++) {
                suma += notas[i][j];
            }
            promedios[i] = suma / MAX_NOTAS;
        }
    }
}

void mostrarResumenGeneral() {
    if (cantidadEstudiantes == 0) {
        cout << "\nNo hay estudiantes registrados.\n";
        pausar();
        return;
    }

    calcularPromedios();

    float mayorPromedio = promedios[0];
    float menorPromedio = promedios[0];
    float sumaGeneral = 0;
    int aprobados = 0;
    int reprobados = 0;
    int posicionMayor = 0;
    int posicionMenor = 0;

    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (registroActivo[i]) {
            sumaGeneral += promedios[i];

            if (promedios[i] > mayorPromedio) {
                mayorPromedio = promedios[i];
                posicionMayor = i;
            }

            if (promedios[i] < menorPromedio) {
                menorPromedio = promedios[i];
                posicionMenor = i;
            }

            if (promedios[i] >= 7) {
                aprobados++;
            } else {
                reprobados++;
            }
        }
    }

    float promedioGeneral = sumaGeneral / cantidadEstudiantes;

    cout << "\n----------- RESUMEN GENERAL -----------\n";
    cout << "Cantidad de estudiantes: " << cantidadEstudiantes << endl;
    cout << "Promedio general del curso: " << promedioGeneral << endl;
    cout << "Mayor promedio: " << mayorPromedio << " - " << nombres[posicionMayor] << endl;
    cout << "Menor promedio: " << menorPromedio << " - " << nombres[posicionMenor] << endl;
    cout << "Aprobados: " << aprobados << endl;
    cout << "Reprobados: " << reprobados << endl;

    pausar();
}

void buscarEstudiante() {
    if (cantidadEstudiantes == 0) {
        cout << "\nNo hay estudiantes registrados.\n";
        pausar();
        return;
    }

    string buscado;
    bool encontrado = false;

    cout << "\nIngrese el nombre del estudiante a buscar: ";
    getline(cin, buscado);

    if (buscado.empty()) {
        cout << "Error: no ingreso ningun nombre.\n";
        pausar();
        return;
    }

    calcularPromedios();

    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (registroActivo[i] && nombres[i] == buscado) {
            cout << "\nEstudiante encontrado:\n";
            cout << "Nombre: " << nombres[i] << endl;
            cout << "Nota 1: " << notas[i][0] << endl;
            cout << "Nota 2: " << notas[i][1] << endl;
            cout << "Nota 3: " << notas[i][2] << endl;
            cout << "Promedio: " << promedios[i] << endl;
            cout << "Estado: " << clasificarPromedio(promedios[i]) << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\nNo se encontro un estudiante con ese nombre.\n";
    }

    pausar();
}

// Mejora creativa: clasificacion segun promedio
string clasificarPromedio(float promedio) {
    if (promedio >= 9) {
        return "Excelente";
    } else if (promedio >= 7) {
        return "Aprobado";
    } else {
        return "Reprobado";
    }
}

void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.get();
}