#include <stdio.h>

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct
{
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// 스택 초기화함수
void init_stack(StackType *s)
{
    s->top = -1; // s->top = -1;
}

// 공백 상태검출함수
int is_empty(StackType* s)
{
    return (s->top == -1);
}
// 포화 상태검출함수
int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입함수
void push(StackType* s, element item)
{
    if (is_full(s)){
        fprintf(stderr, "스택포화에러\n");
        return;
    }
    else
        s->data[++(s->top)] = item;
}

// 삭제함수
element pop(StackType* s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택공백에러\n");
        //exit(1);
    }
    else
        return s->data[(s->top)--];
}

// 피크 함수 (스택의 맨 위 데이터 확인)
element peek(StackType* s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        //exit(1);
    }
    return s->data[s->top];  // 스택의 top 위치 값 반환 (삭제는 안 함)
}



int main(void)
{
    StackType s;
    init_stack(&s);
	printf("init()함수의 top의 위치 %d\n", s.top);
    push(&s, 1), printf("%d\n", s.data[s.top]);
    push(&s, 2), printf("%d\n", s.data[s.top]);
    push(&s, 3), printf("%d\n", s.data[s.top]);

    printf("struct stack\npeek: %d\n", peek(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
}