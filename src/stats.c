#include "header.h"
// preguntar si las funciones las hacemos en ingles :P
void total_stock(Producto producto[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += producto[i].stock;

    printf("\nTotal de productos en stock: %d\n\n", total);
}

void valor_inventario(Producto producto[], int n) // suma de precio × stock por producto
{
    float total_valor = 0;
    for (int i = 0; i < n; i++)
        total_valor += producto[i].precio * producto[i].stock;

    printf("\nValor total del inventario: $%.2f\n\n", total_valor);
}

// Encuentra el producto con mayor stock
void mayor_stock(Producto productos[], int n) {
    if (n == 0) {
        printf("No hay productos disponibles.\n");
        return;
    }

    Producto *mayor = &productos[0];
    for (int i = 1; i < n; i++) {
        if (productos[i].stock > mayor->stock) {
            mayor = &productos[i];
        }
    }

    printf("Producto con mayor stock: ID=%d, Nombre=%s, Stock=%d\n", mayor->id, mayor->nombre, mayor->stock);
}

// Encuentra el producto con menor stock
void menor_stock(Producto productos[], int n) {
    if (n == 0) {
        printf("No hay productos disponibles.\n");
        return;
    }

    Producto *menor = &productos[0];
    for (int i = 1; i < n; i++) {
        if (productos[i].stock < menor->stock) {
            menor = &productos[i];
        }
    }

    printf("Producto con menor stock: ID=%d, Nombre=%s, Stock=%d\n", menor->id, menor->nombre, menor->stock);
}

// Encuentra el producto más caro
void mas_caro(Producto productos[], int n) {
    if (n == 0) {
        printf("No hay productos disponibles.\n");
        return;
    }

    Producto *mas_caro = &productos[0];
    for (int i = 1; i < n; i++) {
        if (productos[i].precio > mas_caro->precio) {
            mas_caro = &productos[i];
        }
    }

    printf("Producto más caro: ID=%d, Nombre=%s, Precio=%.2f\n", mas_caro->id, mas_caro->nombre, mas_caro->precio);
}

// Encuentra el producto más barato
void menos_caro(Producto productos[], int n) {
    if (n == 0) {
        printf("No hay productos disponibles.\n");
        return;
    }

    Producto *menos_caro = &productos[0];
    for (int i = 1; i < n; i++) {
        if (productos[i].precio < menos_caro->precio) {
            menos_caro = &productos[i];
        }
    }

    printf("Producto más barato: ID=%d, Nombre=%s, Precio=%.2f\n", menos_caro->id, menos_caro->nombre, menos_caro->precio);
}

// Calcula el promedio de precios por categoría
void promedio_precio_por_categoria(Producto productos[], int n) {
    if (n == 0) {
        printf("No hay productos disponibles.\n");
        return;
    }

    float suma_precios[MAX_CATEGORIAS] = {0};
    int conteo[MAX_CATEGORIAS] = {0};
    char categorias[MAX_CATEGORIAS][50];
    int num_categorias = 0;

    for (int i = 0; i < n; i++) {
        int categoria_index = -1;
        for (int j = 0; j < num_categorias; j++) {
            if (strcmp(productos[i].categoria, categorias[j]) == 0) {
                categoria_index = j;
                break;
            }
        }

        if (categoria_index == -1) {
            strcpy(categorias[num_categorias], productos[i].categoria);
            categoria_index = num_categorias++;
        }

        suma_precios[categoria_index] += productos[i].precio;
        conteo[categoria_index]++;
    }

    printf("Promedio de precios por categoría:\n");
    for (int i = 0; i < num_categorias; i++) {
        printf("Categoría: %s, Promedio: %.2f\n", categorias[i], suma_precios[i] / conteo[i]);
    }
}

// Calcula el total de productos por categoría
void total_productos_por_categoria(Producto productos[], int n) {
    if (n == 0) {
        printf("No hay productos disponibles.\n");
        return;
    }

    int conteo[MAX_CATEGORIAS] = {0};
    char categorias[MAX_CATEGORIAS][50];
    int num_categorias = 0;

    for (int i = 0; i < n; i++) {
        int categoria_index = -1;
        for (int j = 0; j < num_categorias; j++) {
            if (strcmp(productos[i].categoria, categorias[j]) == 0) {
                categoria_index = j;
                break;
            }
        }

        if (categoria_index == -1) {
            strcpy(categorias[num_categorias], productos[i].categoria);
            categoria_index = num_categorias++;
        }

        conteo[categoria_index]++;
    }

    printf("Total de productos por categoría:\n");
    for (int i = 0; i < num_categorias; i++) {
        printf("Categoría: %s, Total: %d\n", categorias[i], conteo[i]);
    }
}