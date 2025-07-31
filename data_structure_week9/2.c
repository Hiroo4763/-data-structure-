#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
void printfList(struct NodeList* head);

typedef int element;
struct NodeList {
	element data;
	struct NodeList* next;
};

int main()
{
	struct NodeList* head = NULL;
	struct NodeList* node;
	node = (struct NodeList*)malloc(sizeof(struct NodeList));
	node->data = 10;
	node->next = head;
	head = node;

	node = (struct NodeList*)malloc(sizeof(struct NodeList));
	node->data = 20;
	node->next = head;
	head = node;

	node = (struct NodeList*)malloc(sizeof(struct NodeList));
	node->data = 30;
	node->next = head;
	head = node;

	printfList(head);
}

void printfList(struct NodeList* head)
{
	struct NodeList* p = head;
	while (p != NULL) {
		printf("%d=> ", p->data);
		p = p->next;
	}
	printf("\n");
}