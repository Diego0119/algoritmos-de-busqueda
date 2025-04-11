#include "header.h"

void take_time(void (*func)(int *, int), int *arr, int n, const char *nombre_archivo)
{
    clock_t inicio, fin;
    double tiempo_usado;

    FILE *archivo = fopen(nombre_archivo, "a");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }

    // medimos tiempos para diferentes tamaños de arreglo (n, 2n, 4n,
    for (int i = 0; i < 10; i++)
    {
        int nuevo_tamano = n * pow(2, i); // tamaños: n, 2n, 4n, 8n
        int *nuevo_arr = (int *)malloc(nuevo_tamano * sizeof(int));

        if (nuevo_arr == NULL)
        {
            printf("Error de asignación de memoria\n");
            fclose(archivo);
            return;
        }

        for (int j = 0; j < nuevo_tamano; j++)
        {
            nuevo_arr[j] = arr[j % n];
        }

        inicio = clock();
        func(nuevo_arr, nuevo_tamano);
        fin = clock();

        tiempo_usado = ((double)(fin - inicio)) / CLOCKS_PER_SEC;

        fprintf(archivo, "%d %f\n", nuevo_tamano, tiempo_usado);

        free(nuevo_arr);
    }

    fclose(archivo);
}