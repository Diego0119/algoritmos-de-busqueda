#include "header.h"

void handle_statistics(Producto productos[], int cantidad)
{
    printf("Seleccione la estadistica que quiera ver:\n");
    printf("1. Total de productos en inventario\n");
    printf("2. Valor total del inventario\n");
    printf("3. Producto con mayor y menor stock\n");
    printf("4. Producto mas caro y mas barato\n");
    printf("5. Promedio de precios por categoria\n");
    printf("6. Cantidad de productos por categoria\n");
    int stats_option;
    if (scanf("%d", &stats_option) != 1)
    {
        fprintf(stderr, "Error: Entrada invalida.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    switch (stats_option)
    {
    case 1:
        total_stock(productos, cantidad);
        break;
    case 2:
        valor_inventario(productos, cantidad);
        break;
    case 3:
        mayor_menor_stock(productos, cantidad);
        break;
    case 4:
        mas_caro_mas_barato(productos, cantidad);
        break;
    case 5:
        promedio_precios_categoria(productos, cantidad);
        break;
    case 6:
        cantidad_productos_categoria(productos, cantidad);
        break;
    default:
        printf("Opcion no valida. Por favor, intente de nuevo.\n");
        break;
    }
}

void mayor_menor_stock(Producto productos[], int cantidad)
{
    if (cantidad == 0)
    {
        printf("No hay productos en el inventario.\n");
        return;
    }

    int mayor = 0, menor = 0;
    for (int i = 1; i < cantidad; i++)
    {
        if (productos[i].stock > productos[mayor].stock)
            mayor = i;
        if (productos[i].stock < productos[menor].stock)
            menor = i;
    }

    printf("Producto con mayor stock: %s (%d unidades)\n", productos[mayor].nombre, productos[mayor].stock);
    printf("Producto con menor stock: %s (%d unidades)\n", productos[menor].nombre, productos[menor].stock);
}

void mas_caro_mas_barato(Producto productos[], int cantidad)
{
    if (cantidad == 0)
    {
        printf("No hay productos en el inventario.\n");
        return;
    }

    int mas_caro = 0, mas_barato = 0;
    for (int i = 1; i < cantidad; i++)
    {
        if (productos[i].precio > productos[mas_caro].precio)
            mas_caro = i;
        if (productos[i].precio < productos[mas_barato].precio)
            mas_barato = i;
    }

    printf("Producto mas caro: %s (%.2f)\n", productos[mas_caro].nombre, productos[mas_caro].precio);
    printf("Producto mas barato: %s (%.2f)\n", productos[mas_barato].nombre, productos[mas_barato].precio);
}

void promedio_precios_categoria(Producto productos[], int cantidad)
{
    char categoria[50];
    printf("Ingrese la categoria para calcular el promedio de precios: ");
    if (scanf("%s", categoria) != 1)
    {
        fprintf(stderr, "Error: Entrada invalida.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    float suma = 0;
    int contador = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (strcmp(productos[i].categoria, categoria) == 0)
        {
            suma += productos[i].precio;
            contador++;
        }
    }

    if (contador == 0)
    {
        printf("No hay productos en la categoria %s.\n", categoria);
    }
    else
    {
        printf("Promedio de precios en la categoria %s: %.2f\n", categoria, suma / contador);
    }
}

void cantidad_productos_categoria(Producto productos[], int cantidad)
{
    char categoria[50];
    printf("Ingrese la categoria para contar los productos: ");
    if (scanf("%s", categoria) != 1)
    {
        fprintf(stderr, "Error: Entrada invalida.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    int contador = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (strcmp(productos[i].categoria, categoria) == 0)
        {
            contador++;
        }
    }

    printf("Cantidad de productos en la categoria %s: %d\n", categoria, contador);
}
