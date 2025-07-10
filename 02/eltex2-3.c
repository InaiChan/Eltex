#include <stdio.h>

#define N 10

int main(void) {
    int a[N][N] = {0};
    int count = N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            a[i][j] = (j < count - 1) ? 0 : 1;
        }
        --count;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
