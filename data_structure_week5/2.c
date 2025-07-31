#include <stdio.h>

#define MAX_STACK_SIZE 100  

int stack[MAX_STACK_SIZE];  // ������ �迭�� ����
typedef int element;  // ���ÿ� ������ �������� Ÿ���� ����

typedef struct {
	element data[MAX_STACK_SIZE];  // ������ ������ �迭
	int top;
}StackType;

StackType s;  

void init_stack() {
	s.top = -1;  // ������ ��� ���� �� top�� -1�� ����
}

int is_empty() {
	return (s.top == -1);  // ������ ������� 1, �ƴϸ� 0 ��ȯ
}

int is_full() {
	return (s.top == MAX_STACK_SIZE - 1);  // ������ ���� ���� 1, �ƴϸ� 0 ��ȯ
}

int peek() {
	if (is_empty()) {
		printf("������ ��� �ֽ��ϴ�.\n");
		return -1;  // ������ �߻����� �� -1 ��ȯ
	}
	return s.data[s.top];  // top ��ġ�� �����͸� ��ȯ
}

void push(element item) {
	if (is_full()) {  // ������ ���� ���� ���� �޽��� ���
		printf("������ ���� á���ϴ�.\n");
		return;
	}
	else s.data[++s.top] = item;  // top�� �ϳ� �������Ѽ� ���ο� ��ġ�� �̵��ϰ� ������ ����
}

int pop() {
	if (is_empty()) {  // ������ ��� ������ ���� �޽��� ���
		printf("������ ��� �ֽ��ϴ�.\n");
		return -1;  // ������ �߻����� �� -1 ��ȯ
	}
	else return s.data[s.top--];  // top ��ġ�� �����͸� ��ȯ�ϰ� top�� �ϳ� ���ҽ�Ŵ
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