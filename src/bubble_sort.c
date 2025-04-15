#include "header.h"

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap_int(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

void bubble_sort_by_id(Producto producto[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (producto[j].id > producto[j + 1].id)
            {
                swap_int(&producto[j].id, &producto[j + 1].id);
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}

void bubble_sort_by_name(Producto producto[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(producto[j].nombre, producto[j + 1].nombre) > 0)
            {
                swap(&producto[j], &producto[j + 1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}

void bubble_sort_by_price(Producto producto[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (producto[j].precio > producto[j + 1].precio)
            {
                swap(&producto[j], &producto[j + 1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}

void bubble_sort_by_stock(Producto producto[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (producto[j].stock > producto[j + 1].stock)
            {
                swap(&producto[j], &producto[j + 1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}
