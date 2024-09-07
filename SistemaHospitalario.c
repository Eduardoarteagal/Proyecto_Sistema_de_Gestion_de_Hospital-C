#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para pacientes
typedef struct Paciente {
    int id;
    char nombre[50];
    int edad;
    char genero[10];
    char enfermedad[100];
    struct Paciente *siguiente;
} Paciente;

// Estructura para doctores
typedef struct Doctor {
    int id;
    char nombre[50];
    char especialidad[50];
    struct Doctor *siguiente;
} Doctor;

// Estructura para citas
typedef struct Cita {
    int idCita;
    int idPaciente;
    int idDoctor;
    char fecha[20];
    struct Cita *siguiente;
} Cita;

Paciente *listaPacientes = NULL;
Doctor *listaDoctores = NULL;
Cita *listaCitas = NULL;

void agregarPaciente() {
    Paciente *nuevoPaciente = (Paciente *)malloc(sizeof(Paciente));

    printf("ID del Paciente: ");
    scanf("%d", &nuevoPaciente->id);
    printf("Nombre del Paciente: ");
    scanf("%s", nuevoPaciente->nombre);
    printf("Edad del Paciente: ");
    scanf("%d", &nuevoPaciente->edad);
    printf("Genero del Paciente: ");
    scanf("%s", nuevoPaciente->genero);
    printf("Enfermedad del Paciente: ");
    scanf("%s", nuevoPaciente->enfermedad);

    nuevoPaciente->siguiente = listaPacientes;
    listaPacientes = nuevoPaciente;  // Añadir al inicio de la lista
}

void agregarDoctor() {
    Doctor *nuevoDoctor = (Doctor *)malloc(sizeof(Doctor));

    printf("ID del Doctor: ");
    scanf("%d", &nuevoDoctor->id);
    printf("Nombre del Doctor: ");
    scanf("%s", nuevoDoctor->nombre);
    printf("Especialidad del Doctor: ");
    scanf("%s", nuevoDoctor->especialidad);

    nuevoDoctor->siguiente = listaDoctores;
    listaDoctores = nuevoDoctor;  // Añadir al inicio de la lista
}

void programarCita() {
    Cita *nuevaCita = (Cita *)malloc(sizeof(Cita));

    printf("ID de la Cita: ");
    scanf("%d", &nuevaCita->idCita);
    printf("ID del Paciente: ");
    scanf("%d", &nuevaCita->idPaciente);
    printf("ID del Doctor: ");
    scanf("%d", &nuevaCita->idDoctor);
    printf("Fecha de la Cita (DD/MM/AAAA): ");
    scanf("%s", nuevaCita->fecha);

    nuevaCita->siguiente = listaCitas;
    listaCitas = nuevaCita;  // Añadir al inicio de la lista
}

void mostrarPacientes() {
    Paciente *temp = listaPacientes;
    if (temp == NULL) {
        printf("No hay pacientes registrados.\n");
        return;
    }

    while (temp != NULL) {
        printf("ID: %d, Nombre: %s, Edad: %d, Genero: %s, Enfermedad: %s\n",
               temp->id, temp->nombre, temp->edad, temp->genero, temp->enfermedad);
        temp = temp->siguiente;
    }
}

void mostrarDoctores() {
    Doctor *temp = listaDoctores;
    if (temp == NULL) {
        printf("No hay doctores registrados.\n");
        return;
    }

    while (temp != NULL) {
        printf("ID: %d, Nombre: %s, Especialidad: %s\n", temp->id, temp->nombre, temp->especialidad);
        temp = temp->siguiente;
    }
}

void mostrarCitas() {
    Cita *temp = listaCitas;
    if (temp == NULL) {
        printf("No hay citas programadas.\n");
        return;
    }

    while (temp != NULL) {
        printf("ID Cita: %d, ID Paciente: %d, ID Doctor: %d, Fecha: %s\n",
               temp->idCita, temp->idPaciente, temp->idDoctor, temp->fecha);
        temp = temp->siguiente;
    }
}

void eliminarPaciente(int id) {
    Paciente *temp = listaPacientes, *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        printf("Paciente no encontrado.\n");
        return;
    }

    if (prev == NULL) {
        listaPacientes = temp->siguiente;  
    } else {
        prev->siguiente = temp->siguiente;
    }

    free(temp);
    printf("Paciente eliminado correctamente.\n");
}

void eliminarDoctor(int id) {
    Doctor *temp = listaDoctores, *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        printf("Doctor no encontrado.\n");
        return;
    }

    if (prev == NULL) {
        listaDoctores = temp->siguiente;
    } else {
        prev->siguiente = temp->siguiente;
    }

    free(temp);
    printf("Doctor eliminado correctamente.\n");
}

void eliminarCita(int id) {
    Cita *temp = listaCitas, *prev = NULL;

    while (temp != NULL && temp->idCita != id) {
        prev = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        printf("Cita no encontrada.\n");
        return;
    }

    if (prev == NULL) {
        listaCitas = temp->siguiente;
    } else {
        prev->siguiente = temp->siguiente;
    }

    free(temp);
    printf("Cita eliminada correctamente.\n");
}

int main() {
    int opcion, id;

    do {
        printf("\n--- Sistema de Gestion Hospitalaria ---\n");
        printf("1. Agregar Paciente\n");
        printf("2. Agregar Doctor\n");
        printf("3. Programar Cita\n");
        printf("4. Ver Pacientes\n");
        printf("5. Ver Doctores\n");
        printf("6. Ver Citas\n");
        printf("7. Eliminar Paciente\n");
        printf("8. Eliminar Doctor\n");
        printf("9. Eliminar Cita\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarPaciente();
                break;
            case 2:
                agregarDoctor();
                break;
            case 3:
                programarCita();
                break;
            case 4:
                mostrarPacientes();
                break;
            case 5:
                mostrarDoctores();
                break;
            case 6:
                mostrarCitas();
                break;
            case 7:
                printf("ID del Paciente a eliminar: ");
                scanf("%d", &id);
                eliminarPaciente(id);
                break;
            case 8:
                printf("ID del Doctor a eliminar: ");
                scanf("%d", &id);
                eliminarDoctor(id);
                break;
            case 9:
                printf("ID de la Cita a eliminar: ");
                scanf("%d", &id);
                eliminarCita(id);
                break;
            case 0:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion invalida, por favor intente nuevamente.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}

