#include "header.h"

void selection_sort_by_id(Producto producto[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        
        for (int j = i + 1; j < n; j++)
        {
            if (producto[j].id < producto[min_index].id)
                min_index = j; // se actualiza el menor
        }

        if (min_index != i) //verifica que el minimo no este en el primero para no hacer niun cambio :P
        {
            swap(&producto[i], &producto[min_index]); // se intercambian las estructuras completas
        }
    }
}

void selection_sort_by_price(Producto producto[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (producto[j].precio < producto[min_index].precio)
                min_index = j;
        }

        if (min_index != i)
        {
            swap(&producto[i], &producto[min_index]);
        }
    }
}

void selection_sort_by_stock(Producto producto[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (producto[j].stock < producto[min_index].stock)
                min_index = j;
        }

        if (min_index != i)
        {
            swap(&producto[i], &producto[min_index]);
        }
    }
}

void selection_sort_by_name(Producto producto[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(producto[j].nombre, producto[min_index].nombre) < 0)
                min_index = j;
        }

        if (min_index != i)
        {
            swap(&producto[i], &producto[min_index]);
        }
    }
}