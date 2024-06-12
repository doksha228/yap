#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Стек переполнен. Невозможно добавить элемент %d\n", value);
    } else {
        stack->items[++(stack->top)] = value;
        printf("Добавлено значение %d в стек\n", value);
    }
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Стек пуст. Невозможно извлечь значение\n");
        return -1;
    } else {
        return stack->items[(stack->top)--];
    }
}

void peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Стек пуст. Нет верхнего значения для просмотра\n");
    } else {
        printf("Верхнее значение стека: %d\n", stack->items[stack->top]);
    }
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    // Примеры операций над стеком
    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);

    printf("Извлечено значение из стека: %d\n", pop(&stack));
    printf("Извлечено значение из стека: %d\n", pop(&stack);

    push(&stack, 20);
    push(&stack, 25);

    peek(&stack);

    return 0;
}