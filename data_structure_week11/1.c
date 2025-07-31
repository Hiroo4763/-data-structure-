#include <stdio.h>
#include <stdlib.h>

typedef int element;

// 이중 연결 노드 구조
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

// 이중 연결 리스트 초기화 함수
void init(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

// 이중 연결 리스트 출력 함수
void print_dlist(DListNode* phead) {
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf("<-| |%d| |->", p->data);
    }
    printf("\n");
}

// 새로운 데이터를 노드 before의 오른쪽에 삽입
void dinsert(DListNode* before, element data) {
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

// 노드 removed를 삭제
void ddelete(DListNode* head, DListNode* removed) {
    if (removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

// 테스트 프로그램
int main(void) {
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);

    printf("추가 단계\n");
    for (int i = 0; i < 5; i++) {
        dinsert(head, i); // 항상 head 오른쪽에 삽입
        print_dlist(head);
    }

    printf("\n삭제 단계\n");
    for (int i = 0; i < 5; i++) {
        print_dlist(head);
        ddelete(head, head->rlink); // 가장 앞 노드 삭제
    }

    free(head);
    return 0;
}