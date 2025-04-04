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
                    printf("En contruccion...\n");
                    break;
                case 2:
                    printf("En contruccion...\n");

                    break;
                case 3:
                    printf("En contruccion...\n");

                    break;
                case 4:
                    printf("En contruccion...\n");

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
                int id;
                printf("Ingrese el ID del producto a buscar: ");
                scanf("%d", &id);
                int index = recursive_binary_search(productos, 0, cantidad, id);
                if (index != -1)
                {
                    printf("Producto encontrado:\n");

                    printf("Nombre: %s\n", productos[index].nombre);
                    printf("Categoria: %s\n", productos[index].categoria);
                    printf("Precio: %f\n", productos[index].precio);
                    printf("Stock: %d\n", productos[index].stock);
                }
                else
                {
                    printf("Producto no encontrado.\n");
                }
            }
            break;
        case 4:
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
