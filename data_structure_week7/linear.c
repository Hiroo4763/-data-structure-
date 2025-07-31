#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5 // 큐의 최대 크기를 5로 정의

typedef int element; // element 타입을 int로 정의

// 큐 타입 정의
typedef struct {
	int front; // 큐의 시작 인덱스
	int rear;  // 큐의 끝 인덱스
	element data[MAX_QUEUE_SIZE]; // 큐의 요소를 저장할 배열
} QueueType;

// 오류 발생 시 메시지를 출력하고 프로그램 종료
void error(const char* message)
{
	fprintf(stderr, "%s\n", message); // 에러 메시지 출력
	exit(1); // 프로그램 종료
}

// 큐를 초기화하는 함수
void init_queue(QueueType* q)
{
	q->rear = -1; // rear 초기화
	q->front = -1; // front 초기화
}

// 큐의 현재 상태를 출력하는 함수
void queue_print(QueueType* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("   | "); // 비어있는 칸
		else
			printf("%3d | ", q->data[i]); // 데이터가 있는 칸
	}
	printf("\n");
}

// 큐가 포화 상태인지 검사하는 함수
int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1) // rear가 마지막 인덱스에 도달했는지 확인
		return 1;
	else
		return 0;
}

// 큐가 공백 상태인지 검사하는 함수
int is_empty(QueueType* q)
{
	if (q->front == q->rear) // front와 rear가 같으면 큐가 비어있음
		return 1;
	else
		return 0;
}

// 큐에 요소를 삽입하는 함수
void enqueue(QueueType* q, int item)
{
	if (is_full(q)) { // 큐가 포화 상태이면
		error("큐가포화상태입니다."); // 에러 발생
		return;
	}
	q->data[++(q->rear)] = item; // rear를 증가시키고 item을 삽입
}

// 큐에서 요소를 삭제하고 반환하는 함수
int dequeue(QueueType* q)
{
	if (is_empty(q)) { // 큐가 비어있으면
		error("큐가공백상태입니다."); // 에러 발생
		return -1;
	}
	int item = q->data[++(q->front)]; // front를 증가시키고 요소 반환
	return item;
}

int main(void)
{
	int item = 0;
	QueueType q;
	init_queue(&q); // 큐 초기화
	enqueue(&q, 10); queue_print(&q); // 10 삽입 후 출력
	enqueue(&q, 20); queue_print(&q); // 20 삽입 후 출력
	enqueue(&q, 30); queue_print(&q); // 30 삽입 후 출력
	item = dequeue(&q); queue_print(&q); // 삭제 후 출력
	item = dequeue(&q); queue_print(&q); // 삭제 후 출력
	item = dequeue(&q); queue_print(&q); // 삭제 후 출력
	return 0;
}