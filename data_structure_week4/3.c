#include <stdio.h>

int main() {
    double score[3][5] = { {80,90,88}, {65,92, 78}, {100, 97, 92} };


    for (int k = 0; k < 3; k++) {
        score[k][3] = 0;
        for (int i = 0; i < 3; i++) {
            score[k][3] += score[k][i];
        }
        score[k][4] = score[k][3] / 3.0;
    }

    printf("\n학생들의 성적 합계와 평균:\n");
    for (int k = 0; k < 3; k++) {
        printf("학생 %d 성적 합계: %f, 성적 평균: %f\n", k + 1, score[k][3], score[k][4]);
    }
    return 0;
}