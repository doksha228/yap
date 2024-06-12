#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

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

    reverseArray(random_numbers, ARRAY_SIZE);

    FILE *file = fopen("random_numbers.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        fprintf(file, "%d\n", random_numbers[i]);
    }

    fclose(file);

    printf("Массив записан в файл 'random_numbers.txt' в обратном порядке.\n");

    return 0;
}