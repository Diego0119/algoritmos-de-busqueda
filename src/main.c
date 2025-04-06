#include "header.h"

int main(void) {
    Producto productos[100];
    int cantidad = 0;
    int opcion;

    while (1) 
    {
        show_menu();
        printf("Seleccione una opción: ");
        if (scanf("%d", &opcion) != 1) 
        {
            fprintf(stderr, "Error: Entrada inválida.\n");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            continue;
        }

        switch (opcion) 
        {
            case 1: handle_load_products(productos, &cantidad); break;
            case 2: handle_sort_products(productos, cantidad); break;
            case 3: handle_search_products(productos, cantidad); break;
            case 4: handle_statistics(productos, cantidad); break;
            case 5: printf("Saliendo...\n"); return 0;
            default: printf("Opción no válida.\n");
        }
    }

    return 0;

}
