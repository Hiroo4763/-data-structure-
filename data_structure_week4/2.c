#include <stdio.h>
#define ROWS 3
#define COLS 3

// ���� ��� ����� �Լ�
void make_identity_matrix(int A[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (r == c)
                A[r][c] = 1; // �ִ밢�� ���� 1�� ����
            else
                A[r][c] = 0; // ������ ���� 0���� ����
        }
    }
}

// ��� ��� �Լ�
void matrix_print(int A[ROWS][COLS]) {
    printf("====================\n");
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%d ", A[r][c]);
        }
        printf("\n");
    }
    printf("====================\n");
}

int main(void) {
    int array1[ROWS][COLS] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };  // 3x3 ��� (�ʱⰪ 0)

    // ���� ��� �����
    make_identity_matrix(array1);

    // ��� ���
    printf("A�� ���� ���:\n");
    matrix_print(array1);

    return 0;
}
