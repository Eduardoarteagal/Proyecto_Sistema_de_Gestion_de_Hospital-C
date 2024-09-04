#include <stdio.h>
#include <string.h>

// Estructura para pacientes
typedef struct {
    int id;
    char nombre[50];
    int edad;
    char genero[10];
    char enfermedad[100];
} Paciente;

// Estructura para doctores
typedef struct {
    int id;
    char nombre[50];
    char especialidad[50];
} Doctor;

// Estructura para citas
typedef struct {
    int idCita;
    int idPaciente;
    int idDoctor;
    char fecha[20];
} Cita;

void agregarPaciente(Paciente *paciente) {
    printf("ID del Paciente: ");
    scanf("%d", &paciente->id);
    printf("Nombre del Paciente: ");
    scanf("%s", paciente->nombre);
    printf("Edad del Paciente: ");
    scanf("%d", &paciente->edad);
    printf("Género del Paciente: ");
    scanf("%s", paciente->genero);
    printf("Enfermedad del Paciente: ");
    scanf("%s", paciente->enfermedad);
}

void agregarDoctor(Doctor *doctor) {
    printf("ID del Doctor: ");
    scanf("%d", &doctor->id);
    printf("Nombre del Doctor: ");
    scanf("%s", doctor->nombre);
    printf("Especialidad del Doctor: ");
    scanf("%s", doctor->especialidad);
}

void programarCita(Cita *cita) {
    printf("ID de la Cita: ");
    scanf("%d", &cita->idCita);
    printf("ID del Paciente: ");
    scanf("%d", &cita->idPaciente);
    printf("ID del Doctor: ");
    scanf("%d", &cita->idDoctor);
    printf("Fecha de la Cita (DD/MM/AAAA): ");
    scanf("%s", cita->fecha);
}

void guardarPaciente(Paciente *paciente) {
    FILE *archivo = fopen("pacientes.txt", "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    fprintf(archivo, "%d %s %d %s %s\n", paciente->id, paciente->nombre, paciente->edad, paciente->genero, paciente->enfermedad);
    fclose(archivo);
}

void cargarPacientes() {
    FILE *archivo = fopen("pacientes.txt", "r");
    if (archivo == NULL) {
        printf("No hay pacientes guardados.\n");
        return;
    }
    Paciente paciente;
    while (fscanf(archivo, "%d %s %d %s %s", &paciente.id, paciente.nombre, &paciente.edad, paciente.genero, paciente.enfermedad) != EOF) {
        printf("ID: %d, Nombre: %s, Edad: %d, Género: %s, Enfermedad: %s\n", paciente.id, paciente.nombre, paciente.edad, paciente.genero, paciente.enfermedad);
    }
    fclose(archivo);
}

int main() {
    int opcion;
    Paciente paciente;
    Doctor doctor;
    Cita cita;

    do {
        printf("\n--- Sistema de Gestión Hospitalaria ---\n");
        printf("1. Agregar Paciente\n");
        printf("2. Agregar Doctor\n");
        printf("3. Programar Cita\n");
        printf("4. Ver Pacientes\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarPaciente(&paciente);
                guardarPaciente(&paciente);
                break;
            case 2:
                agregarDoctor(&doctor);
                break;
            case 3:
                programarCita(&cita);
                break;
            case 4:
                cargarPacientes();
                break;
            case 0:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 0);

    return 0;
}
