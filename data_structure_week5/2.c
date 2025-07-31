#include <stdio.h>

#define MAX_STACK_SIZE 100  

int stack[MAX_STACK_SIZE];  // 스택을 배열로 구현
typedef int element;  // 스택에 저장할 데이터의 타입을 정의

typedef struct {
	element data[MAX_STACK_SIZE];  // 스택의 데이터 배열
	int top;
}StackType;

StackType s;  

void init_stack() {
	s.top = -1;  // 스택이 비어 있을 때 top은 -1로 설정
}

int is_empty() {
	return (s.top == -1);  // 스택이 비었으면 1, 아니면 0 반환
}

int is_full() {
	return (s.top == MAX_STACK_SIZE - 1);  // 스택이 가득 차면 1, 아니면 0 반환
}

int peek() {
	if (is_empty()) {
		printf("스택이 비어 있습니다.\n");
		return -1;  // 오류가 발생했을 때 -1 반환
	}
	return s.data[s.top];  // top 위치의 데이터를 반환
}

void push(element item) {
	if (is_full()) {  // 스택이 가득 차면 에러 메시지 출력
		printf("스택이 가득 찼습니다.\n");
		return;
	}
	else s.data[++s.top] = item;  // top을 하나 증가시켜서 새로운 위치로 이동하고 데이터 삽입
}

int pop() {
	if (is_empty()) {  // 스택이 비어 있으면 에러 메시지 출력
		printf("스택이 비어 있습니다.\n");
		return -1;  // 오류가 발생했을 때 -1 반환
	}
	else return s.data[s.top--];  // top 위치의 데이터를 반환하고 top을 하나 감소시킴
}

int main() {
	StackType s;

	init_stack(&s); 
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	return 0;

}