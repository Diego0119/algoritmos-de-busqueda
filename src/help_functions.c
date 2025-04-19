#include "header.h"

/**
 * @brief Muestra el contenido de un archivo CSV como una tabla en la consola.
 * @param filename Nombre del archivo CSV a mostrar.
*/

void display_csv_as_table(const char *filename)
{
    FILE *file = fopen(filename, "r"); // Abre el archivo en modo lectura
    if (file == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char line[MAX_LINE_LENGTH]; // Buffer para almacenar cada línea del archivo

    printf("%-10s %-30s %-15s %-10s %-10s\n", "ID", "Nombre", "Categoria", "Precio", "Stock");

    while (fgets(line, sizeof(line), file)) // Lee cada linea del archivo
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

int load_products(const char *filename, Producto productos[]) 
{
    FILE *file = fopen(filename, "r");
    if (!file) 
    {
        fprintf(stderr, "Error: No se pudo abrir el archivo '%s'.\n", filename);
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int count = 0;

    if (!fgets(line, sizeof(line), file)) 
    {
        fprintf(stderr, "Error: El archivo '%s' esta vacio o no tiene encabezados.\n", filename);
        fclose(file);
        return -1;
    }

    while (fgets(line, sizeof(line), file)) 
    {
        line[strcspn(line, "\n")] = '\0';

        if (strlen(line) == 0) 
        {
            fprintf(stderr, "Advertencia: Linea vacia encontrada en el archivo.\n");
            continue;
        }

        if (sscanf(line, "%d,%99[^,],%49[^,],%f,%d",
                   &productos[count].id,
                   productos[count].nombre,
                   productos[count].categoria,
                   &productos[count].precio,
                   &productos[count].stock) == 5) 
                   {
            count++;
            if (count >= MAX_NUMBER_OF_PRODUCTS) 
            {
                fprintf(stderr, "Advertencia: Se alcanzo el limite maximo de productos (%d).\n", MAX_NUMBER_OF_PRODUCTS);
                break;
            }
        } 
        else 
        {
            fprintf(stderr, "Advertencia: Linea con formato incorrecto: '%s'\n", line);
        }
    }

    fclose(file);
    
    return count;
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
