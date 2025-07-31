#include <stdio.h>
#define n 100 // 배열의 크기
int items = 7; // 배열의 항목 개수 

// 배열에 정수를 삽입하는 함수
void insert(int array[], int loc, int value) { // 배열, 삽입할 위치, 삽입할 값
	for (int i = items; i >= loc; i--) { // 배열의 끝부터 삽입할 위치까지
		array[i + 1] = array[i]; // 한 칸씩 뒤로 이동
    }
	array[loc] = value; // 삽입할 위치에 값 삽입
	items++; // 항목 개수 증가
}

int main() {
    int array[n] = { 1, 2, 3, 4, 5, 6, 7}; 
	int loc, value;

    printf("원래 배열: "); // 원래 배열 출력
    for (int i = 0; i < items; i++) {
        printf("%d ", array[i]);
    }

	printf("삽입할 위치(loc)와 값: "); // 삽입할 위치와 값 입력
	scanf_s("%d %d", &loc, &value);
	insert(array, loc, value); // 삽입 함수 호출

    printf("삽입 후 배열: "); // 변경된 배열 출력
    for (int i = 0; i < items; i++) {
        printf("%d ", array[i]);
    }


    return 0;
}