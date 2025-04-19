#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#define MAX_LINE_LENGTH 1024
#define MAX_PRODUCTS 10
#define MAX_NUMBER_OF_PRODUCTS 5000
#define MAX_CATEGORIAS 50

extern const char *categorias[];
extern const char *nombres[];

typedef struct
{
    int id;
    char nombre[100];
    char categoria[50];
    float precio;
    int stock;
} Producto;

void generate_products_csv(const char *nombre_archivo, int cantidad);

void swap_int(int *a, int *b);
void swap(Producto *a, Producto *b);

void bubble_sort(int arr[], int n);

void bubble_sort_by_id(Producto productos[], int n);

void bubble_sort_by_name(Producto productos[], int n);

void bubble_sort_by_price(Producto productos[], int n);

void bubble_sort_by_stock(Producto productos[], int n);

int iterative_binary_search(int arr[], int n, int target);

int recursive_binary_search_by_id(Producto productos[], int left, int right, int target);

int recursive_binary_search_by_name(Producto productos[], int left, int right, char *target);

int recursive_binary_search_by_price_range(Producto productos[], int left, int right, int target);

void display_csv_as_table(const char *filename);

int load_products(const char *filename, Producto productos[]);

void insertion_sort_by_id(Producto productos[], int n);

void insertion_sort_by_name(Producto productos[], int n);

void insertion_sort_by_price(Producto productos[], int n);

void insertion_sort_by_stock(Producto productos[], int n);

void selection_sort_by_id(Producto producto[], int n);

void selection_sort_by_price(Producto producto[], int n);

void selection_sort_by_stock(Producto producto[], int n);

void selection_sort_by_name(Producto producto[], int n);

int secuencial_search(Producto productos[], int cantidad, int (*criterio)(Producto, void *), void *clave);

void total_stock(Producto producto[], int n);

void valor_inventario(Producto producto[], int n);

void save_products(const char *filename, Producto productos[], int n);

void handle_statistics(Producto productos[], int cantidad);

void handle_search_products(Producto productos[], int cantidad);

void handle_sort_products(Producto productos[], int cantidad);

void handle_load_products(Producto productos[], int *cantidad);

// Prototipos de funciones para manejar estadísticas

void total_stock(Producto productos[], int cantidad);

void valor_inventario(Producto productos[], int cantidad);

void mayor_menor_stock(Producto productos[], int cantidad);

void mas_caro_mas_barato(Producto productos[], int cantidad);

void promedio_precios_categoria(Producto productos[], int cantidad);

void cantidad_productos_categoria(Producto productos[], int cantidad);

int secuencial_search_by_id(Producto productos[], int cantidad, int id);

int secuencial_search_by_name(Producto productos[], int cantidad, const char *nombre);

void take_time_producto(void (*func)(Producto *, int), Producto *arr, int n, const char *nombre_archivo);

void take_time_search(int (*search_func)(Producto[], int, int), Producto productos[], int cantidad, const char *archivo_resultado);

int secuencial_search_by_categoria(Producto productos[], int cantidad, const char *categoria);

int secuencial_search_by_precio(Producto productos[], int cantidad, float precio);

int secuencial_search_by_stock(Producto productos[], int cantidad, int stock);

void binary_search_by_stock(Producto productos[], int cantidad, int stock);

void binary_search_by_categoria(Producto productos[], int cantidad, const char *categoria);

void binary_search_by_precio(Producto productos[], int cantidad, float precio);

int wrapper_binary_search(Producto productos[], int cantidad, int id);

// Prototipos de funciones para manejar la ayuda

void show_help(void);

void handle_commands(int argc, char *argv[]);

void mayor_stock(Producto productos[], int n);

void menor_stock(Producto productos[], int n);

void mas_caro(Producto productos[], int n);

void menos_caro(Producto productos[], int n);

void promedio_precio_por_categoria(Producto productos[], int n);

void total_productos_por_categoria(Producto productos[], int n);

int criterio_por_id(Producto producto, void *clave);

#endif
