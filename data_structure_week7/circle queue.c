#include <stdio.h>
#include <stdlib.h>
// ===== 원형큐코드시작======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct{ // 큐타입
element  data[MAX_QUEUE_SIZE];
 int front, rear;
} QueueType;
// 오류함수
void error(const char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 공백상태검출함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
// 공백상태검출함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
// 포화상태검출함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 원형큐출력함수
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
		} while (i != q->rear);
	}
	printf("\n");
}
// 삽입함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
// 삭제함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
int main(void)
{
	QueueType queue;
	int element;
	init_queue(&queue);
	printf("--데이터추가단계--\n");
	while (!is_full(&queue))
	{
		printf("정수를입력하시오: ");
		scanf_s("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("큐는포화상태입니다.\n\n");
	printf("--데이터삭제단계--\n");
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("꺼내진정수: %d \n", element);
		queue_print(&queue);
	}
	printf("큐는공백상태입니다.\n");
	return 0;
}