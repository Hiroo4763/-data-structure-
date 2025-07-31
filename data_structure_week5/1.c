#include <stdio.h>

#define MAX_STACK_SIZE 100  

int stack[MAX_STACK_SIZE];  // 스택을 배열로 구현
int top;

void init_stack() {
	top = -1;  // 스택이 비어 있을 때 top은 -1로 설정
}

int is_empty() {
	return (top == -1);  // 스택이 비었으면 1, 아니면 0 반환
}

int is_full() {
	return (top == MAX_STACK_SIZE - 1);  // 스택이 가득 차면 1, 아니면 0 반환
}

int peek() {
	if (is_empty()) {
		printf("스택이 비어 있습니다.\n");
		return -1;  // 오류가 발생했을 때 -1 반환
	}
	return stack[top];  // top 위치의 데이터를 반환
}

void push(int element) {
	if (is_full()) {  // 스택이 가득 차면 에러 메시지 출력
		printf("스택이 가득 찼습니다.\n");
		return;
	}
	stack[++top]=element ;  // top을 하나 증가시켜서 새로운 위치로 이동하고 데이터 삽입
}

int pop() {
	if (is_empty()) {  // 스택이 비어 있으면 에러 메시지 출력
		printf("스택이 비어 있습니다.\n");
		return -1;  // 오류가 발생했을 때 -1 반환
	}
	return stack[top--];  // top 위치의 데이터를 반환하고 top을 하나 감소시킴
}	

int main() {

	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	return 0;

}