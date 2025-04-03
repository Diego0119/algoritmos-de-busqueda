#include "header.h"

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bubble_sort_op(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0; // bandera que permite encontrar si el arreglo estaba ordenado desde antes

        for (int j = 0; j < n - i - 1; j++) // n - i - 1 reduce el rango de busqueda, asi no recorre siempre hasta el final cuando el elemento ordenado ya subio al final
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}
