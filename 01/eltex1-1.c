#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);
    unsigned int mask = 0b10000000000000000000000000000000;
    for(int i = 0; i < 32; i++) {
        (a & mask) == mask ? printf("%d", 1) : printf("%d", 0);
        mask = mask >> 1;
    }

    return 0;
}
