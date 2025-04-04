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
            printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n");
            int sort_option;
            scanf("%d", &sort_option);
            if (sort_option == 1)
            {
                printf("Datos antes de ordenar: \n");
                display_csv_as_table("data.csv");

                printf("Ordenando...\n");
                sleep(3);
                bubble_sort_op(productos, cantidad);

                printf("Datos después de ordenar (antes de guardar): \n");
                display_csv_as_table("data.csv");

                save_products("data.csv", productos, cantidad);
                printf("Productos ordenados con Bubble Sort.\n");

                printf("Datos después de guardar: \n");
                display_csv_as_table("data.csv");
            }
            else if (sort_option == 2)
            {
                printf("En construcción...\n");
            }
            else if (sort_option == 3)
            {
                printf("Datos antes de ordenar: \n");
                display_csv_as_table("data.csv");

                printf("Ordenando...\n");
                sleep(3);
                insertion_sort(productos, cantidad);

                printf("Datos después de ordenar (antes de guardar): \n");
                display_csv_as_table("data.csv");

                save_products("data.csv", productos, cantidad);
                printf("Productos ordenados con Insertion Sort.\n");

                printf("Datos después de guardar: \n");
                display_csv_as_table("data.csv");
            }
            break;
            printf("Productos ordenados.\n");
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
