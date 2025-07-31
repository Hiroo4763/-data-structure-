#include <stdio.h>

#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return s->top == -1;
}

void push(StackType* s, element item) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->top++;
        s->data[s->top] = item;
    }
}

element pop(StackType* s) {
    if (is_empty(s)) {
        return '\0';
    }
    return s->data[s->top--];
}

int check_matching(const char* expr) {
    StackType stack;
    init_stack(&stack);

    int i = 0;
    char ch, open_ch;

    while (expr[i] != '\0') {
        ch = expr[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            push(&stack, ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (is_empty(&stack)) {
                return 0;
            }
            open_ch = pop(&stack);

            if ((open_ch == '(' && ch != ')') ||
                (open_ch == '[' && ch != ']') ||
                (open_ch == '{' && ch != '}')) {
                return 0;
            }
        }
        i++;
    }

    if (!is_empty(&stack)) {
        return 0;
    }

    return 1;
}

int main(void) {
    char* p = "{ A[(i+1)]=0; } ";
    if (check_matching(p) == 1) {
        printf("%s 괄호검사성공\n", p);
    }
    else {
        printf("%s 괄호검사실패\n", p);
    }

    return 0;
}