#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, int value) {
    stack->items[++(stack->top)] = value;
}

int pop(struct Stack *stack) {
    return stack->items[(stack->top)--];
}

int evaluatePostfix(char *expression) {
    struct Stack stack;
    initializeStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&stack);
}

int main() {
    FILE *inputFile;
    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Не удалось открыть файл\n");
        return 1;
    }

    char expression[MAX_SIZE];
    while (fscanf(inputFile, "%s", expression) != EOF) {
        printf("Выражение: %s\n", expression);
        int result = evaluatePostfix(expression);
        printf("Результат: %d\n\n");
    }

    fclose(inputFile);

    return 0;
}