#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int num;

// void eat_stack()
// {
//     if (num--) eat_stack();
// }


int main()
{
    int *x = (int *)malloc(sizeof(int)*10);
    free(x);
    x = (int *)malloc(sizeof(int)*10);
    int *y = (int *)malloc(sizeof(int)*10);
    free(y);
    free(x);
    return 0;
}


