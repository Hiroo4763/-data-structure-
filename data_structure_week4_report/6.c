#include <stdio.h>
#define n 100 // �迭�� ũ��
int items = 7; // �迭�� �׸� ���� 

// �迭�� ������ �����ϴ� �Լ�
void insert(int array[], int loc, int value) { // �迭, ������ ��ġ, ������ ��
	for (int i = items; i >= loc; i--) { // �迭�� ������ ������ ��ġ����
		array[i + 1] = array[i]; // �� ĭ�� �ڷ� �̵�
    }
	array[loc] = value; // ������ ��ġ�� �� ����
	items++; // �׸� ���� ����
}

int main() {
    int array[n] = { 1, 2, 3, 4, 5, 6, 7}; 
	int loc, value;

    printf("���� �迭: "); // ���� �迭 ���
    for (int i = 0; i < items; i++) {
        printf("%d ", array[i]);
    }

	printf("������ ��ġ(loc)�� ��: "); // ������ ��ġ�� �� �Է�
	scanf_s("%d %d", &loc, &value);
	insert(array, loc, value); // ���� �Լ� ȣ��

    printf("���� �� �迭: "); // ����� �迭 ���
    for (int i = 0; i < items; i++) {
        printf("%d ", array[i]);
    }


    return 0;
}