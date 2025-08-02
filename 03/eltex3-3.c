#include <stdio.h>

#define N 10

int main(void) {
    int array[N] = {0};
    int count = 0;

    while(count < N && scanf("%d", &array[count]) == 1) {
        count++;
    }

    int *ptr = &array[0];
    for(int j = 0; j < N; j++) {
        printf("%d ", *ptr++);
    }

    return 0;
}