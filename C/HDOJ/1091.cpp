#include <stdio.h>
int main()
{
	int a, b, sum;
	
	while (scanf("%d%d", &a, &b) == 2)
	{
		if (a + b != 0)
			printf("%d\n", a + b);
	}
	return 0;
}