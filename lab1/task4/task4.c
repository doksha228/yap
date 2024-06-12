#include <stdio.h>

int main() {
    float a, b, c, x;

    printf("Введите коэффициент a: ");
    scanf("%f", &a);

    printf("Введите коэффициент b: ");
    scanf("%f", &b);

    printf("Введите значение c: ");
    scanf("%f", &c);

    if (a == 0) {
        if (b == c) {
            printf("Решений бесконечно много (уравнение тождественно верно)\n");
        } else {
            printf("Нет решений (уравнение неверно)\n");
        }
    } else {
        x = (c - b) / a;
        printf("x = %.2f\n", x);
    }

    return 0;
}
printf("x=%f\n", x);

return 0;



