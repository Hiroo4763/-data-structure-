#include <stdio.h>
#include <string.h> // strlen �Լ� ����� ���� ��� ���� �߰�

#define MAX_STACK_SIZE 100 // ������ �ִ� ũ�� ����

typedef char element; // ���ÿ� ������ ������ ������ char�� ����

// ���� ����ü ����
typedef struct {
    element data[MAX_STACK_SIZE]; // ��ҵ��� ������ �迭
    int top;                      // ������ top�� ��Ÿ���� �ε���
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) {
    s->top = -1; // top�� -1�� �ʱ�ȭ�Ͽ� �� ���� ���·� ����
}

// ������ ����ִ��� Ȯ��
int is_empty(StackType* s) {
    return (s->top == -1);
}

// ������ ���� á���� Ȯ��
int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

// ���ÿ� ��Ҹ� �߰� (push)
void push(StackType* s, element item) {
    if (is_full(s)) {
        printf("������ ����ֽ��ϴ�!\n"); 
        return;
    }
    s->data[++(s->top)] = item; // top�� ������Ű�� ������ ����
}

// ���ÿ��� ��Ҹ� ���� (pop)
element pop(StackType* s) {
    if (is_empty(s)) {
        printf("������ ����ֽ��ϴ�!\n"); 
        return -1; // ���� �� -1 ��ȯ
    }
    return s->data[(s->top)--]; // top ��ġ�� ������ ��ȯ �� top ����
}

// ������ �ֻ�� ��Ҹ� Ȯ�� (peek)
element peek(StackType* s) {
    if (is_empty(s)) {
        printf("������ ����ֽ��ϴ�!\n"); 
        return -1; // ���� �� -1 ��ȯ
    }
    return s->data[s->top]; // top ��ġ�� ������ ��ȯ
}

// ��ȣ�� �ùٸ��� ¦���������� Ȯ���ϴ� �Լ�
int check_matching(const char* expr) {
    StackType s;
    element ch, open_ch;
    int i, n = strlen(expr);

    init_stack(&s); // ���� �ʱ�ȭ

    for (i = 0; i < n; i++) {
        ch = expr[i];

        switch (ch) {
            // ���� ��ȣ�� ���ÿ� push
        case '(':
        case '[':
        case '{':
            push(&s, ch);
            break;

            // �ݴ� ��ȣ�� ���� ���
        case ')':
        case ']':
        case '}':
            if (is_empty(&s)) // ������ ��� ������ ����
                return 0;

            open_ch = pop(&s); // ���ÿ��� ���� ��ȣ ����
            // ��ȣ ���� ��ġ���� ������ ����
            if ((open_ch == '(' && ch != ')') ||
                (open_ch == '[' && ch != ']') ||
                (open_ch == '{' && ch != '}')) {
                return 0;
            }
            break;
        }
    }

    return is_empty(&s); // ��� ��ȣ�� ¦�������ٸ� ������ ��� �־�� ��
}

// ���� �Լ�: ���� ���ڿ��� ��ȣ �˻� ����
int main(void) {
    const char* expr = "{ A[(i+1)]=0; }";

    if (check_matching(expr))
        printf("\"%s\" ��ȣ �˻� ����\n", expr);
    else
        printf("\"%s\" ��ȣ �˻� ����\n", expr);

    return 0;
}