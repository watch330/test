#include <stdio.h>
int main(void)
{
	int n,neg, zero, pos,i;
	double temp;
	while (scanf("%d", &n) == 1)
	{	
		neg = 0, zero = 0, pos = 0;

		if (n > 0)
		{
			for (i = 1; i <= n; i++)
			{
				scanf("%lf", &temp);
				if (temp < 0)
					neg++;
				if (temp == 0)
					zero++;
				if (temp > 0)
					pos++;
			}
			printf("%d %d %d\n", neg, zero, pos);
		}
	}
	return 0;
}