#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100 // ť�� �ִ�ũ��

typedef int element; // �����Ÿ��
typedef struct QueueNode { // ť�� ����� Ÿ��
	element data;
	struct QueueNode* link;
} QueueNode;
typedef struct {
	// ťADT ����
	QueueNode* front, * rear;
} LinkedQueueType;

// ���� ó�� �Լ�
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ť �ʱ�ȭ �Լ�
void init(LinkedQueueType* q) {
	q->front = NULL;
	q->rear = NULL;
}

// ť�� ����ִ��� Ȯ��
int is_empty(LinkedQueueType* q) {
	return (q->front == NULL);
}

// ť�� ���� á���� Ȯ�� (���� ����Ʈ�� ��ȭ ����)
int is_full(LinkedQueueType* q) {
	return 0;
}

// ť�� ������ ���
void print_queue(LinkedQueueType* q) {
	QueueNode* p;
	for (p = q->front; p != NULL; p = p->link)
		printf("%d -> ", p->data);
	printf("NULL\n");
}

//�����Լ�
void enqueue(LinkedQueueType* q, element data)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data; //����������
	temp->link = NULL; //��ũ�ʵ带NULL
	if (is_empty(q)) { //ť�������̸�
		q->front = temp;
		q->rear = temp;
	}
	else { //ť�������̾ƴϸ�
		q->rear->link = temp; //�������߿�
		q->rear = temp;
	}
}

//�����Լ�
element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element data;
	if (is_empty(q)) { //�������
		fprintf(stderr, "ť�� �������\n");
		exit(1);
	}
	else {
		data = temp->data; //�����͸�������.
		q->front = q->front->link;//front�δ������
		if (q->front == NULL) //�������
			q->rear = NULL;
		free(temp); //�����޸�����
		return data; //�����͹�ȯ
	}
}

int main()
{
	LinkedQueueType q;
	init(&q); //ť�ʱ�ȭ
	enqueue(&q, 1); //ť������
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);
	print_queue(&q); //ť���
	printf("dequeue: %d\n", dequeue(&q)); //ť��������
	print_queue(&q); //ť���
	return 0;
}