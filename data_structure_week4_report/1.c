#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101  // ��� ��Ŀ��� ������ �� �ִ� �ִ� �� ����

// ���� ���Ҹ� �����ϴ� ����ü
typedef struct {
    int row;    // ������ �� ��ȣ
    int col;    // ������ �� ��ȣ
    int value;  // ������ �� (0�� �ƴ� ���� ����)
} element;

// ��� ����� ǥ���ϴ� ����ü
typedef struct SparseMatrix {
    element data[MAX_TERMS]; // 0�� �ƴ� ���� ������ �迭
    int rows;   // �� ����
    int cols;   // �� ����
    int terms;  // 0�� �ƴ� ���� ����
} SparseMatrix;

// ��� ����� ��ġ�ϴ� �Լ�
SparseMatrix matrix_transpose2(SparseMatrix a) {
    SparseMatrix b;
    int bindex;  // ���ο� ��Ŀ��� ���� ������ ��ġ
    b.rows = a.cols;  // ��ġ �� ��� ���� �ٲ�
    b.cols = a.rows;
    b.terms = a.terms; // 0�� �ƴ� ����� ������ ������ ����

    if (a.terms > 0) {  // 0�� �ƴ� ��Ұ� ���� ��쿡�� ����
        bindex = 0;

        // ���� �������� ���� ������� ��ġ ���� ����
        for (int c = 0; c < a.cols; c++) {
            for (int i = 0; i < a.terms; i++) {
                if (a.data[i].col == c) { // �ش��ϴ� ��� ã��
                    b.data[bindex].row = a.data[i].col;  // ��� �� ��ġ ����
                    b.data[bindex].col = a.data[i].row;
                    b.data[bindex].value = a.data[i].value;
                    bindex++; // ���� ��� ��ġ �̵�
                }
            }
        }
    }
    return b; // ��ġ�� ��� ��� ��ȯ
}

// ��� ����� ����ϴ� �Լ�
void matrix_print(SparseMatrix a) {
    printf("====================\n");
    for (int i = 0; i < a.terms; i++) {
        printf("%d %d %d\n", a.data[i].row, a.data[i].col, a.data[i].value);
    }
    printf("====================\n");
}

int main(void) {
    // �׽�Ʈ�� ��� ��� ����
    SparseMatrix m = {
        { {0,3,7}, {1,0,9}, {1,5,8}, {3,0,6}, {3,1,5}, {4,5,1}, {5,2,2} },
        6, // ���� ����
        6, // ���� ����
        7  // 0�� �ƴ� ��� ����
    };

    SparseMatrix result;  // ��ġ�� ����� ������ ����

    result = matrix_transpose2(m);  // ��ġ ���� ����
    matrix_print(result);  // ��� ���

    return 0;
}