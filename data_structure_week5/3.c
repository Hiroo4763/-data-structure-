#include <stdio.h>

#define MAX_STACK_SIZE 100
typedef int element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    if (s->top == -1) {
        return 1;
    }
    return 0;
}

int is_full(StackType* s) {
    if (s->top == MAX_STACK_SIZE - 1) {
        return 1;
    }
    return 0;
}

void push(StackType* s, element item) {
    if (is_full(s)) {
        printf("스택이 가득 찼습니다.\n");
        return;
    }
    s->top++;
    s->data[s->top] = item;
}

element pop(StackType* s) {
    if (is_empty(s)) {
        printf("스택이 비어 있습니다.\n");
        return -1;
    }
    return s->data[s->top--];
}

element peek(StackType* s) {
    if (is_empty(s)) {
        printf("스택이 비어 있습니다.\n");
        return -1;
    }
    return s->data[s->top];
}

int main() {
    StackType stack;
    init_stack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("pop: %d\n", pop(&stack));
    printf("pop: %d\n", pop(&stack));
    printf("pop: %d\n", pop(&stack));
    printf("pop: %d\n", pop(&stack));

    return 0;
}