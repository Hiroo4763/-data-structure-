#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // 큐타입
	element  data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(const char* message) // 오류함수
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) // 공백상태검출함수
{
	q->front = q->rear = 0;
}
 
int is_empty(QueueType* q) // 공백상태검출함수
{
	return (q->front == q->rear);
}

int is_full(QueueType* q) // 포화상태검출함수
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) // 삽입함수
{
	if (is_full(q))
		error("큐가포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) // 삭제함수
{
	if (is_empty(q))
		error("큐가공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int fibonacci(int n) { // 피보나치 수열 계산 (큐 사용)
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
	printf("피보나치 수를 입력하시오 : ");
	scanf_s("%d", &n);

	printf("%d번째 피보나치 수는 %d입니다.\n", n, fibonacci(n));
	return 0;
}