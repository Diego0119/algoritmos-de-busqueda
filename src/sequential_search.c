#include "header.h"

void to_lowercase(const char *str, char *lower_str)
{
    while (*str)
    {
        *lower_str = tolower((unsigned char)*str);
        str++;
        lower_str++;
    }
    *lower_str = '\0';
}

int secuencial_search(Producto productos[], int cantidad, int (*criterio)(Producto, void *), void *clave)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (criterio(productos[i], clave) == 0)
        {
            return i;
        }
    }
    return -1;
}

int secuencial_search_by_id(Producto productos[], int cantidad, int id)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (productos[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

int secuencial_search_by_name(Producto productos[], int cantidad, const char *nombre)
{
    char nombre_buscado[100];
    to_lowercase(nombre, nombre_buscado);

    int encontrado = 0;

    for (int i = 0; i < cantidad; i++)
    {
        char nombre_producto[100];
        to_lowercase(productos[i].nombre, nombre_producto);

        if (strcmp(nombre_producto, nombre_buscado) == 0)
        {
            printf("Producto encontrado: ID=%d, Nombre=%s, Categoria=%s, Precio=%.2f, Stock=%d\n",
                   productos[i].id, productos[i].nombre, productos[i].categoria,
                   productos[i].precio, productos[i].stock);
            encontrado = 1;
        }
    }

    if (!encontrado)

    {
        printf("Producto no encontrado.\n");
    }

    return encontrado;
}

int secuencial_search_by_categoria(Producto productos[], int cantidad, const char *categoria)
{
    int encontrado = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (strcmp(productos[i].categoria, categoria) == 0)
        {
            printf("Producto encontrado: ID=%d, Nombre=%s, Categoría=%s, Precio=%.2f, Stock=%d\n",
                   productos[i].id, productos[i].nombre, productos[i].categoria,
                   productos[i].precio, productos[i].stock);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        printf("Producto no encontrado.\n");
    }

    return encontrado;
}

int secuencial_search_by_precio(Producto productos[], int cantidad, float precio)
{
    int encontrado = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (productos[i].precio == precio)
        {
            printf("Producto encontrado: ID=%d, Nombre=%s, Categoría=%s, Precio=%.2f, Stock=%d\n",
                   productos[i].id, productos[i].nombre, productos[i].categoria,
                   productos[i].precio, productos[i].stock);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        printf("Producto no encontrado.\n");
    }

    return encontrado;
}

int secuencial_search_by_stock(Producto productos[], int cantidad, int stock)
{
    int encontrado = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (productos[i].stock == stock)
        {
            printf("Producto encontrado: ID=%d, Nombre=%s, Categoría=%s, Precio=%.2f, Stock=%d\n",
                   productos[i].id, productos[i].nombre, productos[i].categoria,
                   productos[i].precio, productos[i].stock);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        // printf("Producto no encontrado.\n");
    }

    return encontrado;
}
