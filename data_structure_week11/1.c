#include <stdio.h>
#include <stdlib.h>

typedef int element;

// ���� ���� ��� ����
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

// ���� ���� ����Ʈ �ʱ�ȭ �Լ�
void init(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

// ���� ���� ����Ʈ ��� �Լ�
void print_dlist(DListNode* phead) {
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf("<-| |%d| |->", p->data);
    }
    printf("\n");
}

// ���ο� �����͸� ��� before�� �����ʿ� ����
void dinsert(DListNode* before, element data) {
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

// ��� removed�� ����
void ddelete(DListNode* head, DListNode* removed) {
    if (removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

// �׽�Ʈ ���α׷�
int main(void) {
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);

    printf("�߰� �ܰ�\n");
    for (int i = 0; i < 5; i++) {
        dinsert(head, i); // �׻� head �����ʿ� ����
        print_dlist(head);
    }

    printf("\n���� �ܰ�\n");
    for (int i = 0; i < 5; i++) {
        print_dlist(head);
        ddelete(head, head->rlink); // ���� �� ��� ����
    }

    free(head);
    return 0;
}