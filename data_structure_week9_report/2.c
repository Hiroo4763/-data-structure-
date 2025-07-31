#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // ťŸ��
	element  data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(const char* message) // �����Լ�
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) // ������°����Լ�
{
	q->front = q->rear = 0;
}
 
int is_empty(QueueType* q) // ������°����Լ�
{
	return (q->front == q->rear);
}

int is_full(QueueType* q) // ��ȭ���°����Լ�
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) // �����Լ�
{
	if (is_full(q))
		error("ť����ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) // �����Լ�
{
	if (is_empty(q))
		error("ť����������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int fibonacci(int n) { // �Ǻ���ġ ���� ��� (ť ���)
	if (n == 0) return 0;
	if (n == 1) return 1;

	QueueType q;
	init_queue(&q);

	enqueue(&q, 0);  // F(0)
	enqueue(&q, 1);  // F(1)

	int i, a, b, c;
	for (i = 2; i <= n; i++) {
		a = dequeue(&q);
		b = dequeue(&q);
		c = a + b;
		enqueue(&q, b); // F(n-1)
		enqueue(&q, c); // F(n)
	}

	return c;
}

int main() {
	int n;
	printf("�Ǻ���ġ ���� �Է��Ͻÿ� : ");
	scanf_s("%d", &n);

	printf("%d��° �Ǻ���ġ ���� %d�Դϴ�.\n", n, fibonacci(n));
	return 0;
}