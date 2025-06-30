#include <stdio.h>

int main() {
    int a, number;
    scanf("%d%d", &a, &number);
    unsigned char *ptr = (char*) &a;
    for(int i = 1; i <= sizeof(a); i++){
        *ptr = i == 3 ? number : *ptr;
        printf("%d ", *ptr++);
    }

    return 0;
}