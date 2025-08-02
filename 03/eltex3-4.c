#include <stdio.h>

int main(void) {
    char str[100];
    char str2[100];
    scanf("%99s", str);
    scanf("%99s", str2);

    int count = 0;
    while(str2[count] != '\0') count++;

    char *result = NULL;

    for(int i = 0; str[i] != '\0'; i++) {
        int j = 0;
        while(str2[j] != '\0' && str[i + j] == str2[j]) {
            j++;
        }
        if(count == j) {
            result = &str[i];
            break;
        }
    }

    printf("%s", result ? result : "NULL");

    return 0;
}
