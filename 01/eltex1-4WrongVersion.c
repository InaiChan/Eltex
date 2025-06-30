//программа убирает или включает 2 бит в первом числе, в зависимости, включен ли 2 бит во втором числе

#include <stdio.h>

int main(void) {
    int a, b;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    unsigned int mask = 0b00000000000000000000000000000100;
    unsigned int mask2 = 0b10000000000000000000000000000000;
    unsigned int value = 0;

    value = ((b & mask) == mask) ? mask : ~mask;

    if(value == mask) {
        a = a | value;
    } else {
        a = a & value;
    }

    printf("Result: ");

    for(int i = 0; i < 32; i++) {
        ((a & mask2) == mask2) ? printf("%d", 1) : printf("%d", 0);
        mask2 >>= 1;
    }

    return 0;
}

// 0b00000000000000000000000000001101
// &
// 0b00000000000000000000000000000100
// 0b11111111111111111111111111111011
// ==
// 0b00000000000000000000000000000100


// 0b00000000000000000000000000110101 53
// 0b00000000000000000000000000011001 25

// 0b00000000000000000000000000001101 13
// 0b00000000000000000000000000000101 5