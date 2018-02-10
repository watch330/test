#include <stdio.h>
int main()
{
	int n,temp,sum=0,i=1;

	while (scanf("%d", &n) == 1)
	{	
		if (n != 0)
		{
			i = 1;
			sum = 0;
			while (i <= n)
			{
				scanf("%d", &temp);
				sum += temp;
				i++;
			}
			printf("%d\n", sum);
		}
	}
}