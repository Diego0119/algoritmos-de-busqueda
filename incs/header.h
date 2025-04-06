#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_LINE_LENGTH 1024

typedef struct
{
    int id;
    char nombre[100];
    char categoria[50];
    float precio;
    int stock;
} Producto;

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

void show_menu(void);

int load_products(const char *filename, Producto productos[]);

void insertion_sort_by_id(Producto productos[], int n);

void insertion_sort_by_name(Producto productos[], int n);

void insertion_sort_by_price(Producto productos[], int n);

void insertion_sort_by_stock(Producto productos[], int n);

void selection_sort_by_id(Producto producto[], int n);

void selection_sort_by_price(Producto producto[], int n);

void selection_sort_by_stock(Producto producto[], int n);

void selection_sort_by_name(Producto producto[], int n);

int secuencial_search(Producto productos[], int cantidad, int id);

void total_stock(Producto producto[], int n);

void valor_inventario(Producto producto[], int n);

void save_products(const char *filename, Producto productos[], int n);
