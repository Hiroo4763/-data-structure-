#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* current, DListNode* phead)
{
	DListNode* p;
	for (p = current; p != phead; p = p->rlink) {
		printf("<-| |%s| |->", p->data);
	}
	printf("\n");
}

void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	strcpy(newnode->data, data);
	newnode->rlink = before->rlink;
	newnode->llink = before;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}	

int main(void)
{
	char ch;
	DListNode* current;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	dinsert(head, "Mamamia");
	dinsert(head, "Dancing Queen");
	dinsert(head, "Fernando");

	current = head->rlink;
	print_dlist(current, head);

	do {
		printf("\n명령어를 입력하시오(<,>,q): ");
		ch = getchar();
		if (ch == '<') {
			current = current->llink;
			if (current == head) {
				current = current->rlink;
			}
		}
		else if (ch == '>') {
			current = current->rlink;
			if (current == head) {
				current = current->llink;
			}
		}
		print_dlist(current, head);
		getchar();
	} while (ch != 'q');
}