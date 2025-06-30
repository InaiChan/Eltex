#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);
    unsigned int mask = 0b10000000000000000000000000000000;
    int count = 0;
    for(int i = 0; i < 32; i++) {
        ((a & mask) == mask) ? count++ : count;
        mask = mask >> 1;
    }
    printf("%d", count);
    return 0;
}