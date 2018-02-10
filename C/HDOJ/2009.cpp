#include <stdio.h>
#include <math.h>
int main(void)
{
	double n, m,sum;
	int i;
	while (scanf("%lf%lf", &n, &m) != EOF)
	{	
		sum = 0;
		for (i = 1; i <= m; i++)
		{
			sum += n;
			n = sqrt(n);

		}
		printf("%.2lf\n", sum);
	}
	return 0;
}