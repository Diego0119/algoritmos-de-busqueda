#include "header.h"

int secuencial_search(Producto productos[], int cantidad, int id) 
{
    for (int i = 0; i < cantidad; i++) {
        if (productos[i].id == id) {
            return i;
        }
    }
    return -1; 
}