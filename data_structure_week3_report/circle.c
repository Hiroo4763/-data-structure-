#include <stdio.h>
long long count = 0;

// Ackermann 함수 (재귀적 구현)
int ackermann(int m, int n)
{
    count++;
    if (m == 0) 
    {
		return n + 1; // A(0, n) = n + 1 부분 구현
    }
    else if (n == 0) {
		return ackermann(m - 1, 1); // A(m, 0) = A(m - 1, 1) 부분 구현  
    }
    else {
		return ackermann(m - 1, ackermann(m, n - 1)); // A(m, n) = A(m - 1, A(m, n - 1)) 부분 구현
    }
}

int main() {
    int m, n;

    printf("m과 n의 값을 입력해 주세요: ");
    scanf_s("%d %d", &m, &n);
    printf("Ackermann(%d, %d) = %d\n", m, n, ackermann(m, n)); // 결과값 출력
	printf("계산횟수: %lld", count); // Ackermann 함수 계산 횟수 출력

    return 0;
}