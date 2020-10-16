#include <stddef.h>
#include <stdint.h>

size_t naive(size_t offset, size_t page_queues) {
    return offset / page_queues;
}

#define ffs32(x)  ((__builtin_ffs(x)) - 1)
size_t bitwise(size_t offset, size_t page_queues) {
    size_t blockidx;
    size_t divident = page_queues;
    blockidx = offset >> ffs32(divident);
    divident >>= ffs32(divident);
    switch (divident) {
        case 3: blockidx /= 3;
            break;
        case 5: blockidx /= 5;
            break;
        case 7: blockidx /= 7;
            break;
    }
}

int main() {
    
}
