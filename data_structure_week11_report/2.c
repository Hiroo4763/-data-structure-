#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100 // 큐의 최대크기

typedef int element; // 요소의타입
typedef struct QueueNode { // 큐의 노드의 타입
	element data;
	struct QueueNode* link;
} QueueNode;
typedef struct {
	// 큐ADT 구현
	QueueNode* front, * rear;
} LinkedQueueType;

// 오류 처리 함수
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 큐 초기화 함수
void init(LinkedQueueType* q) {
	q->front = NULL;
	q->rear = NULL;
}

// 큐가 비어있는지 확인
int is_empty(LinkedQueueType* q) {
	return (q->front == NULL);
}

// 큐가 가득 찼는지 확인 (연결 리스트는 포화 없음)
int is_full(LinkedQueueType* q) {
	return 0;
}

// 큐의 내용을 출력
void print_queue(LinkedQueueType* q) {
	QueueNode* p;
	for (p = q->front; p != NULL; p = p->link)
		printf("%d -> ", p->data);
	printf("NULL\n");
}

//삽입함수
void enqueue(LinkedQueueType* q, element data)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data; //데이터저장
	temp->link = NULL; //링크필드를NULL
	if (is_empty(q)) { //큐가공백이면
		q->front = temp;
		q->rear = temp;
	}
	else { //큐가공백이아니면
		q->rear->link = temp; //순서가중요
		q->rear = temp;
	}
}

//삭제함수
element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element data;
	if (is_empty(q)) { //공백상태
		fprintf(stderr, "큐가 비어있음\n");
		exit(1);
	}
	else {
		data = temp->data; //데이터를꺼낸다.
		q->front = q->front->link;//front로다음노드
		if (q->front == NULL) //공백상태
			q->rear = NULL;
		free(temp); //동적메모리해제
		return data; //데이터반환
	}
}

int main()
{
	LinkedQueueType q;
	init(&q); //큐초기화
	enqueue(&q, 1); //큐에삽입
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);
	print_queue(&q); //큐출력
	printf("dequeue: %d\n", dequeue(&q)); //큐에서삭제
	print_queue(&q); //큐출력
	return 0;
}