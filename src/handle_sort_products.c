#include "header.h"

void handle_sort_products(Producto productos[], int cantidad) 
{
    int option, sort_option;

    printf("Selecciona el algoritmo de ordenación:\n");
    printf("1. Insertion Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Selection Sort\n");
    printf("Opción: ");
    if (scanf("%d", &option) != 1) 
    {
        fprintf(stderr, "Error: Entrada inválida.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Selecciona el criterio de ordenación:\n");
    printf("1. Ordenar por ID\n");
    printf("2. Ordenar por Nombre\n");
    printf("3. Ordenar por Precio\n");
    printf("4. Ordenar por Stock\n");
    printf("Opción: ");
    if (scanf("%d", &sort_option) != 1) 
    {
        fprintf(stderr, "Error: Entrada inválida.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Datos antes de ordenar: \n");
    display_csv_as_table("data.csv");

    switch (option) 
    {
        case 1:
            switch (sort_option) 
            {
                case 1: insertion_sort_by_id(productos, cantidad); break;
                case 2: insertion_sort_by_name(productos, cantidad); break;
                case 3: insertion_sort_by_price(productos, cantidad); break;
                case 4: insertion_sort_by_stock(productos, cantidad); break;
                default: printf("Opción no válida.\n"); return;
            }
            break;
        case 2:
            switch (sort_option) 
            {
                case 1: bubble_sort_by_id(productos, cantidad); break;
                case 2: bubble_sort_by_name(productos, cantidad); break;
                case 3: bubble_sort_by_price(productos, cantidad); break;
                case 4: bubble_sort_by_stock(productos, cantidad); break;
                default: printf("Opción no válida.\n"); return;
            }
            break;
        case 3:
            switch (sort_option) 
            {
                case 1: selection_sort_by_id(productos, cantidad); break;
                case 2: selection_sort_by_name(productos, cantidad); break;
                case 3: selection_sort_by_price(productos, cantidad); break;
                case 4: selection_sort_by_stock(productos, cantidad); break;
                default: printf("Opción no válida.\n"); return;
            }
            break;
        default:
            printf("Opción no válida.\n");
            return;
    }

    save_products("data.csv", productos, cantidad);
    printf("Productos ordenados.\n");
    display_csv_as_table("data.csv");
}
