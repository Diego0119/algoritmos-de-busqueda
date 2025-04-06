#include "header.h"

void display_csv_as_table(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];

    printf("%-10s %-30s %-15s %-10s %-10s\n", "ID", "Nombre", "Categoria", "Precio", "Stock");

    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line, "\n")] = 0;

        char *id = strtok(line, ",");
        char *nombre = strtok(NULL, ",");
        char *categoria = strtok(NULL, ",");
        char *precio = strtok(NULL, ",");
        char *stock = strtok(NULL, ",");

        printf("%-10s %-30s %-15s %-10s %-10s\n", id, nombre, categoria, precio, stock);
    }

    fclose(file);
}

void show_menu(void)
{
    printf("Sistema de Gestion de Inventario\n");
    printf("1. Cargar productos desde CSV\n");
    printf("2. Ordenar productos\n");
    printf("3. Buscar producto\n");
    printf("4. Ver estadísticas\n");
    printf("5. Salir\n");
}
int load_products(const char *filename, Producto productos[])
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    int index = 0;

    if (fgets(line, sizeof(line), file) == NULL) 
    {
        fprintf(stderr, "Error al leer la linea del archivo o fin del archivo alcanzado.\n");
        fclose(file);
        return 0;
    }

    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line, "\n")] = 0;

        char *id_str = strtok(line, ",");
        char *nombre = strtok(NULL, ",");
        char *categoria = strtok(NULL, ",");
        char *precio_str = strtok(NULL, ",");
        char *stock_str = strtok(NULL, ",");

        productos[index].id = atoi(id_str);
        strcpy(productos[index].nombre, nombre);
        strcpy(productos[index].categoria, categoria);
        productos[index].precio = atof(precio_str);
        productos[index].stock = atoi(stock_str);

        index++;
    }

    fclose(file);
    return index;
}

void save_products(const char *filename, Producto productos[], int n)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo para escribir.\n");
        return;
    }

    fprintf(file, "id,nombre,categoria,precio,stock\n");

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d,%s,%s,%.2f,%d\n",
                productos[i].id,
                productos[i].nombre,
                productos[i].categoria,
                productos[i].precio,
                productos[i].stock);
    }

    fclose(file);
    printf("Productos guardados en %s correctamente.\n", filename);
}
