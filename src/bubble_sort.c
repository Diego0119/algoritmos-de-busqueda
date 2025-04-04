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

void bubble_sort_op(Producto productos[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (productos[j].id > productos[j + 1].id) // se comparan los id's, porque se ordeara por id creo
            {
                swap(&productos[j], &productos[j + 1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}
