#include "header.h"

/**
 * @brief Realiza una búsqueda binaria iterativa en un arreglo de enteros.
 * 
 * @param arr Arreglo de enteros ordenado.
 * @param n Tamaño del arreglo.
 * @param target Elemento a buscar.
 * @return int Índice del elemento encontrado o -1 si no se encuentra.
 */

int iterative_binary_search(int arr[], int n, int target)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Calcula el índice medio.

        if (arr[mid] == target)     // Elemento encontrado.
            return mid;

        if (arr[mid] < target) // Busca en la mitad derecha
            left = mid + 1;
        else // Busca en la mitad izquierda
            right = mid - 1;
    }

    return -1;
}
/**
 * @brief Realiza una búsqueda binaria recursiva para encontrar un producto por su ID.
 * 
 * @param productos Arreglo de estructuras Producto ordenado por ID.
 * @param left Índice inicial del rango de búsqueda.
 * @param right Índice final del rango de búsqueda.
 * @param target ID del producto a buscar.
 * @return int Índice del producto encontrado o -1 si no se encuentra.
 */

int recursive_binary_search_by_id(Producto productos[], int left, int right, int target)
{
    if (left > right) // Caso base: no encontrado.
        return -1;

    int mid = left + (right - left) / 2; // Calcula el índice medio.

    if (productos[mid].id == target) // Producto encontrado.
        return mid;

    if (productos[mid].id > target) // Busca en la mitad izquierda
        return recursive_binary_search_by_id(productos, left, mid - 1, target);

    return recursive_binary_search_by_id(productos, mid + 1, right, target);
}

/**
 * @brief Realiza una búsqueda binaria recursiva para encontrar un producto por su nombre.
 * 
 * @param productos Arreglo de estructuras Producto ordenado por nombre.
 * @param left Índice inicial del rango de búsqueda.
 * @param right Índice final del rango de búsqueda.
 * @param target Nombre del producto a buscar.
 * @return int Índice del producto encontrado o -1 si no se encuentra.
 */

int recursive_binary_search_by_name(Producto productos[], int left, int right, char *target)
{
    if (left > right) // Caso base: no encontrado.
        return -1;

    int mid = left + (right - left) / 2; // Calcula el índice medio.

    int comparison = strcasecmp(productos[mid].nombre, target); // Compara el nombre del producto en el medio con el objetivo.

    if (comparison == 0) // Producto encontrado.
        return mid;

    if (comparison > 0) // Busca en la mitad izquierda
        return recursive_binary_search_by_name(productos, left, mid - 1, target); 

    return recursive_binary_search_by_name(productos, mid + 1, right, target); // Busca en la mitad derecha
}

void binary_search_by_categoria(Producto productos[], int cantidad, const char *categoria)
{
    int left = 0, right = cantidad - 1; // Inicializa los límites de búsqueda.
    int encontrado = 0;

    while (left <= right) // Mientras haya elementos en el rango de búsqueda
    {
        int mid = left + (right - left) / 2; // Calcula el índice medio.

        int cmp = strcmp(productos[mid].categoria, categoria); // Compara la categoría del producto en el medio con la categoría objetivo.
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
        else if (cmp < 0) // Busca en la mitad derecha
        {
            left = mid + 1; 
        }
        else // Busca en la mitad izquierda
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
    int left = 0, right = cantidad - 1; // Inicializa los límites de búsqueda.
    int encontrado = 0;

    while (left <= right) // Mientras haya elementos en el rango de búsqueda
    {
        int mid = left + (right - left) / 2; // Calcula el índice medio.

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
        else if (productos[mid].precio < precio) // Busca en la mitad derecha
        {
            left = mid + 1; 
        }
        else
        {
            right = mid - 1;    // Busca en la mitad izquierda
        }
    }

    if (!encontrado)
    {
        printf("No se encontraron productos con el precio %.2f.\n", precio);
    }
}

void binary_search_by_stock(Producto productos[], int cantidad, int stock)
{
    int left = 0, right = cantidad - 1; // Inicializa los límites de búsqueda.
    int encontrado = 0;

    while (left <= right) // Mientras haya elementos en el rango de búsqueda
    {
        int mid = left + (right - left) / 2; // Calcula el índice medio.

        if (productos[mid].stock == stock) // Producto encontrado.
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
        else if (productos[mid].stock < stock) // Busca en la mitad derecha
        {
            left = mid + 1;
        }
        else // Busca en la mitad izquierda
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
