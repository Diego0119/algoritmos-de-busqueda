#include "header.h"

// Función para cargar productos
void handle_load_products(Producto productos[], int *cantidad)
{
    *cantidad = load_products("data.csv", productos);
    printf("%d productos cargados.\n", *cantidad);
    display_csv_as_table("data.csv");
}