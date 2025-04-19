#include "header.h"

/**
 * @brief Ordena un arreglo de productos por ID utilizando el algoritmo de inserción.
 * @param producto Arreglo de productos a ordenar.
 * @param n Cantidad de productos en el arreglo.
*/

void insertion_sort_by_id(Producto producto[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Producto key = producto[i]; // se guarda la estructura del producto
        int j = i - 1;

        while (j >= 0 && producto[j].id > key.id)
        {
            producto[j + 1] = producto[j]; // se mueve la estructura completa, no solo el id
            j--;
        }
        producto[j + 1] = key; // se ordena
    }
}

void insertion_sort_by_name(Producto producto[], int n)
{
    for (int i = 1; i < n; i++) // se empieza desde el segundo elemento
    {
        Producto key = producto[i];
        int j = i - 1;

        while (j >= 0 && strcmp(producto[j].nombre, key.nombre) > 0) // se compara el nombre
        // si el nombre actual es mayor que el siguiente
        {
            producto[j + 1] = producto[j];
            j--;
        }

        producto[j + 1] = key;
    }
}

void insertion_sort_by_price(Producto producto[], int n)
{
    for (int i = 1; i < n; i++) // se empieza desde el segundo elemento
    // se empieza desde el segundo elemento
    {
        Producto key = producto[i];
        int j = i - 1;

        while (j >= 0 && producto[j].precio > key.precio) // se compara el precio
        // si el precio actual es mayor que el siguiente
        {
            producto[j + 1] = producto[j];
            j--;
        }

        producto[j + 1] = key;
    }
}

void insertion_sort_by_stock(Producto producto[], int n)
{
    for (int i = 1; i < n; i++) // se empieza desde el segundo elemento
    {
        Producto key = producto[i];
        int j = i - 1;

        while (j >= 0 && producto[j].stock > key.stock) // se compara el stock
        {
            producto[j + 1] = producto[j];
            j--;
        }

        producto[j + 1] = key;
    }
}
