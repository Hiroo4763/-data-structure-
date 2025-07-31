#include <stdio.h>
#define ROWS 3
#define COLS 3

// 단위 행렬 만드는 함수
void make_identity_matrix(int A[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (r == c)
                A[r][c] = 1; // 주대각선 값은 1로 설정
            else
                A[r][c] = 0; // 나머지 값은 0으로 설정
        }
    }
}

// 행렬 출력 함수
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
    int array1[ROWS][COLS] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };  // 3x3 행렬 (초기값 0)

    // 단위 행렬 만들기
    make_identity_matrix(array1);

    // 결과 출력
    printf("A의 단위 행렬:\n");
    matrix_print(array1);

    return 0;
}
