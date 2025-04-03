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
void swap(int *element_a, int *element_b)
{
    int *temp = *element_a;
    *element_a = *element_b;
    *element_b = temp;
}