#include <stdio.h>

int main() {
    int a = 5;
    int b = 3;
    int c = a + b;
    printf("c=%d\n", c);

    a = 10;
    b = 7;
    c = a + b;
    printf("c=%d\n", c);

    a = -3;
    b = 7;
    c = a + b;
    printf("c=%d\n", c);

    return 0;
}
