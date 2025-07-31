#include <stdio.h>

#define MAX_STACK_SIZE 100  

int stack[MAX_STACK_SIZE];  // ������ �迭�� ����
int top;

void init_stack() {
	top = -1;  // ������ ��� ���� �� top�� -1�� ����
}

int is_empty() {
	return (top == -1);  // ������ ������� 1, �ƴϸ� 0 ��ȯ
}

int is_full() {
	return (top == MAX_STACK_SIZE - 1);  // ������ ���� ���� 1, �ƴϸ� 0 ��ȯ
}

int peek() {
	if (is_empty()) {
		printf("������ ��� �ֽ��ϴ�.\n");
		return -1;  // ������ �߻����� �� -1 ��ȯ
	}
	return stack[top];  // top ��ġ�� �����͸� ��ȯ
}

void push(int element) {
	if (is_full()) {  // ������ ���� ���� ���� �޽��� ���
		printf("������ ���� á���ϴ�.\n");
		return;
	}
	stack[++top]=element ;  // top�� �ϳ� �������Ѽ� ���ο� ��ġ�� �̵��ϰ� ������ ����
}

int pop() {
	if (is_empty()) {  // ������ ��� ������ ���� �޽��� ���
		printf("������ ��� �ֽ��ϴ�.\n");
		return -1;  // ������ �߻����� �� -1 ��ȯ
	}
	return stack[top--];  // top ��ġ�� �����͸� ��ȯ�ϰ� top�� �ϳ� ���ҽ�Ŵ
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