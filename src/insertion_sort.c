#include "header.h"

void insertion_sort(Producto producto[], int n)
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
