#include <stdio.h>

// person 구조체 정의
struct person {
    char name[50];   // 이름 (문자 배열)
    int age;         // 나이 (정수형)
    float Monthpay;    // 월급 (실수형)
};

int main() {
    struct person p1 = { "홍길동", 30, 3500.5 }; // 구조체 변수 선언 및 초기화

    // 출력
    printf("이름: %s\n", p1.name);
    printf("나이: %d\n", p1.age);
    printf("월급: %.2f\n", p1.Monthpay);

    return 0;
}