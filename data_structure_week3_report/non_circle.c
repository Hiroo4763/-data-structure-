#include <stdio.h>
#include <stdbool.h>

long long count = 0;


int ackermann(int m, int n) {
	int list[100000];
	int esp = 0;

	list[esp++] = m;
	list[esp] = n;

	while (true) { // true를 사용하기 위해 stdbool.h 헤더 파일을 추가
		count++;
		if (esp == 0) {
			return list[esp];
		}
		else if (list[esp - 1] == 0) {
			
			list[esp - 1] = list[esp] + 1;
			esp = esp - 1;
		}
		else if (list[esp] == 0) {
			
			list[esp - 1] = list[esp - 1] - 1;
			list[esp] = 1;
		}
		else {
		
			list[esp + 1] = list[esp] - 1;
			list[esp] = list[esp - 1];
			list[esp - 1] = list[esp - 1] - 1;

			esp = esp + 1;
		}
	}
}

int main() {
	int m, n;

	printf("m과 n의 값을 입력해 주세요: ");
	scanf_s("%d %d", &m, &n);

	printf("ackermann(%d, %d) = %d\n", m, n, ackermann(m, n));
	printf("count = %lld", count);

	return 0;
}
