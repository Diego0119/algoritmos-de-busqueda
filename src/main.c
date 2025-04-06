#include "header.h"

int main(void)
{
    Producto productos[100];
    int cantidad = 0;
    int opcion;
    int index;

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
            case 1:
                cantidad = load_products("data.csv", productos);
                printf("%d productos cargados.\n", cantidad);
                display_csv_as_table("data.csv");
                break;

            case 2:
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
                    continue;
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
                    continue;
                }

                printf("Datos antes de ordenar: \n");
                display_csv_as_table("data.csv");

                switch (option)
                {
                case 1:
                    switch (sort_option)
                    {
                    case 1:
                        insertion_sort_by_id(productos, cantidad);
                        break;
                    case 2:
                        insertion_sort_by_name(productos, cantidad);
                        break;
                    case 3:
                        insertion_sort_by_price(productos, cantidad);
                        break;
                    case 4:
                        insertion_sort_by_stock(productos, cantidad);
                        break;
                    default:
                        printf("Opción no válida.\n");
                        continue;
                    }
                    break;

                case 2:
                    switch (sort_option)
                    {
                    case 1:
                        bubble_sort_by_id(productos, cantidad);
                        break;
                    case 2:
                        bubble_sort_by_name(productos, cantidad);
                        break;
                    case 3:
                        bubble_sort_by_price(productos, cantidad);
                        break;
                    case 4:
                        bubble_sort_by_stock(productos, cantidad);
                        break;
                    default:
                        printf("Opción no válida.\n");
                        continue;
                    }
                    break;

                case 3:
                    switch (sort_option)
                    {
                    case 1:
                        selection_sort_by_id(productos, cantidad);
                        break;
                    case 2:
                        selection_sort_by_name(productos, cantidad);
                        break;
                    case 3:
                        selection_sort_by_price(productos, cantidad);
                        break;
                    case 4:
                        selection_sort_by_stock(productos, cantidad);
                        break;
                    default:
                        printf("Opción no válida.\n");
                        continue;
                    }
                    break;

                default:
                    printf("Opción no válida.\n");
                    continue;
                }

                save_products("data.csv", productos, cantidad);
                printf("Productos ordenados.\n");
                display_csv_as_table("data.csv");
                break;
            }

            case 3:
            {
                int search_option;

                printf("Seleccione el tipo de búsqueda:\n");
                printf("1. Búsqueda Secuencial\n");
                printf("2. Búsqueda Binaria\n");
                printf("Opción: ");
                if (scanf("%d", &search_option) != 1)
                {
                    fprintf(stderr, "Error: Entrada inválida.\n");
                    while (getchar() != '\n');
                    continue;
                }

                if (search_option == 1)
                {
                    int id;
                    printf("Ingrese el ID del producto a buscar: ");
                    if (scanf("%d", &id) != 1)
                    {
                        fprintf(stderr, "Error: Entrada inválida.\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    index = secuencial_search(productos, cantidad, id);
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
                    int search_type;
                    printf("Seleccione el tipo de búsqueda:\n");
                    printf("1. Búsqueda por ID\n");
                    printf("2. Búsqueda por Nombre\n");
                    printf("3. Búsqueda por Rango de Precio\n");
                    printf("Opción: ");
                    if (scanf("%d", &search_type) != 1)
                    {
                        fprintf(stderr, "Error: Entrada inválida.\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    switch (search_type)
                    {
                    case 1:
                    {
                        int id;
                        printf("Ingrese el ID del producto a buscar: ");
                        if (scanf("%d", &id) != 1)
                        {
                            fprintf(stderr, "Error: Entrada inválida.\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        index = recursive_binary_search_by_id(productos, 0, cantidad - 1, id);
                        if (index != -1)
                        {
                            printf("Producto encontrado: %s\n", productos[index].nombre);
                        }
                        else
                        {
                            printf("Producto no encontrado.\n");
                        }
                    }
                    break;

                    case 2:
                    {
                        char nombre[50];
                        printf("Ingrese el nombre del producto a buscar: ");
                        if (scanf(" %[^\n]", nombre) != 1)
                        {
                            fprintf(stderr, "Error: Entrada inválida.\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        index = recursive_binary_search_by_name(productos, 0, cantidad - 1, nombre);
                        if (index != -1)
                        {
                            printf("Producto encontrado: %s\n", productos[index].nombre);
                        }
                        else
                        {
                            printf("Producto no encontrado.\n");
                        }
                    }
                    break;

                    case 3:
                    {
                        float min_price, max_price;
                        printf("Ingrese el precio mínimo: ");
                        if (scanf("%f", &min_price) != 1)
                        {
                            fprintf(stderr, "Error: Entrada inválida.\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        printf("Ingrese el precio máximo: ");
                        if (scanf("%f", &max_price) != 1)
                        {
                            fprintf(stderr, "Error: Entrada inválida.\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        int found = 0;
                        for (int i = 0; i < cantidad; i++)
                        {
                            if (productos[i].precio >= min_price && productos[i].precio <= max_price)
                            {
                                printf("Producto encontrado: %s\n", productos[i].nombre);
                                found = 1;
                            }
                        }

                        if (!found)
                        {
                            printf("No se encontraron productos en el rango de precios especificado.\n");
                        }
                    }
                    break;

                    default:
                        printf("Opción no válida.\n");
                        break;
                    }
                }
                break;
            }

            case 4: //stats
            printf("Seleccione la estadistica que quiera ver:\n");
            printf("1. Total de productos en inventario\n");
            printf("2. Valor total del inventario\n");
            printf("3. Producto con mayor y menor stock\n");
            printf("4. Producto más caro y más barato\n");
            printf("5. Promedio de precios por categoría\n");
            printf("6. Cantidad de productos por categoría\n");
            int stats_option;
            if (scanf("%d", &stats_option) != 1) 
            {
                fprintf(stderr, "Error: Entrada inválida.\n");
                while (getchar() != '\n'); 
                continue;
            }
            if (stats_option == 1) 
            {
                total_stock(productos, cantidad);
            }
            else if (stats_option == 2)
            {
                valor_inventario(productos, cantidad);
            }
            else if (stats_option == 3)
            {
                printf("En proceso de creacion...");
            }
            else if (stats_option == 4)
            {
                printf("En proceso de creacion...");
            }
            else if (stats_option == 5) 
            {
                printf("En proceso de creacion...");
            }
            else if (stats_option == 6) 
            {
                printf("En proceso de creacion...");
            }
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
