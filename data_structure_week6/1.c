#include <stdio.h>

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct
{
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// ���� �ʱ�ȭ�Լ�
void init_stack(StackType *s)
{
    s->top = -1; // s->top = -1;
}

// ���� ���°����Լ�
int is_empty(StackType* s)
{
    return (s->top == -1);
}
// ��ȭ ���°����Լ�
int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

// �����Լ�
void push(StackType* s, element item)
{
    if (is_full(s)){
        fprintf(stderr, "������ȭ����\n");
        return;
    }
    else
        s->data[++(s->top)] = item;
}

// �����Լ�
element pop(StackType* s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "���ð��鿡��\n");
        //exit(1);
    }
    else
        return s->data[(s->top)--];
}

// ��ũ �Լ� (������ �� �� ������ Ȯ��)
element peek(StackType* s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "���� ���� ����\n");
        //exit(1);
    }
    return s->data[s->top];  // ������ top ��ġ �� ��ȯ (������ �� ��)
}



int main(void)
{
    StackType s;
    init_stack(&s);
	printf("init()�Լ��� top�� ��ġ %d\n", s.top);
    push(&s, 1), printf("%d\n", s.data[s.top]);
    push(&s, 2), printf("%d\n", s.data[s.top]);
    push(&s, 3), printf("%d\n", s.data[s.top]);

    printf("struct stack\npeek: %d\n", peek(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
}