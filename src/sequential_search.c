#include "header.h"

/**
 * @brief Convierte una cadena a minúsculas.
 * @param str Cadena de entrada.
 * @param lower_str Cadena de salida en minúsculas.
 */
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

/**
 * @brief Imprime los detalles de un producto.
 * @param producto Producto a imprimir.
 */
void print_product(const Producto *producto)
{
    printf("Producto encontrado: ID=%d, Nombre=%s, Categoría=%s, Precio=%.2f, Stock=%d\n",
           producto->id, producto->nombre, producto->categoria, producto->precio, producto->stock);
}

/**
 * @brief Búsqueda secuencial genérica basada en un criterio.
 * @param productos Arreglo de productos.
 * @param cantidad Número de productos.
 * @param criterio Función criterio para comparar.
 * @param clave Clave de búsqueda.
 * @return Índice del producto encontrado o -1 si no se encuentra.
 */
int secuencial_search(Producto productos[], int cantidad, int (*criterio)(Producto, void *), void *clave)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (criterio(productos[i], clave) == 0)
        {
            return i; // Producto encontrado
        }
    }
    return -1; // Producto no encontrado
}

/**
 * @brief Búsqueda secuencial por ID.
 * @param productos Arreglo de productos.
 * @param cantidad Número de productos.
 * @param id ID a buscar.
 * @return Índice del producto encontrado o -1 si no se encuentra.
 */
int secuencial_search_by_id(Producto productos[], int cantidad, int id)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (productos[i].id == id)
        {
            return i; // Salir después de encontrar el producto
        }
    }
    printf("Producto no encontrado.\n");
    return -1;
}

/**
 * @brief Búsqueda secuencial por nombre.
 * @param productos Arreglo de productos.
 * @param cantidad Número de productos.
 * @param nombre Nombre a buscar.
 * @return 1 si se encuentra al menos un producto, 0 en caso contrario.
 */
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
            print_product(&productos[i]);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        //printf("Producto no encontrado.\n");
    }
    return encontrado;
}

/**
 * @brief Búsqueda secuencial por categoría.
 * @param productos Arreglo de productos.
 * @param cantidad Número de productos.
 * @param categoria Categoría a buscar.
 * @return 1 si se encuentra al menos un producto, 0 en caso contrario.
 */
int secuencial_search_by_categoria(Producto productos[], int cantidad, const char *categoria)
{
    int encontrado = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (strcmp(productos[i].categoria, categoria) == 0)
        {
            print_product(&productos[i]);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        //printf("Producto no encontrado.\n");
    }
    return encontrado;
}

/**
 * @brief Búsqueda secuencial por precio.
 * @param productos Arreglo de productos.
 * @param cantidad Número de productos.
 * @param precio Precio a buscar.
 * @return 1 si se encuentra al menos un producto, 0 en caso contrario.
 */
int secuencial_search_by_precio(Producto productos[], int cantidad, float precio)
{
    int encontrado = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (productos[i].precio == precio)
        {
            print_product(&productos[i]);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        //printf("Producto no encontrado.\n");
    }
    return encontrado;
}

/**
 * @brief Búsqueda secuencial por stock.
 * @param productos Arreglo de productos.
 * @param cantidad Número de productos.
 * @param stock Stock a buscar.
 * @return 1 si se encuentra al menos un producto, 0 en caso contrario.
 */
int secuencial_search_by_stock(Producto productos[], int cantidad, int stock)
{
    int encontrado = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (productos[i].stock == stock)
        {
            print_product(&productos[i]);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        //printf("Producto no encontrado.\n");
    }
    return encontrado;
}