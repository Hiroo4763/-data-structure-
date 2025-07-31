#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101  // �ִ� �� ����

typedef struct { // ���׽� ���� �����ϴ� ����ü
    float coef;  // ���
    int expon;   // ���� 
} polynomial;

polynomial terms[MAX_TERMS] = { {8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0} }; // ���׽��� ���� ������ �迭 
int avail = 6;  // ���� ���� ���� ���� 
char compare(int a, int b) { // ���� �� �Լ�
    if (a > b) return '>';  // ù ��° ���� �� Ŭ ���
    else if (a < b) return '<';  // �� ��° ���� �� Ŭ ���
    else return '=';  // �� ���� ������ ���� ���
}

void attach(float coef, int expon) { // ���ο� ���� �迭�� �߰��ϴ� �Լ�
    if (avail > MAX_TERMS) {  // �ִ� ������ �ʰ��� ���
        fprintf(stderr, "���� ������ �ʹ� ����\n");
        exit(1);
    }
    terms[avail].coef = coef;   // ��� ����
    terms[avail].expon = expon; // ���� ����
    avail++;  // ���� �� ���� ����
}

void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) { // �� ���׽��� ���ϴ� �Լ�
    float tempcoef;
    *Cs = avail;  // ��� ���׽��� ���� ��ġ ����
    while (As <= Ae && Bs <= Be) {  // �� ���׽��� ��� ���� ���ϸ� ���� ����
        switch (compare(terms[As].expon, terms[Bs].expon)) {
        case '>':  // ù ��° ���׽��� ������ �� Ŭ ���
            attach(terms[As].coef, terms[As].expon);
            As++;
            break;
        case '=':  // �� ���� ������ ���� ��� ����� ����
            tempcoef = terms[As].coef + terms[Bs].coef;
            if (tempcoef)  // ����� 0�� �ƴϸ� �߰�
                attach(tempcoef, terms[As].expon);
            As++;
            Bs++;
            break;
        case '<':  // �� ��° ���׽��� ������ �� Ŭ ���
            attach(terms[Bs].coef, terms[Bs].expon);
            Bs++;
            break;
        }
    }

    for (; As <= Ae; As++) // As �κ� ���� ���� ��� ���׽Ŀ� �߰� 
        attach(terms[As].coef, terms[As].expon);
    for (; Bs <= Be; Bs++) // Bs �κ� ���� ���� ��� ���׽Ŀ� �߰� 
        attach(terms[Bs].coef, terms[Bs].expon);
    *Ce = avail - 1;  // ��� ���׽��� �� ��ġ ����
}


void print_poly(int s, int e) { // ���׽��� ����ϴ� �Լ�
    for (int i = s; i < e; i++) {
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);  // ������ �� ���
}

int main(void) {
    int As = 0, Ae = 2; // ù ��° ���׽�: 8x^3 + 7x^1 + 1x^0
    int Bs = 3, Be = 5; // �� ��° ���׽�: 10x^3 + 3x^2 + 1x^0
    int Cs, Ce;  // ��� ���׽��� ���۰� �� �ε���
    // �� ���׽��� ����
    poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
    // ���׽� ���
    print_poly(As, Ae);
    print_poly(Bs, Be);
    printf("-------------------------------------------------\n");
    print_poly(Cs, Ce);

    return 0;
}