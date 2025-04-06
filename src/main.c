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
            printf("Error al leer la opción.\n");
            return 1;
        }
        switch (opcion)
        {
        case 1:
            cantidad = load_products("data.csv", productos);
            printf("%d productos cargados.\n", cantidad);
            display_csv_as_table("data.csv");
            break;
        case 2:
            printf("Selecciona el algoritmo de ordenación:\n");
            printf("1. Insertion Sort\n");
            printf("2. Bubble Sort\n");
            printf("3. Selection Sort\n");
            int option;
            scanf("%d", &option);

            printf("Selecciona el criterio de ordenación:\n");
            printf("1. Ordenar por ID\n");
            printf("2. Ordenar por Nombre\n");
            printf("3. Ordenar por Precio\n");
            printf("4. Ordenar por Stock\n");

            int sort_option;
            scanf("%d", &sort_option);

            printf("Datos antes de ordenar: \n");
            display_csv_as_table("data.csv");

            switch (option)
            {
            case 1:
                switch (sort_option)
                {
                case 1:
                    insertion_sort_by_id(productos, cantidad);
                    save_products("data.csv", productos, cantidad);
                    break;
                case 2:
                    insertion_sort_by_name(productos, cantidad);
                    save_products("data.csv", productos, cantidad);
                    break;
                case 3:
                    insertion_sort_by_price(productos, cantidad);
                    save_products("data.csv", productos, cantidad);
                    break;
                case 4:
                    insertion_sort_by_stock(productos, cantidad);
                    save_products("data.csv", productos, cantidad);
                    break;
                default:
                    printf("Opción no válida.\n");
                    break;
                }
                break;

            case 2:
                switch (sort_option)
                {
                case 1:
                    bubble_sort_by_id(productos, cantidad);
                    save_products("data.csv", productos, cantidad);
                    break;
                case 2:
                    bubble_sort_by_name(productos, cantidad);
                    save_products("data.csv", productos, cantidad);
                    break;
                case 3:
                    bubble_sort_by_price(productos, cantidad);
                    save_products("data.csv", productos, cantidad);
                    break;
                case 4:
                    bubble_sort_by_stock(productos, cantidad);
                    save_products("data.csv", productos, cantidad);
                    break;
                default:
                    printf("Opción no válida.\n");
                    break;
                }
                break;

            case 3:
                switch (sort_option)
                {
                case 1:
                    selection_sort_by_id(productos, cantidad);
                    save_products("data.csv", productos, cantidad);
                    break;
                case 2:
                    selection_sort_by_name(productos, cantidad);
                    save_products("data.csv", productos, cantidad);

                    break;
                case 3:
                    selection_sort_by_price(productos, cantidad);
                    save_products("data.csv", productos, cantidad);
                    break;
                case 4:
                    selection_sort_by_stock(productos, cantidad);
                    save_products("data.csv", productos, cantidad);

                    break;
                default:
                    printf("Opción no válida.\n");
                    break;
                }
                break;
            default:
                printf("Opción no válida.\n");
                break;
            }

            printf("Productos ordenados.\n");
            display_csv_as_table("data.csv");
            break;
        case 3:
            printf("Seleccione el tipo de búsqueda:\n");
            printf("1. Búsqueda Secuencial\n2. Búsqueda Binaria\n");
            int search_option;
            scanf("%d", &search_option);
            if (search_option == 1)
            {
                int id;
                printf("Ingrese el ID del producto a buscar: ");
                scanf("%d", &id);
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
                printf("Seleccione el tipo de búsqueda:\n");
                printf("1. Búsqueda por ID\n");
                printf("2. Búsqueda por Nombre\n");
                printf("3. Búsqueda por Rango de Precio\n");

                int search_type;
                scanf("%d", &search_type);

                switch (search_type)
                {
                case 1:
                {
                    int id;
                    printf("Ingrese el ID del producto a buscar: ");
                    scanf("%d", &id);
                    int index = recursive_binary_search_by_id(productos, 0, cantidad - 1, id);
                    if (index != -1)
                    {
                        printf("Producto encontrado:\n");
                        printf("Nombre: %s\n", productos[index].nombre);
                        printf("Categoria: %s\n", productos[index].categoria);
                        printf("Precio: %.2f\n", productos[index].precio);
                        printf("Stock: %d\n", productos[index].stock);
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
                    scanf(" %[^\n]", nombre);
                    int index = recursive_binary_search_by_name(productos, 0, cantidad - 1, nombre);
                    if (index != -1)
                    {
                        printf("Producto encontrado:\n");
                        printf("Nombre: %s\n", productos[index].nombre);
                        printf("Categoria: %s\n", productos[index].categoria);
                        printf("Precio: %.2f\n", productos[index].precio);
                        printf("Stock: %d\n", productos[index].stock);
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
                    scanf("%f", &min_price);
                    printf("Ingrese el precio máximo: ");
                    scanf("%f", &max_price);
                    int found = 0;
                    for (int i = 0; i < cantidad; i++)
                    {
                        if (productos[i].precio >= min_price && productos[i].precio <= max_price)
                        {
                            printf("Producto encontrado:\n");
                            printf("ID: %d\n", productos[i].id);
                            printf("Nombre: %s\n", productos[i].nombre);
                            printf("Categoria: %s\n", productos[i].categoria);
                            printf("Precio: %.2f\n", productos[i].precio);
                            printf("Stock: %d\n", productos[i].stock);
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
        case 4: //stats
            printf("Seleccione la estadistica que quiera ver:\n");
            printf("1. Total de productos en inventario\n");
            printf("2. Valor total del inventario\n");
            printf("3. Producto con mayor y menor stock\n");
            printf("4. Producto más caro y más barato\n");
            printf("5. Promedio de precios por categoría\n");
            printf("6. Cantidad de productos por categoría\n");
            int stats_option;
            scanf("%d", &stats_option);
            if (stats_option == 1) // total de productos
            {
                total_stock(productos, cantidad);
            }
            else if (stats_option == 2) // valor total inv.
            {
                valor_inventario(productos, cantidad);
            }
            else if (stats_option == 3) // mayor y menor stock
            {
                printf("En proceso de creacion...");
            }
            else if (stats_option == 4) // mas caro y mas barato
            {
                printf("En proceso de creacion...");
            }
            else if (stats_option == 5) // promedio precio por catg.
            {
                printf("En proceso de creacion...");
            }
            else if (stats_option == 6) // cantidad prodc. por catg.
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
