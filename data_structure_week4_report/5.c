#include <stdio.h>

// 복소수 구조체 정의
typedef struct {
    float real;      // 실수 부분
    float imaginary; // 허수 부분
} Complex;

// 복소수 덧셈 함수
Complex Complex_add(Complex a, Complex b) {
	Complex result = { a.real + b.real, a.imaginary + b.imaginary }; // 덧셈 수행
	return result; // 덧셈 결과 반환
}

int main() {
	Complex c1 = { 3.2, 4.5 }; // 복소수 변수 선언 및 초기화
    Complex c2 = { 1.1, -2.3 }; // 복소수 변수 선언 및 초기화
	Complex sum = Complex_add(c1, c2); // 두 복소수 덧셈

	printf("두 복소수의 합: %.2f + %.2fi\n", sum.real, sum.imaginary); // 덧셈 결과 출력
    return 0;
}