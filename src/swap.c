/**
 * @file swap.c
 * @brief archivo que contine la función swap
 * @authors Felipe Carcamo, Duvan Figueroa, Diego Sanhueza
 */

#include "header.h" ///< Incluye la definición de las funciones
/**
 * @brief función para intercambiar elementos
 *
 * @param element_a entero a intercambiar a
 * @param element_b entero a intercambiar b
 */
void swap_int(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}   
/**
 * @brief función para intercambiar elementos
 *
 * @param element_a entero a intercambiar a
 * @param element_b entero a intercambiar b
 */
void swap(Producto *a, Producto *b)
{
    Producto temp = *a;
    *a = *b;
    *b = temp;
}
