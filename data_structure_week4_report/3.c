#include <stdio.h>

// person ����ü ����
struct person {
    char name[50];   // �̸� (���� �迭)
    int age;         // ���� (������)
    float Monthpay;    // ���� (�Ǽ���)
};

int main() {
    struct person p1 = { "ȫ�浿", 30, 3500.5 }; // ����ü ���� ���� �� �ʱ�ȭ

    // ���
    printf("�̸�: %s\n", p1.name);
    printf("����: %d\n", p1.age);
    printf("����: %.2f\n", p1.Monthpay);

    return 0;
}