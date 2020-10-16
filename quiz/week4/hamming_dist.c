#include <stdio.h>
#include <stdlib.h>


int hammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
}


int main() {
    printf("%d\n", hammingDistance(4, 1));
    return 0;
}