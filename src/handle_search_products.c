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
        while (getchar() != '\n')
            ;
        return;
    }

    if (search_option == 1)
    {
        int sequential_option;
        printf("Seleccione el tipo de busqueda secuencial:\n");
        printf("1. Por ID\n");
        printf("2. Por Nombre\n");
        printf("Opcion: ");
        if (scanf("%d", &sequential_option) != 1)
        {
            fprintf(stderr, "Error: Entrada invalida.\n");
            while (getchar() != '\n')
                ;
            return;
        }

        if (sequential_option == 1)
        {
            int id;
            printf("Ingrese el ID del producto a buscar: ");
            if (scanf("%d", &id) != 1)
            {
                fprintf(stderr, "Error: Entrada invalida.\n");
                while (getchar() != '\n')
                    ;
                return;
            }
            int index = secuencial_search_by_id(productos, cantidad, id);
            if (index != -1)
            {
                printf("Producto encontrado: ID %d,\n Nombre: %s\n Categoria: %s\n Precio: %.2f\n", productos[index].id, productos[index].nombre, productos[index].categoria, productos[index].precio);
            }
            else
            {
                printf("Producto no encontrado.\n");
            }
        }
        else if (sequential_option == 2)
        {
            char nombre[100];
            printf("Ingrese el nombre del producto a buscar: ");
            if (scanf(" %[^\n]", nombre) != 1) {
                fprintf(stderr, "Error: Fallo al leer el nombre.\n");
                return;
            }

            int index = secuencial_search_by_name(productos, cantidad, nombre);
            if (index != -1)
            {
                printf("Producto encontrado: ID %d,\n Nombre: %s\n Categoria: %s\n Precio: %.2f\n", productos[index].id, productos[index].nombre, productos[index].categoria, productos[index].precio);
            }
            else
            {
                printf("Producto no encontrado.\n");
            }
        }
        else
        {
            printf("Opcion invalida.\n");
        }
    }
    else if (search_option == 2)
    {
        int binary_option;
        printf("Seleccione el tipo de busqueda binaria:\n");
        printf("1. Por ID\n");
        printf("2. Por Nombre\n");
        printf("Opcion: ");
        if (scanf("%d", &binary_option) != 1)
        {
            fprintf(stderr, "Error: Entrada invalida.\n");
            while (getchar() != '\n')
                ;
            return;
        }

        if (binary_option == 1)
        {
            insertion_sort_by_id(productos, cantidad);
            int id;
            printf("Ingrese el ID del producto a buscar: ");
            if (scanf("%d", &id) != 1)
            {
                fprintf(stderr, "Error: Entrada invalida.\n");
                while (getchar() != '\n')
                    ;
                return;
            }
            int index = recursive_binary_search_by_id(productos, 0, cantidad - 1, id);

            if (index != -1)
            {
                printf("Producto encontrado: %s\n", productos[index].nombre);
            }
            else
            {
                printf("Producto no encontrado.\n");
            }
        }
        else if (binary_option == 2)
        {
            insertion_sort_by_name(productos, cantidad);
            char nombre[100];
            printf("Ingrese el nombre del producto a buscar: ");
            if (scanf(" %[^\n]", nombre) != 1) {
                fprintf(stderr, "Error: Fallo al leer el nombre.\n");
                return;
            }

            int index = recursive_binary_search_by_name(productos, 0, cantidad - 1, nombre);
            if (index != -1)
            {
                printf("Producto encontrado: ID %d,\n Nombre: %s\n Categoria: %s\n Precio: %f\n", productos[index].id, productos[index].nombre, productos[index].categoria, productos[index].precio);
            }
            else
            {
                printf("Producto no encontrado.\n");
            }
        }
        else
        {
            printf("Opcion invalida.\n");
        }
    }
    else
    {
        printf("Opcion invalida.\n");
    }
}
