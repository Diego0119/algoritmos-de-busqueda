#include "header.h"

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
    for (int i = 1; i < n; i++)
    {
        Producto key = producto[i];
        int j = i - 1;

        while (j >= 0 && strcmp(producto[j].nombre, key.nombre) > 0)
        {
            producto[j + 1] = producto[j];
            j--;
        }

        producto[j + 1] = key;
    }
}

void insertion_sort_by_price(Producto producto[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Producto key = producto[i];
        int j = i - 1;

        while (j >= 0 && producto[j].precio > key.precio)
        {
            producto[j + 1] = producto[j];
            j--;
        }

        producto[j + 1] = key;
    }
}

void insertion_sort_by_stock(Producto producto[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Producto key = producto[i];
        int j = i - 1;

        while (j >= 0 && producto[j].stock > key.stock)
        {
            producto[j + 1] = producto[j];
            j--;
        }

        producto[j + 1] = key;
    }
}
