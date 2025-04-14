#include "header.h"

int iterative_binary_search(int arr[], int n, int target)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int recursive_binary_search_by_id(Producto productos[], int left, int right, int target)
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (productos[mid].id == target)
        return mid;

    if (productos[mid].id > target)
        return recursive_binary_search_by_id(productos, left, mid - 1, target);

    return recursive_binary_search_by_id(productos, mid + 1, right, target);
}

int recursive_binary_search_by_name(Producto productos[], int left, int right, char *target)
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    int comparison = strcasecmp(productos[mid].nombre, target);

    if (comparison == 0)
        return mid;

    if (comparison > 0)
        return recursive_binary_search_by_name(productos, left, mid - 1, target);

    return recursive_binary_search_by_name(productos, mid + 1, right, target);
}

void binary_search_by_categoria(Producto productos[], int cantidad, const char *categoria)
{
    int left = 0, right = cantidad - 1;
    int encontrado = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        int cmp = strcmp(productos[mid].categoria, categoria);
        if (cmp == 0)
        {

            printf("Producto encontrado: ID=%d, Nombre=%s, Categoría=%s, Precio=%.2f, Stock=%d\n",
                   productos[mid].id, productos[mid].nombre, productos[mid].categoria,
                   productos[mid].precio, productos[mid].stock);
            encontrado = 1;

            int i = mid - 1;
            while (i >= 0 && strcmp(productos[i].categoria, categoria) == 0)
            {
                printf("Producto encontrado: ID=%d, Nombre=%s, Categoría=%s, Precio=%.2f, Stock=%d\n",
                       productos[i].id, productos[i].nombre, productos[i].categoria,
                       productos[i].precio, productos[i].stock);
                i--;
            }

            i = mid + 1;
            while (i < cantidad && strcmp(productos[i].categoria, categoria) == 0)
            {
                printf("Producto encontrado: ID=%d, Nombre=%s, Categoría=%s, Precio=%.2f, Stock=%d\n",
                       productos[i].id, productos[i].nombre, productos[i].categoria,
                       productos[i].precio, productos[i].stock);
                i++;
            }
            break;
        }
        else if (cmp < 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (!encontrado)
    {
        printf("No se encontraron productos en la categoría '%s'.\n", categoria);
    }
}

void binary_search_by_precio(Producto productos[], int cantidad, float precio)
{
    int left = 0, right = cantidad - 1;
    int encontrado = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (productos[mid].precio == precio)
        {
            printf("Producto encontrado: ID=%d, Nombre=%s, Categoría=%s, Precio=%.2f, Stock=%d\n",
                   productos[mid].id, productos[mid].nombre, productos[mid].categoria,
                   productos[mid].precio, productos[mid].stock);
            encontrado = 1;

            int i = mid - 1;
            while (i >= 0 && productos[i].precio == precio)
            {
                printf("Producto encontrado: ID=%d, Nombre=%s, Categoría=%s, Precio=%.2f, Stock=%d\n",
                       productos[i].id, productos[i].nombre, productos[i].categoria,
                       productos[i].precio, productos[i].stock);
                i--;
            }

            i = mid + 1;
            while (i < cantidad && productos[i].precio == precio)
            {
                printf("Producto encontrado: ID=%d, Nombre=%s, Categoría=%s, Precio=%.2f, Stock=%d\n",
                       productos[i].id, productos[i].nombre, productos[i].categoria,
                       productos[i].precio, productos[i].stock);
                i++;
            }
            break;
        }
        else if (productos[mid].precio < precio)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (!encontrado)
    {
        printf("No se encontraron productos con el precio %.2f.\n", precio);
    }
}

void binary_search_by_stock(Producto productos[], int cantidad, int stock)
{
    int left = 0, right = cantidad - 1;
    int encontrado = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (productos[mid].stock == stock)
        {
            printf("Producto encontrado: ID=%d, Nombre=%s, Categoría=%s, Precio=%.2f, Stock=%d\n",
                   productos[mid].id, productos[mid].nombre, productos[mid].categoria,
                   productos[mid].precio, productos[mid].stock);
            encontrado = 1;

            int i = mid - 1;
            while (i >= 0 && productos[i].stock == stock)
            {
                printf("Producto encontrado: ID=%d, Nombre=%s, Categoría=%s, Precio=%.2f, Stock=%d\n",
                       productos[i].id, productos[i].nombre, productos[i].categoria,
                       productos[i].precio, productos[i].stock);
                i--;
            }

            i = mid + 1;
            while (i < cantidad && productos[i].stock == stock)
            {
                printf("Producto encontrado: ID=%d, Nombre=%s, Categoría=%s, Precio=%.2f, Stock=%d\n",
                       productos[i].id, productos[i].nombre, productos[i].categoria,
                       productos[i].precio, productos[i].stock);
                i++;
            }
            break;
        }
        else if (productos[mid].stock < stock)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (!encontrado)
    {
        printf("No se encontraron productos con el stock %d.\n", stock);
    }
}

int wrapper_binary_search(Producto productos[], int cantidad, int id)
{
    return recursive_binary_search_by_id(productos, 0, cantidad - 1, id);
}
