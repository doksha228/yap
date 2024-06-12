#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

int main() {
    int random_numbers[ARRAY_SIZE];
    srand(time(NULL));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        random_numbers[i] = rand() % 100;  // Генерируем случайное число от 0 до 99
    }

    printf("Сгенерированный массив случайных чисел:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", random_numbers[i]);
    }
    printf("\n");

    return 0;
}