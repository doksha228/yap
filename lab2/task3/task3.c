#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArrayWithRandomFloats(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (float)rand() / (float)(RAND_MAX);  // Генерируем случайное число с плавающей точкой от 0 до 1
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Использование: %s <размер массива>\n", argv[0]);
        return 1;
    }

    int arraySize = atoi(argv[1]);
    if (arraySize <= 0) {
        printf("Размер массива должен быть положительным числом.\n");
        return 1;
    }

    float random_floats[arraySize];
    srand(time(NULL));

    fillArrayWithRandomFloats(random_floats, arraySize);

    printf("Сгенерированный массив случайных чисел с плавающей точкой:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%f\n", random_floats[i]);
    }

    return 0;
}