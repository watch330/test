#include <stdio.h>
int main()
{
	int n1, n2, squ, cub;
	int m1, m2;
	while (scanf("%d%d", &n1, &n2) != EOF)
	{   
		squ = 0, cub = 0;

		if (n1 >= n2)
		{
			m1 = n1;
			m2 = n2;
		}
		else
		{
			m1 = n2;
			m2 = n1;
		}
		for ( ; m2 <= m1; m2++)
		{
			if (m2 % 2 == 0)
			{
				squ += m2*m2;
			}
			else
			{
				cub += m2*m2*m2;
			}
		}
		printf("%d %d\n", squ, cub);
	}
	return 0;
}