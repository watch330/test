#include <stdio.h>
int main()
{
	int n,m,i,count;
	int h, d, u;
	int h_, d_, u_;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		count = 0;
		for (i = m; i <= n; i++)
		{
			h = i / 100;
			d = (i % 100) / 10;
			u = i % 10;
			h_ = h*h*h;
			d_ = d*d*d;
			u_ = u*u*u;
			if (h_ + d_ + u_ == i)
			{	
				count++;
				if (count == 1)
					printf("%d", i);
				if (count != 1 && count != 0)
					printf(" %d", i);
			}		
		}
		if (count == 0)
			printf("no\n");
		else
			printf("\n");
	}

	return 0;

}