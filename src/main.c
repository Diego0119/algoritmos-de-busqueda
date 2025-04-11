#include "header.h"

int main(void)
{

    Producto productos[MAX_NUMBER_OF_PRODUCTS];
    int cantidad;
    printf("Ingrese la cantidad de productos a generar: \n");
    scanf("%d", &cantidad);
    int opcion;

    generate_products_csv("data.csv", cantidad);

    while (1)
    {
        show_menu();
        printf("Seleccione una opción: ");
        if (scanf("%d", &opcion) != 1)
        {
            fprintf(stderr, "Error: Entrada inválida.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (opcion)
        {
        case 1:
            handle_load_products(productos, &cantidad);
            break;
        case 2:
            handle_sort_products(productos, cantidad);
            break;
        case 3:
            handle_search_products(productos, cantidad);
            break;
        case 4:
            handle_statistics(productos, cantidad);
            break;
        case 5:
            printf("Saliendo...\n");
            return 0;
        default:
            printf("Opción no válida.\n");
        }
    }

    return 0;
}
