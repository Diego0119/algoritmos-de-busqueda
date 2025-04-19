#include "header.h"

/**
 * @brief Ordena un arreglo de enteros usando el algoritmo Bubble Sort.
 * 
 * @param arr Arreglo de enteros.
 * @param n Tamaño del arreglo.
 */

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) // Itera sobre el arreglo
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) // Compara elementos adyacentes
        {
            if (arr[j] > arr[j + 1]) // Si el elemento actual es mayor que el siguiente
            {
                swap_int(&arr[j], &arr[j + 1]); // Intercambia los elementos
                swapped = 1;
            }
        }
        if (!swapped) // Si no hubo intercambios, el arreglo ya está ordenado
            break;
    }
}

void bubble_sort_by_id(Producto producto[], int n)
{
    for (int i = 0; i < n - 1; i++) // Itera sobre el arreglo
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) // Compara elementos adyacentes
        { 
            if (producto[j].id > producto[j + 1].id) // Si el ID actual es mayor que el siguiente
            {
                swap_int(&producto[j].id, &producto[j + 1].id); // Intercambia los IDs
                swapped = 1;
            }
        }

        if (!swapped)   // Si no hubo intercambios, el arreglo ya está ordenado
            break;
    }
}

void bubble_sort_by_name(Producto producto[], int n)
{
    for (int i = 0; i < n - 1; i++) // Itera sobre el arreglo
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) // Compara elementos adyacentes
        {
            if (strcmp(producto[j].nombre, producto[j + 1].nombre) > 0) // Si el nombre actual es mayor que el siguiente
            {
                swap(&producto[j], &producto[j + 1]); // Intercambia los productos completos
                swapped = 1;
            }
        }

        if (!swapped) // Si no hubo intercambios, el arreglo ya está ordenado
            break;
    }
}

void bubble_sort_by_price(Producto producto[], int n)
{
    for (int i = 0; i < n - 1; i++) // Itera sobre el arreglo
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) // Compara elementos adyacentes
        {
            if (producto[j].precio > producto[j + 1].precio) // Si el precio actual es mayor que el siguiente
            {
                swap(&producto[j], &producto[j + 1]); // Intercambia los productos completos
                swapped = 1;
            }
        }

        if (!swapped)   // Si no hubo intercambios, el arreglo ya está ordenado
            break;
    }
}

void bubble_sort_by_stock(Producto producto[], int n)
{
    for (int i = 0; i < n - 1; i++) // Itera sobre el arreglo
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) // Compara elementos adyacentes
        {
            if (producto[j].stock > producto[j + 1].stock) // Si el stock actual es mayor que el siguiente
            {
                swap(&producto[j], &producto[j + 1]); // Intercambia los productos completos
                swapped = 1; 
            }
        }

        if (!swapped) // Si no hubo intercambios, el arreglo ya está ordenado
            break;
    }
}
