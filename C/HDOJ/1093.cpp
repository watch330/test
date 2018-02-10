#include <stdio.h>
int main()
{
	int z=1,h,n, temp, sum = 0, i = 1;

	while (scanf("%d", &h) == 1)
	{	
		while (scanf("%d", &n) == 1)
		{
			i = 1;
			sum = 0;
			while (i <= n)
			{
				scanf("%d", &temp);
				sum += temp;
				i++;
			}

			if(z==1)
				printf("%d\n", sum);
			if (z != 1 && z <= h)
				printf("\n%d\n", sum);
			z++;
		}

	}

}