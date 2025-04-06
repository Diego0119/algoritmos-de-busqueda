#include "header.h"

void handle_search_products(Producto productos[], int cantidad) 
{
    int search_option;

    printf("Seleccione el tipo de busqueda:\n");
    printf("1. Busqueda Secuencial\n");
    printf("2. Busqueda Binaria\n");
    printf("Opcion: ");
    if (scanf("%d", &search_option) != 1) 
    {
        fprintf(stderr, "Error: Entrada invalida.\n");
        while (getchar() != '\n');
        return;
    }

    if (search_option == 1) 
    {
        int id;
        printf("Ingrese el ID del producto a buscar: ");
        if (scanf("%d", &id) != 1) 
        {
            fprintf(stderr, "Error: Entrada invalida.\n");
            while (getchar() != '\n');
            return;
        }

        int index = secuencial_search(productos, cantidad, id);
        if (index != -1) 
        {
            printf("Producto encontrado: %s\n", productos[index].nombre);
        } 
        else 
        {
            printf("Producto no encontrado.\n");
        }
    } 
    else if (search_option == 2) 
    {
        printf("En proceso de implementacion...\n");
    }
}
