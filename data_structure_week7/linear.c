#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5 // ť�� �ִ� ũ�⸦ 5�� ����

typedef int element; // element Ÿ���� int�� ����

// ť Ÿ�� ����
typedef struct {
	int front; // ť�� ���� �ε���
	int rear;  // ť�� �� �ε���
	element data[MAX_QUEUE_SIZE]; // ť�� ��Ҹ� ������ �迭
} QueueType;

// ���� �߻� �� �޽����� ����ϰ� ���α׷� ����
void error(const char* message)
{
	fprintf(stderr, "%s\n", message); // ���� �޽��� ���
	exit(1); // ���α׷� ����
}

// ť�� �ʱ�ȭ�ϴ� �Լ�
void init_queue(QueueType* q)
{
	q->rear = -1; // rear �ʱ�ȭ
	q->front = -1; // front �ʱ�ȭ
}

// ť�� ���� ���¸� ����ϴ� �Լ�
void queue_print(QueueType* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("   | "); // ����ִ� ĭ
		else
			printf("%3d | ", q->data[i]); // �����Ͱ� �ִ� ĭ
	}
	printf("\n");
}

// ť�� ��ȭ �������� �˻��ϴ� �Լ�
int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1) // rear�� ������ �ε����� �����ߴ��� Ȯ��
		return 1;
	else
		return 0;
}

// ť�� ���� �������� �˻��ϴ� �Լ�
int is_empty(QueueType* q)
{
	if (q->front == q->rear) // front�� rear�� ������ ť�� �������
		return 1;
	else
		return 0;
}

// ť�� ��Ҹ� �����ϴ� �Լ�
void enqueue(QueueType* q, int item)
{
	if (is_full(q)) { // ť�� ��ȭ �����̸�
		error("ť����ȭ�����Դϴ�."); // ���� �߻�
		return;
	}
	q->data[++(q->rear)] = item; // rear�� ������Ű�� item�� ����
}

// ť���� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
int dequeue(QueueType* q)
{
	if (is_empty(q)) { // ť�� ���������
		error("ť����������Դϴ�."); // ���� �߻�
		return -1;
	}
	int item = q->data[++(q->front)]; // front�� ������Ű�� ��� ��ȯ
	return item;
}

int main(void)
{
	int item = 0;
	QueueType q;
	init_queue(&q); // ť �ʱ�ȭ
	enqueue(&q, 10); queue_print(&q); // 10 ���� �� ���
	enqueue(&q, 20); queue_print(&q); // 20 ���� �� ���
	enqueue(&q, 30); queue_print(&q); // 30 ���� �� ���
	item = dequeue(&q); queue_print(&q); // ���� �� ���
	item = dequeue(&q); queue_print(&q); // ���� �� ���
	item = dequeue(&q); queue_print(&q); // ���� �� ���
	return 0;
}