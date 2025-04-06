#include "header.h"
//preguntar si las funciones las hacemos en ingles :P
void total_stock(Producto producto[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += producto[i].stock;

    printf("\nTotal de productos en stock: %d\n\n", total);
}

void valor_inventario(Producto producto[], int n) //suma de precio × stock por producto
{
    float total_valor = 0;
    for (int i = 0; i < n; i++)
        total_valor += producto[i].precio * producto[i].stock;

    printf("\nValor total del inventario: $%.2f\n\n", total_valor);
}

/*void mayor_stock(Producto producto[], int n)
{
    //hablar de cual algoritmo usar para ordenar y despues escoger el primer o ultimo indice
}

void menor_stock()
{
    //hablar de cual algoritmo usar para ordenar y despues escoger el primer o ultimo indice
}

void mas_caro()
{
    //hablar de cual algoritmo usar para ordenar y despues escoger el primer o ultimo indice
}

void menos_caro()
{
    //hablar de cual algoritmo usar para ordenar y despues escoger el primer o ultimo indice
}

void promedio_precio_por_categoria()
{

}

void total_productos_por_categoria()
{

}
*/