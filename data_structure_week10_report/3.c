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

// ����Ʈ���� Ư�� �� ����
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
        printf("����Ʈ�� ���� �����Դϴ�.\n");
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

    printf("����Ʈ ������.(�ʱ���� = NULL)\n");
    printf("���� �����Դϴ�.\n");

    int values[] = { 40, -20, 60, 40, 15, 80, 15 };
    int n = sizeof(values) / sizeof(values[0]);

    printf("%d���� ���Ҹ� �����մϴ�.\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d��° ���� : %d\n", i, values[i]);
        add(&list, values[i]);
    }

    printf("����Ʈ�� ���̸� ����մϴ�. %d\n", get_len(&list));
    printf("����Ʈ�� ��� ��Ҹ� ����մϴ�.\n");
    display(&list);

    int search = 30;
    printf("����Ʈ�� �����ϴ��� ������ ���� : %d\n", search);
    printf("%s\n", is_in_list(&list, search) ? "����" : "����");

    int to_delete = 50;
    printf("����Ʈ�� ���� �� �����ϰ� ���� ���� : %d\n", to_delete);
    if (delete(&list, to_delete))
        printf("�����Ͽ����ϴ�.\n");
    else
        printf("���ŵ��� �ʾҽ��ϴ�.\n");

    printf("����Ʈ�� ��� ��Ҹ� ����մϴ�.\n");
    display(&list);

    printf("�����ִ� ������ ������ %d���Դϴ�.\n", get_len(&list));

    printf("����Ʈ�� ��� ��Ҹ� ��� �����ϰڽ��ϴ�.\n");
    clear(&list);

    printf("����Ʈ�� �����ִ� ���Ҹ� ����մϴ�.\n");
    display(&list);

    return 0;
}
