#include "stdio.h"

extern int my_add(int a, int b);

void main()
{
    int i = 1;
    int j = 2;
    int k = my_add(i, j);
    printf("k = %d \n", k);
}
