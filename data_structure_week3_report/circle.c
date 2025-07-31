#include <stdio.h>
long long count = 0;

// Ackermann �Լ� (����� ����)
int ackermann(int m, int n)
{
    count++;
    if (m == 0) 
    {
		return n + 1; // A(0, n) = n + 1 �κ� ����
    }
    else if (n == 0) {
		return ackermann(m - 1, 1); // A(m, 0) = A(m - 1, 1) �κ� ����  
    }
    else {
		return ackermann(m - 1, ackermann(m, n - 1)); // A(m, n) = A(m - 1, A(m, n - 1)) �κ� ����
    }
}

int main() {
    int m, n;

    printf("m�� n�� ���� �Է��� �ּ���: ");
    scanf_s("%d %d", &m, &n);
    printf("Ackermann(%d, %d) = %d\n", m, n, ackermann(m, n)); // ����� ���
	printf("���Ƚ��: %lld", count); // Ackermann �Լ� ��� Ƚ�� ���

    return 0;
}