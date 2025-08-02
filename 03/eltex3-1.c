#include <stdio.h>

int main(void) {
    int number;
    unsigned char third_byte;

    printf("Enter number: ");
    if(scanf("%d", &number) != 1) {
        printf("Input error");
        return 0;
    }
    printf("Enter third byte: ");
    if(scanf("%hhu", &third_byte) != 1) {
            printf("Input error");
            return 0;
    }
    printf("third byte: %hhu\n", third_byte);
    unsigned char *ptr = (char*) &number;


    for(int i = 1; i <= sizeof(number); i++) {
        *ptr = i == 3 ? third_byte : *ptr;
        printf("%d ", *ptr++);
    }

    return 0;
}

// #include <stdio.h>

// int main() {
//     int a, number;
//     scanf("%d%d", &a, &number);
//     unsigned char *ptr = (char*) &a;
//     for(int i = 1; i <= sizeof(a); i++){
//         *ptr = i == 3 ? number : *ptr;
//         printf("%d ", *ptr++);
//     }

//     return 0;
// }