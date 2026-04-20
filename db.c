#include <stdio.h>

#define ESTUDIANTES 5
#define ASIGNATURAS 3

int main() {
    float notas[ESTUDIANTES][ASIGNATURAS];
    float suma_est, suma_asig;
    float max_e, min_e, max_a, min_a;
    int aprobados, reprobados;

    // 1. Entrada de datos y validación
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("\nEstudiante %d:\n", i + 1);
        for (int j = 0; j < ASIGNATURAS; j++) {
            do {
                printf("  Asignatura %d (0-10): ", j + 1);
                scanf("%f", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("  Error: Nota fuera de rango. Intente de nuevo.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }

    // 2. Resultados por Estudiante
    printf("\n--- RESULTADOS POR ESTUDIANTE ---");
    for (int i = 0; i < ESTUDIANTES; i++) {
        suma_est = 0;
        max_e = notas[i][0];
        min_e = notas[i][0];

        for (int j = 0; j < ASIGNATURAS; j++) {
            suma_est += notas[i][j];
            if (notas[i][j] > max_e) max_e = notas[i][j];
            if (notas[i][j] < min_e) min_e = notas[i][j];
        }
        printf("\nEstudiante %d -> Promedio: %.2f | Max: %.2f | Min: %.2f", 
               i + 1, suma_est / ASIGNATURAS, max_e, min_e);
    }

    // 3. Resultados por Asignatura
    printf("\n\n--- RESULTADOS POR ASIGNATURA ---");
    for (int j = 0; j < ASIGNATURAS; j++) {
        suma_asig = 0;
        aprobados = 0;
        reprobados = 0;
        max_a = notas[0][j];
        min_a = notas[0][j];

        for (int i = 0; i < ESTUDIANTES; i++) {
            suma_asig += notas[i][j];
            
            // Máximos y mínimos por asignatura
            if (notas[i][j] > max_a) max_a = notas[i][j];
            if (notas[i][j] < min_a) min_a = notas[i][j];

            // Contador de aprobados/reprobados
            if (notas[i][j] >= 6.0) aprobados++;
            else reprobados++;
        }
        
        printf("\nAsignatura %d:", j + 1);
        printf("\n  Promedio: %.2f", suma_asig / ESTUDIANTES);
        printf("\n  Nota Max: %.2f | Nota Min: %.2f", max_a, min_a);
        printf("\n  Aprobados: %d | Reprobados: %d\n", aprobados, reprobados);
    }

    return 0;
}