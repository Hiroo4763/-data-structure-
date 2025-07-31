#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long long factorialA(int a);
long long factorialB(int b);

int main()
{
	clock_t start, stop;
	double durationA, durationB;
	start = clock();

	int n = 100;

	printf("반복문 팩토리얼 값 %lld\n", factorialA(n));

	stop = clock(); 
	durationA = (double)(stop - start) / CLOCKS_PER_SEC;	
	printf("수행시간은 %f초입니다.\n", durationA);

	start = clock();
	printf("재귀 팩토리얼 값 %lld\n", factorialB(n));

	stop = clock();
	durationB = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("수행시간은 %f초입니다.\n", durationB);
	return 0;
}

long long factorialA(int a)
{
    long long result = 1;
    for (int i = 1; i <= a; i++)
    {
        result *= i;
    }
    return result;
}

long long factorialB(int b)
{
	if (b == 0) return 1;	
	else return b * factorialB(b - 1);

}
