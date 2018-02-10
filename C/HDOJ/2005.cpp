#include <stdio.h>
int main()
{
	int y, m, d,f,i;
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	while (scanf("%d/%d/%d",&y,&m,&d) != EOF)
	{	
		f = 0;
		if (y % 4 == 0 && y % 100 != 0 || (y % 400 == 0))
			 a[2] = 29;
		else 
			a[2] = 28;
		i = m - 1;
		while (i >= 1)
		{
			f += a[i];
			i--;
		}
		f += d;
		printf("%d\n", f);
	}
	return 0;
}