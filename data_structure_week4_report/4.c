#include <stdio.h>

// complex �ڷ��� ����
typedef struct {
    float real;      // �Ǽ� �κ�
    float imaginary; // ��� �κ�
} complex;

int main() {
    complex c1 = { 3.2, 4.5 }; // ���Ҽ� ���� ���� �� �ʱ�ȭ
    complex c2 = { 1.1, -2.3 }; // ���Ҽ� ���� ���� �� �ʱ�ȭ

    // c1, c2 ���
    printf("c1 = %.2f + %.2fi\n", c1.real, c1.imaginary);
    printf("c2 = %.2f + %.2fi\n", c2.real, c2.imaginary);

    return 0;
}