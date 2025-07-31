#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} SortedList;

void init(SortedList* list) {
    list->head = NULL;
}

int is_empty(SortedList* list) {
    return list->head == NULL;
}

void add(SortedList* list, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (list->head == NULL || list->head->data >= value) {
        new_node->next = list->head;
        list->head = new_node;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

// 리스트에서 특정 값 삭제
int delete(SortedList* list, int value) {
    Node* current = list->head;
    Node* prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return 0;  

    if (prev == NULL) {
        list->head = current->next;
    }
    else {
        prev->next = current->next;
    }

    free(current);
    return 1;
}

void clear(SortedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
}

int is_in_list(SortedList* list, int value) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == value)
            return 1;
        current = current->next;
    }
    return 0;
}

int get_len(SortedList* list) {
    int count = 0;
    Node* current = list->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void display(SortedList* list) {
    Node* current = list->head;
    if (current == NULL) {
        printf("리스트가 공백 상태입니다.\n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    puts("");
}

int main() {
    SortedList list;
    init(&list);

    printf("리스트 생성됨.(초기상태 = NULL)\n");
    printf("공백 상태입니다.\n");

    int values[] = { 40, -20, 60, 40, 15, 80, 15 };
    int n = sizeof(values) / sizeof(values[0]);

    printf("%d개의 원소를 삽입합니다.\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d번째 원소 : %d\n", i, values[i]);
        add(&list, values[i]);
    }

    printf("리스트의 길이를 출력합니다. %d\n", get_len(&list));
    printf("리스트의 모든 요소를 출력합니다.\n");
    display(&list);

    int search = 30;
    printf("리스트에 존재하는지 조사할 숫자 : %d\n", search);
    printf("%s\n", is_in_list(&list, search) ? "있음" : "없음");

    int to_delete = 50;
    printf("리스트의 원소 중 제거하고 싶은 숫자 : %d\n", to_delete);
    if (delete(&list, to_delete))
        printf("제거하였습니다.\n");
    else
        printf("제거되지 않았습니다.\n");

    printf("리스트의 모든 요소를 출력합니다.\n");
    display(&list);

    printf("남아있는 원소의 개수는 %d개입니다.\n", get_len(&list));

    printf("리스트의 모든 요소를 모두 제거하겠습니다.\n");
    clear(&list);

    printf("리스트에 남아있는 원소를 출력합니다.\n");
    display(&list);

    return 0;
}
