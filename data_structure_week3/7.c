#include <stdio.h>

int main() 
{
	int a = 0, sum = 0;
	scanf_s(":", &a);
	sumB(5);
	
}

int sumA(int n)
{
	printf("%d\n", n);
	if (n < 1)
		return 0;
	else return (n + sumA(n - 1));
}	

int sumB(int n)
{
	printf("%d\n", n);
	int sum = 0;
	for (int i = 0; i < n; ++i);
		if (n < 1)
			return 0;
		sum = n + sum;
		return sum;
	
}
