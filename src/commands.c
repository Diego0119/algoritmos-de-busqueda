#include "header.h" // Asegúrate de incluir el encabezado necesario

/**
 * @brief Muestra la ayuda del programa
 */
void show_help()
{
    printf("Uso: ./program.out [opciones]\n");
    printf("Opciones disponibles:\n");
    printf("  --help                 Muestra esta ayuda\n");
    printf("  --binary-search <campo> <valor>  Realiza una busqueda binaria en el campo especificado\n");
    printf("  --sequential-search <campo> <valor>  Realiza una busqueda secuencial en el campo especificado\n");
    printf("  --bubble-sort <campo>  Ordena los datos usando Bubble Sort\n");
    printf("  --insertion-sort <campo>  Ordena los datos usando Insertion Sort\n");
    printf("  --selection-sort <campo>  Ordena los datos usando Selection Sort\n");
    printf("  --generate <cantidad>  Genera un archivo CSV con datos aleatorios\n");
    printf("  --modify-price <ID> <nuevo_precio>  Modifica el precio de un producto por su ID\n");
    printf("  --modify-stock <ID> <nuevo_stock>  Modifica el stock de un producto por su ID\n");
}

/**
 * @brief Maneja los comandos de línea de comandos
 */
void handle_commands(int argc, char *argv[])
{
    int opt;
    int opt_index = 0;

    static struct option long_options[] =
        {
            {"help", no_argument, 0, 'h'},
            {"binary-search", no_argument, 0, 'b'},
            {"sequential-search", no_argument, 0, 's'},
            {"bubble-sort", no_argument, 0, 'u'},
            {"insertion-sort", no_argument, 0, 'i'},
            {"selection-sort", no_argument, 0, 'e'},
            {"generate", required_argument, 0, 'g'},
            {"modify-price", no_argument, 0, 'p'},
            {"modify-stock", no_argument, 0, 't'},
            {0, 0, 0, 0}};

    while ((opt = getopt_long(argc, argv, "hb:s:uieg:", long_options, &opt_index)) != -1)
    {
        switch (opt)
        {
        case 'h':
            show_help();
            return;

        case 'b':
        {
            if (optind + 1 >= argc)
            {
                printf("Error: Debes proporcionar un campo (ID, Nombre, Categoría, Precio, Stock) y un valor para la búsqueda binaria.\n");
                return;
            }

            const char *campo = argv[optind];
            const char *valor = argv[optind + 1];

            Producto productos[MAX_NUMBER_OF_PRODUCTS];
            int cantidad = load_products("data.csv", productos);
            if (cantidad == -1)
            {
                printf("Error: No se pudo cargar el archivo CSV.\n");
                return;
            }

            if (strcmp(campo, "ID") == 0)
            {
                int id = atoi(valor);
                selection_sort_by_id(productos, cantidad);
                int index = recursive_binary_search_by_id(productos, 0, cantidad - 1, id);
                if (index != -1)
                {
                    printf("Producto encontrado: ID=%d, Nombre=%s, Categoría=%s, Precio=%.2f, Stock=%d\n",
                           productos[index].id, productos[index].nombre, productos[index].categoria,
                           productos[index].precio, productos[index].stock);
                }
                else
                {
                    printf("Producto no encontrado.\n");
                }
            }
            else if (strcmp(campo, "Nombre") == 0)
            {
                selection_sort_by_name(productos, cantidad);
                int index = recursive_binary_search_by_name(productos, 0, cantidad - 1, (char *)valor);
                if (index != -1)
                {
                    printf("Producto encontrado: ID=%d, Nombre=%s, Categoría=%s, Precio=%.2f, Stock=%d\n",
                           productos[index].id, productos[index].nombre, productos[index].categoria,
                           productos[index].precio, productos[index].stock);
                }
                else
                {
                    printf("Producto no encontrado.\n");
                }
            }
            else if (strcmp(campo, "Categoria") == 0)
            {
                binary_search_by_categoria(productos, cantidad, valor);
            }
            else if (strcmp(campo, "Precio") == 0)
            {
                float precio = atof(valor);
                binary_search_by_precio(productos, cantidad, precio);
            }
            else if (strcmp(campo, "Stock") == 0)
            {
                int stock = atoi(valor);
                binary_search_by_stock(productos, cantidad, stock);
            }
            else
            {
                printf("Error: Campo no soportado para la búsqueda binaria. Los campos válidos son: ID, Nombre, Categoría, Precio, Stock.\n");
            }
            return;
        }

        case 's':
        {
            if (optind + 1 >= argc)
            {
                printf("Error: Debes proporcionar un campo (ID, Nombre, Categoria, Precio, Stock) y un valor para la busqueda secuencial.\n");
                return;
            }

            const char *campo = argv[optind];
            const char *valor = argv[optind + 1];

            Producto productos[MAX_NUMBER_OF_PRODUCTS];
            int cantidad = load_products("data.csv", productos);
            if (cantidad == -1)
            {
                printf("Error: No se pudo cargar el archivo CSV.\n");
                return;
            }

            if (strcmp(campo, "ID") == 0)
            {
                int id = atoi(valor);
                int index = secuencial_search_by_id(productos, cantidad, id);
                if (index != -1)
                {
                    printf("Producto encontrado: ID=%d, Nombre=%s, Categoria=%s, Precio=%.2f, Stock=%d\n",
                           productos[index].id, productos[index].nombre, productos[index].categoria,
                           productos[index].precio, productos[index].stock);
                }
                else
                {
                    printf("Producto no encontrado.\n");
                }
            }
            else if (strcmp(campo, "Nombre") == 0)
            {
                int encontrado = secuencial_search_by_name(productos, cantidad, valor);
                if (!encontrado)
                {
                    printf("Producto no encontrado.\n");
                }
            }
            else if (strcmp(campo, "Categoria") == 0)
            {
                int encontrado = secuencial_search_by_categoria(productos, cantidad, valor);
                if (!encontrado)
                {
                    printf("Producto no encontrado.\n");
                }
            }
            else if (strcmp(campo, "Precio") == 0)
            {
                float precio = atof(valor);
                int encontrado = secuencial_search_by_precio(productos, cantidad, precio);
                if (!encontrado)
                {
                    printf("Producto no encontrado.\n");
                }
            }
            else if (strcmp(campo, "Stock") == 0)
            {
                int stock = atoi(valor);
                int encontrado = secuencial_search_by_stock(productos, cantidad, stock);
                if (!encontrado)
                {
                    printf("Producto no encontrado.\n");
                }
            }
            else
            {
                printf("Error: Campo no soportado para la busqueda secuencial. Los campos validos son: ID, Nombre, Categoria, Precio, Stock.\n");
            }
            return;
        }

        case 'u':
        {
            if (optind >= argc)
            {
                printf("Error: Debes proporcionar un campo para la ordenación (ID, Nombre, Precio, Stock).\n");
                return;
            }

            const char *campo = argv[optind];
            Producto productos[MAX_NUMBER_OF_PRODUCTS];
            int cantidad = load_products("data.csv", productos);
            if (cantidad == -1)
            {
                printf("Error: No se pudo cargar el archivo CSV.\n");
                return;
            }

            if (strcmp(campo, "ID") == 0)
            {
                bubble_sort_by_id(productos, cantidad);
            }
            else if (strcmp(campo, "Nombre") == 0)
            {
                bubble_sort_by_name(productos, cantidad);
            }
            else if (strcmp(campo, "Precio") == 0)
            {
                bubble_sort_by_price(productos, cantidad);
            }
            else if (strcmp(campo, "Stock") == 0)
            {
                bubble_sort_by_stock(productos, cantidad);
            }
            else
            {
                printf("Error: Campo no valido. Usa ID, Nombre, Precio o Stock.\n");
                return;
            }

            save_products("data.csv", productos, cantidad);
            printf("Productos ordenados por %s usando Bubble Sort.\n", campo);
            return;
        }

        case 'i':
        {
            if (optind >= argc)
            {
                printf("Error: Debes proporcionar un campo para la ordenación (ID, Nombre, Precio, Stock).\n");
                return;
            }

            const char *campo = argv[optind];
            Producto productos[MAX_NUMBER_OF_PRODUCTS];
            int cantidad = load_products("data.csv", productos);
            if (cantidad == -1)
            {
                printf("Error: No se pudo cargar el archivo CSV.\n");
                return;
            }

            if (strcmp(campo, "ID") == 0)
            {
                insertion_sort_by_id(productos, cantidad);
            }
            else if (strcmp(campo, "Nombre") == 0)
            {
                insertion_sort_by_name(productos, cantidad);
            }
            else if (strcmp(campo, "Precio") == 0)
            {
                insertion_sort_by_price(productos, cantidad);
            }
            else if (strcmp(campo, "Stock") == 0)
            {
                insertion_sort_by_stock(productos, cantidad);
            }
            else
            {
                printf("Error: Campo no valido. Usa ID, Nombre, Precio o Stock.\n");
                return;
            }

            save_products("data.csv", productos, cantidad);
            printf("Productos ordenados por %s usando Insertion Sort.\n", campo);
            return;
        }

        case 'e':
        {
            if (optind >= argc)
            {
                printf("Error: Debes proporcionar un campo para la ordenación (ID, Nombre, Precio, Stock).\n");
                return;
            }

            const char *campo = argv[optind];
            Producto productos[MAX_NUMBER_OF_PRODUCTS];
            int cantidad = load_products("data.csv", productos);
            if (cantidad == -1)
            {
                printf("Error: No se pudo cargar el archivo CSV.\n");
                return;
            }

            if (strcmp(campo, "ID") == 0)
            {
                selection_sort_by_id(productos, cantidad);
            }
            else if (strcmp(campo, "Nombre") == 0)
            {
                selection_sort_by_name(productos, cantidad);
            }
            else if (strcmp(campo, "Precio") == 0)
            {
                selection_sort_by_price(productos, cantidad);
            }
            else if (strcmp(campo, "Stock") == 0)
            {
                selection_sort_by_stock(productos, cantidad);
            }
            else
            {
                printf("Error: Campo no valido. Usa ID, Nombre, Precio o Stock.\n");
                return;
            }

            save_products("data.csv", productos, cantidad);
            printf("Productos ordenados por %s usando Selection Sort.\n", campo);
            return;
        }

        case 'g':
        {
            char *endptr;
            int cantidad = strtol(optarg, &endptr, 10);
            if (*endptr != '\0' || cantidad <= 0)
            {
                printf("Error: La cantidad debe ser un numero entero positivo.\n");
                return;
            }
            printf("Generando archivo CSV con %d datos...\n", cantidad);
            generate_products_csv("data.csv", cantidad);
            return;
        }
        case 'p':
        {
            if (optind + 1 >= argc)
            {
                printf("Error: Debes proporcionar el ID del producto y el nuevo precio.\n");
                printf("Uso: ./program.out --modify-price <ID> <nuevo_precio>\n");
                return;
            }

            int id = atoi(argv[optind]);
            double nuevo_precio = atof(argv[optind + 1]);

            Producto productos[MAX_NUMBER_OF_PRODUCTS];
            int cantidad = load_products("data.csv", productos);
            if (cantidad == -1)
            {
                printf("Error: No se pudo cargar el archivo CSV.\n");
                return;
            }

            int encontrado = 0;
            for (int i = 0; i < cantidad; i++)
            {
                if (productos[i].id == id)
                {
                    productos[i].precio = nuevo_precio;
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado)
            {
                printf("Error: No se encontro un producto con el ID %d.\n", id);
                return;
            }

            save_products("data.csv", productos, cantidad);
            printf("Producto con ID %d modificado correctamente. Nuevo precio: %.2f.\n", id, nuevo_precio);
            return;
        }

        case 't':
        {
            if (optind + 1 >= argc)
            {
                printf("Error: Debes proporcionar el ID del producto y el nuevo stock.\n");
                printf("Uso: ./program.out --modify-stock <ID> <nuevo_stock>\n");
                return;
            }

            int id = atoi(argv[optind]);
            int nuevo_stock = atoi(argv[optind + 1]);

            Producto productos[MAX_NUMBER_OF_PRODUCTS];
            int cantidad = load_products("data.csv", productos);
            if (cantidad == -1)
            {
                printf("Error: No se pudo cargar el archivo CSV.\n");
                return;
            }

            int encontrado = 0;
            for (int i = 0; i < cantidad; i++)
            {
                if (productos[i].id == id)
                {
                    productos[i].stock = nuevo_stock;
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado)
            {
                printf("Error: No se encontro un producto con el ID %d.\n", id);
                return;
            }

            save_products("data.csv", productos, cantidad);
            printf("Producto con ID %d modificado correctamente. Nuevo stock: %d.\n", id, nuevo_stock);
            return;
        }

        default:
            printf("Opcion no valida. Usa --help para ver las opciones disponibles.\n");
            return;
        }
    }

    printf("No se proporcionaron opciones. Usa --help para ver las opciones disponibles.\n");
}