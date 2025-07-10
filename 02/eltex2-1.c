#include <stdio.h>

#define N 3

int main(void) {
    int a[N*N];
    for(int i = 1; i <= N*N; i++) {
        printf("%d ", i);
        if(i % N == 0) printf("\n");
    }

    return 0;
}
