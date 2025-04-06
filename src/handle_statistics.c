#include "header.h"
// Función para mostrar estadísticas
void handle_statistics(Producto productos[], int cantidad) 
{
    printf("Seleccione la estadística que quiera ver:\n");
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
        return;
    }

    switch (stats_option) 
    {
        case 1: total_stock(productos, cantidad); break;
        case 2: valor_inventario(productos, cantidad); break;
        default: printf("En proceso de creación...\n"); break;
    }
}
