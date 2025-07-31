#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100  // 스택 최대 크기 정의

typedef int element;  // 스택에 저장될 데이터 타입 정의
typedef struct
{
    element data[MAX_STACK_SIZE];  // 정적 배열로 스택 구현
    int top;  // 스택의 최상위 인덱스
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
    s->top = -1;  // top을 -1로 초기화하여 공백 상태로 설정
}

// 스택이 비었는지 확인하는 함수
int is_empty(StackType* s)
{
    return (s->top == -1);
}

// 스택이 가득 찼는지 확인하는 함수
int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

// 스택에 데이터를 삽입하는 함수 (push)
void push(StackType* s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else
        s->data[++(s->top)] = item;  // top을 증가시키고 데이터 저장
}

// 스택에서 데이터를 꺼내는 함수 (pop)
element pop(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);  // 오류 발생 시 종료
    }
    else
        return s->data[(s->top)--];  // top의 값 반환 후 감소
}

// 스택의 top 값을 확인하는 함수 (peek)
element peek(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[s->top];
}

// 연산자의 우선순위를 반환하는 함수
int prec(char op)
{
    switch (op)
    {
    case '(': case ')': return 0;          // 괄호는 가장 낮은 우선순위
    case '+': case '-': return 1;          // 덧셈, 뺄셈 우선순위 1
    case '*': case '/': return 2;          // 곱셈, 나눗셈 우선순위 2
    }
    return -1;  // 예외 처리
}

// 중위 표기식을 후위 표기식으로 변환하는 함수
int infix_to_postfix(char exp[])
{
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;

    init_stack(&s);  // 스택 초기화

    for (i = 0; i < len; i++) {
        ch = exp[i];
        switch (ch) {
        case '+': case '-': case '*': case '/': // 연산자일 경우
            // 스택에 있는 연산자의 우선순위가 현재 연산자보다 크거나 같으면 출력
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
                printf("%c", pop(&s));  // 스택에서 pop하며 출력
            push(&s, ch);  // 현재 연산자는 push
            break;
        case '(':  // 왼쪽 괄호는 무조건 push
            push(&s, ch);
            break;
        case ')':  // 오른쪽 괄호일 경우
            top_op = pop(&s);
            // 왼쪽 괄호를 만날 때까지 출력
            while (top_op != '(') {
                printf("%c", top_op);
                top_op = pop(&s);
            }
            break;
        default:  // 피연산자인 경우 바로 출력
            printf("%c", ch);
            break;
        }
    }
    // 스택에 남은 연산자들 모두 출력
    while (!is_empty(&s))
        printf("%c", pop(&s));
}

int main(void)
{
    char* s = "(2+3)*4+9";  // 예시 중위 수식
    printf("중위표시수식 %s \n", s);
    printf("후위표시수식 ");
    infix_to_postfix(s);  // 후위표기식 변환 함수 호출
    printf("\n");
    return 0;
}