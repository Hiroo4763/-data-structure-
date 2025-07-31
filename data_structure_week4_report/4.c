#include <stdio.h>

// complex 자료형 정의
typedef struct {
    float real;      // 실수 부분
    float imaginary; // 허수 부분
} complex;

int main() {
    complex c1 = { 3.2, 4.5 }; // 복소수 변수 선언 및 초기화
    complex c2 = { 1.1, -2.3 }; // 복소수 변수 선언 및 초기화

    // c1, c2 출력
    printf("c1 = %.2f + %.2fi\n", c1.real, c1.imaginary);
    printf("c2 = %.2f + %.2fi\n", c2.real, c2.imaginary);

    return 0;
}