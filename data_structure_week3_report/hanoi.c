#include <stdio.h>

void hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("원판 1을 %c 기둥에서 %c 기둥으로 이동\n", source, target);
        return;
    }
    hanoi(n - 1, source, auxiliary, target);
    printf("원판 %d을(를) %c 기둥에서 %c 기둥으로 이동\n", n, source, target);
    hanoi(n - 1, auxiliary, target, source);
}

int main() {
    int n = 3; // 원판 개수
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
