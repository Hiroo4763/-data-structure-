#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101  // 최대 항 개수

typedef struct { // 다항식 항을 저장하는 구조체
    float coef;  // 계수
    int expon;   // 지수 
} polynomial;

polynomial terms[MAX_TERMS] = { {8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0} }; // 다항식의 항을 저장할 배열 
int avail = 6;  // 현재 사용된 항의 개수 
char compare(int a, int b) { // 지수 비교 함수
    if (a > b) return '>';  // 첫 번째 항이 더 클 경우
    else if (a < b) return '<';  // 두 번째 항이 더 클 경우
    else return '=';  // 두 항의 지수가 같을 경우
}

void attach(float coef, int expon) { // 새로운 항을 배열에 추가하는 함수
    if (avail > MAX_TERMS) {  // 최대 개수를 초과할 경우
        fprintf(stderr, "항의 개수가 너무 많음\n");
        exit(1);
    }
    terms[avail].coef = coef;   // 계수 저장
    terms[avail].expon = expon; // 지수 저장
    avail++;  // 사용된 항 개수 증가
}

void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) { // 두 다항식을 더하는 함수
    float tempcoef;
    *Cs = avail;  // 결과 다항식의 시작 위치 설정
    while (As <= Ae && Bs <= Be) {  // 두 다항식의 모든 항을 비교하며 덧셈 수행
        switch (compare(terms[As].expon, terms[Bs].expon)) {
        case '>':  // 첫 번째 다항식의 지수가 더 클 경우
            attach(terms[As].coef, terms[As].expon);
            As++;
            break;
        case '=':  // 두 항의 지수가 같을 경우 계수만 더함
            tempcoef = terms[As].coef + terms[Bs].coef;
            if (tempcoef)  // 계수가 0이 아니면 추가
                attach(tempcoef, terms[As].expon);
            As++;
            Bs++;
            break;
        case '<':  // 두 번째 다항식의 지수가 더 클 경우
            attach(terms[Bs].coef, terms[Bs].expon);
            Bs++;
            break;
        }
    }

    for (; As <= Ae; As++) // As 부분 남은 항을 결과 다항식에 추가 
        attach(terms[As].coef, terms[As].expon);
    for (; Bs <= Be; Bs++) // Bs 부분 남은 항을 결과 다항식에 추가 
        attach(terms[Bs].coef, terms[Bs].expon);
    *Ce = avail - 1;  // 결과 다항식의 끝 위치 저장
}


void print_poly(int s, int e) { // 다항식을 출력하는 함수
    for (int i = s; i < e; i++) {
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);  // 마지막 항 출력
}

int main(void) {
    int As = 0, Ae = 2; // 첫 번째 다항식: 8x^3 + 7x^1 + 1x^0
    int Bs = 3, Be = 5; // 두 번째 다항식: 10x^3 + 3x^2 + 1x^0
    int Cs, Ce;  // 결과 다항식의 시작과 끝 인덱스
    // 두 다항식을 더함
    poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
    // 다항식 출력
    print_poly(As, Ae);
    print_poly(Bs, Be);
    printf("-------------------------------------------------\n");
    print_poly(Cs, Ce);

    return 0;
}