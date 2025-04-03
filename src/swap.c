#include "header.h"

void swap(int *element_a, int *element_b)
{
    int *temp = *element_a;
    *element_a = *element_b;
    *element_b = temp;
}