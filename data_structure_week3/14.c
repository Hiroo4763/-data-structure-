#include <stdio.h>
double circle(int n);


int main()
{
    int n = 0;
    scanf_s("%d", &n);

    if (n == 0) {
        printf("0���� ū ���� �Է����ֽÿɼ���.\n");
        return 1;
    }

    printf("%lf\n", circle(n));
    return 0;
}


double circle(int n)
{
	if (n == 2)
		return 1;
	else return (1.0 / n + circle(n - 1));
}