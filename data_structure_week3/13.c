#include <stdio.h>

int main()
{
	int n = 0, sum = 0;
	scanf_s("%d", &n);

	
	printf("%d\n", circle(n));
	
}

int circle(int n)
{
	if (n < 1)
		return 0;
	else return (n + circle(n - 1));
}