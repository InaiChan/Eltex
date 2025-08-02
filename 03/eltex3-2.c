#include <stdio.h>

int main(void) {
    float x = 5.0;
    float y = 6.0;
    printf("x = %f, ", x);
    float *xp = &x + 1; // TODO: отредактируйте эту строку, и только правую часть уравнения
    printf("y = %f\n", y);
    float *yp = &y;
    printf("Результат: %f\n", *xp + *yp);
}