#include <stdio.h>

// ���Ҽ� ����ü ����
typedef struct {
    float real;      // �Ǽ� �κ�
    float imaginary; // ��� �κ�
} Complex;

// ���Ҽ� ���� �Լ�
Complex Complex_add(Complex a, Complex b) {
	Complex result = { a.real + b.real, a.imaginary + b.imaginary }; // ���� ����
	return result; // ���� ��� ��ȯ
}

int main() {
	Complex c1 = { 3.2, 4.5 }; // ���Ҽ� ���� ���� �� �ʱ�ȭ
    Complex c2 = { 1.1, -2.3 }; // ���Ҽ� ���� ���� �� �ʱ�ȭ
	Complex sum = Complex_add(c1, c2); // �� ���Ҽ� ����

	printf("�� ���Ҽ��� ��: %.2f + %.2fi\n", sum.real, sum.imaginary); // ���� ��� ���
    return 0;
}