#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101  // 희소 행렬에서 저장할 수 있는 최대 항 개수

// 개별 원소를 저장하는 구조체
typedef struct {
    int row;    // 원소의 행 번호
    int col;    // 원소의 열 번호
    int value;  // 원소의 값 (0이 아닌 값만 저장)
} element;

// 희소 행렬을 표현하는 구조체
typedef struct SparseMatrix {
    element data[MAX_TERMS]; // 0이 아닌 값을 저장할 배열
    int rows;   // 행 개수
    int cols;   // 열 개수
    int terms;  // 0이 아닌 값의 개수
} SparseMatrix;

// 희소 행렬을 전치하는 함수
SparseMatrix matrix_transpose2(SparseMatrix a) {
    SparseMatrix b;
    int bindex;  // 새로운 행렬에서 값을 삽입할 위치
    b.rows = a.cols;  // 전치 후 행과 열을 바꿈
    b.cols = a.rows;
    b.terms = a.terms; // 0이 아닌 요소의 개수는 변하지 않음

    if (a.terms > 0) {  // 0이 아닌 요소가 있을 경우에만 수행
        bindex = 0;

        // 열을 기준으로 작은 순서대로 전치 연산 수행
        for (int c = 0; c < a.cols; c++) {
            for (int i = 0; i < a.terms; i++) {
                if (a.data[i].col == c) { // 해당하는 요소 찾기
                    b.data[bindex].row = a.data[i].col;  // 행과 열 위치 변경
                    b.data[bindex].col = a.data[i].row;
                    b.data[bindex].value = a.data[i].value;
                    bindex++; // 다음 요소 위치 이동
                }
            }
        }
    }
    return b; // 전치된 희소 행렬 반환
}

// 희소 행렬을 출력하는 함수
void matrix_print(SparseMatrix a) {
    printf("====================\n");
    for (int i = 0; i < a.terms; i++) {
        printf("%d %d %d\n", a.data[i].row, a.data[i].col, a.data[i].value);
    }
    printf("====================\n");
}

int main(void) {
    // 테스트용 희소 행렬 정의
    SparseMatrix m = {
        { {0,3,7}, {1,0,9}, {1,5,8}, {3,0,6}, {3,1,5}, {4,5,1}, {5,2,2} },
        6, // 행의 개수
        6, // 열의 개수
        7  // 0이 아닌 요소 개수
    };

    SparseMatrix result;  // 전치된 행렬을 저장할 변수

    result = matrix_transpose2(m);  // 전치 연산 수행
    matrix_print(result);  // 결과 출력

    return 0;
}