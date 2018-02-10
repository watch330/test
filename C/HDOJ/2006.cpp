#include <stdio.h>
int main()
{
	int n, num, i, product, z;
	int a;

	while (scanf("%d", &n) != EOF)
	{	
		product = 1;
		z = 2;
		i = 1;

		while (i <= n)
		{
			scanf("%d", &num);
			if (num % 2 == 1)
			{
				product *= num;
				a = num;
				z++;
			}
			i++;
		}
		if (z >1)
		{
			printf("%d\n", product);
		}
		if (z==1)
		{
			printf("%d\n",a);
		}
	}
	return 0;

}