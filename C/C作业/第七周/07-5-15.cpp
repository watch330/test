#include <stdio.h>
#include <math.h>
double f(double x, int n);
int main()
{	
	double x,power;
	int n;

	printf("������x��n,��x��n�η�\n\n");
	scanf("%lf%d", &x, &n);

		power = f(x, n);
		printf("%.3lf��%d�η�����%.2lf\n", x, n, power);
	
}
double f(double x, int n)
{	
	double pi;
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	else
	{
		pi = f(x, n - 1)*x;
		return pi;
	}
}