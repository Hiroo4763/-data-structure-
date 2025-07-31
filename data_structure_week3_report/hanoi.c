#include <stdio.h>

void hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("���� 1�� %c ��տ��� %c ������� �̵�\n", source, target);
        return;
    }
    hanoi(n - 1, source, auxiliary, target);
    printf("���� %d��(��) %c ��տ��� %c ������� �̵�\n", n, source, target);
    hanoi(n - 1, auxiliary, target, source);
}

int main() {
    int n = 3; // ���� ����
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
