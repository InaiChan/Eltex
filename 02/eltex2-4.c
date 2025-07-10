#include <stdio.h>

#define N 5

int main(void) {
    int ar[N][N] = {0};
    int number = 1;
    int count = 0;

    while(count != N/2 + 1) {
        int i = count;
        int j = count;

        for(; j < N - count - 1; j++) {
            ar[i][j] = number++;
        }

        i = N - count - 1;
        for(j = count; j < N - count - 1; j++) {
            ar[j][i] = number++;
        }

        i = N - count - 1;
        for(j = N - count - 1; j > count; j--) {
            ar[i][j] = number++;
        }

        i = count;
        for(j = N - count - 1; j > count; j--) {
            ar[j][i] = number++;
        }

        if(count == N/2 && N != 2) {
            ar[N/2][N/2] = number++;
        }

        count++;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }

    return 0;
}