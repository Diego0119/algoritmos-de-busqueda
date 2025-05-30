#include "header.h"

/*
 @param arr Arreglo de enteros donde se realizará la búsqueda.
 @param n Tamaño del arreglo.
 @param id Valor a buscar en el arreglo.
 @return Índice del valor encontrado o -1 si no se encuentra.
*/
void take_time_producto(void (*func)(Producto *, int), Producto *arr, int n, const char *nombre_archivo)
{
    clock_t inicio, fin;
    double tiempo_usado;

    FILE *archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) // verifica si el archivo se abre correctamente
    {
        printf("Error al abrir el archivo\n");
        return;
    }

    for (int i = 0; i < 10; i++) // i = 0, 1, 2, ..., 9
    {
        int nuevo_tamano = n * pow(2, i); // tamaños: n, 2n, 4n, ..., 512n
        Producto *nuevo_arr = malloc(nuevo_tamano * sizeof(Producto));

        if (nuevo_arr == NULL) //verifica si la memoria se asigna correctamente
        {
            printf("Error de memoria\n");
            fclose(archivo);
            return;
        }

        for (int j = 0; j < nuevo_tamano; j++) // llena el nuevo arreglo con los elementos del arreglo original
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

void take_time_search(int (*search_func)(Producto[], int, int), Producto productos[], int cantidad, const char *archivo_resultado)
{
    FILE *archivo = fopen(archivo_resultado, "a");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }

    srand(time(NULL));

    for (int i = 0; i < 10; i++) // i = 0, 1, 2, ..., 9
    {
        int repeticiones = 1000 * (i + 1);
        clock_t inicio = clock();

        for (int j = 0; j < repeticiones; j++) // realiza la búsqueda 1000, 2000, ..., 10000 veces
        {
            int random_index = rand() % cantidad;
            int id = productos[random_index].id;

            search_func(productos, cantidad, id);
        }

        clock_t fin = clock();
        double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

        fprintf(archivo, "%d %f\n", repeticiones, tiempo);
    }

    fclose(archivo);
}
