#include "header.h"

/**
 * @brief Genera un archivo CSV con productos aleatorios.
 * 
 * @param nombre_archivo Nombre del archivo CSV a generar.
 * @param cantidad Número de productos a generar.
 */

const char *nombres[MAX_PRODUCTS] = {
    "Laptop HP", "Monitor Dell 24\"", "Teclado Mecánico", "Mouse Inalámbrico",
    "Auriculares Bluetooth", "Altavoz Portátil", "Impresora Epson", "Cartucho Negro",
    "Tablet Samsung", "Disco Duro Externo"};

const char *categorias[MAX_PRODUCTS] = {
    "Cómputo", "Cómputo", "Cómputo", "Cómputo",
    "Audio", "Audio", "Impresión", "Impresión",
    "Cómputo", "Almacenamiento"};

void generate_products_csv(const char *nombre_archivo, int cantidad)
{
    FILE *archivo = fopen(nombre_archivo, "w"); // Abre el archivo en modo escritura
    if (archivo == NULL) // Verifica si el archivo se abrió correctamente
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "ID,Nombre,Categoría,Precio,Stock\n");

    srand(time(NULL)); // Inicializa la semilla para la generación de números aleatorios
    // Se inicializa un arreglo para verificar si el id ya fue ocupado

    int ids_usados[MAX_PRODUCTS * 10] = {0};
    // int index_ids_usados = 0;

    for (int i = 0; i < cantidad; i++)
    {
        int id;

        do
        {
            id = rand() % (MAX_NUMBER_OF_PRODUCTS * 10) + 1001; // genera id's para los poductos
        } while (ids_usados[id - 1001] != 0); // verifica si el id ya fue ocupado

        ids_usados[id - 1001] = 1;

        int indice = rand() % MAX_PRODUCTS;
        double precio = (rand() % 90000 + 1000) / 100.0;
        int stock = rand() % 200 + 1;

        fprintf(archivo, "%d,%s,%s,%.2f,%d\n",
                id, nombres[indice], categorias[indice], precio, stock);
    }

    fclose(archivo);
    printf("Archivo CSV generado con éxito: %s\n", nombre_archivo);
}
