#include <stdio.h>
int main()
{
	int days,n;
	
	while (scanf("%d", &days) != EOF)
	{	
		n = 1;
		while ((days--)>1)
		{
			n = (n + 1) * 2;
		}
		printf("%d\n", n);
	}
	return 0;
}