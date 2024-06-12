#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для хранения данных о товаре
struct Product {
    char name[50];
    float price;
};

// Функция для сравнения цен товаров при сортировке
int comparePrices(const void *a, const void *b) {
    const struct Product *productA = (const struct Product *)a;
    const struct Product *productB = (const struct Product *)b;
    if (productA->price < productB->price) {
        return -1;
    } else if (productA->price > productB->price) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Использование: %s <входной_файл> <выходной_файл>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Ошибка открытия входного файла.\n");
        return 1;
    }

    int numProducts;
    fscanf(inputFile, "%d", &numProducts); // Читаем количество товаров из файла
    struct Product *products = (struct Product *)malloc(numProducts * sizeof(struct Product));

    for (int i = 0; i < numProducts; i++) {
        fscanf(inputFile, "%s %f", products[i].name, &products[i].price); // Читаем название и цену каждого товара из файла
    }

    fclose(inputFile);

    qsort(products, numProducts, sizeof(struct Product), comparePrices); // Сортируем товары по цене

    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Ошибка открытия выходного файла.\n");
        return 1;
    }

    for (int i = 0; i < numProducts; i++) {
        fprintf(outputFile, "%s %.2f\n", products[i].name, products[i].price); // Записываем отсортированные данные в выходной файл
    }

    fclose(outputFile);
    free(products);

    return 0;
}