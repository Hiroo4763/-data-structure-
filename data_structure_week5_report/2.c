#include <stdio.h>
#include <string.h> // strlen 함수 사용을 위한 헤더 파일 추가

#define MAX_STACK_SIZE 100 // 스택의 최대 크기 정의

typedef char element; // 스택에 저장할 데이터 형식을 char로 정의

// 스택 구조체 정의
typedef struct {
    char data[MAX_STACK_SIZE]; // 요소들을 저장할 배열
    int top;                      // 스택의 top을 나타내는 인덱스
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s) {
    s->top = -1; // top을 -1로 초기화하여 빈 스택 상태로 설정
}

// 스택이 비어있는지 확인
int is_empty(StackType* s) {
    return (s->top == -1);
}

// 스택이 가득 찼는지 확인
int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
    if (is_full(s))
    {
        printf("Stack overflow error\n");
        return;
    }
    s->data[++(s->top)] = item;
    printf("PUSH: %c -> 현재 스택: ", item);
    for (int i = 0; i <= s->top; i++)
        printf("%c ", s->data[i]);
    printf("\n");
}

// 삭제
element pop(StackType* s)
{
    if (is_empty(s))
    {
        printf("Stack underflow error\n");
        return -1;
    }
    element popped = s->data[(s->top)--];
    printf("POP: %c -> 현재 스택: ", popped);
    for (int i = 0; i <= s->top; i++)
        printf("%c ", s->data[i]);
    if (s->top == -1) printf("(비어있음)");
    printf("\n");
    return popped;
}

// 스택의 최상단 요소를 확인 (peek)
char peek(StackType* s) {
    if (is_empty(s)) {
        printf("스택이 비어있습니다!\n");
        return -1; // 오류 시 -1 반환
    }
    return s->data[s->top]; // top 위치의 데이터 반환
}

// 괄호가 올바르게 짝지어졌는지 확인하는 함수
int check_matching(const char* expr) {
    StackType s;
    char ch, open_ch;
    int i, n = strlen(expr);

    init_stack(&s); // 스택 초기화

    for (i = 0; i < n; i++) {
        ch = expr[i];

        switch (ch) {
            // 여는 괄호는 스택에 push
        case '(':
        case '[':
        case '{':
            push(&s, ch);
            break;

            // 닫는 괄호가 나올 경우
        case ')':
        case ']':
        case '}':
            if (is_empty(&s)) // 스택이 비어 있으면 오류
                return 0;

            open_ch = pop(&s); // 스택에서 여는 괄호 꺼냄
            // 괄호 쌍이 일치하지 않으면 오류
            if ((open_ch == '(' && ch != ')') ||
                (open_ch == '[' && ch != ']') ||
                (open_ch == '{' && ch != '}')) {
                return 0;
            }
            break;
        }
    }

    return is_empty(&s); // 모든 괄호가 짝지어졌다면 스택이 비어 있어야 함
}

// 메인 함수: 예제 문자열로 괄호 검사 실행
int main(void) {
    cochar* expr = "{ A[(i+1)]=0; }";

    if (check_matching(expr))
        printf("\"%s\" 괄호 검사 성공\n", expr);
    else
        printf("\"%s\" 괄호 검사 실패\n", expr);

    return 0;
}