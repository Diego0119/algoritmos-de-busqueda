#include "header.h"

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

int secuencial_search_by_name(Producto productos[], int cantidad, char *nombre)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (strcasecmp(productos[i].nombre, nombre) == 0)
        {
            return i; 
        }
    }
    return -1; 
}