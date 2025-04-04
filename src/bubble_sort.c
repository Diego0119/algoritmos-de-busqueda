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

void bubble_sort_op(Producto producto[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (producto[j].id > producto[j + 1].id)
            {
                swap(&producto[j], &producto[j + 1]); // se intercambia toda la estructura, no solo el id
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}
