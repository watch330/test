#include <stdio.h>
int main()
{
	int a, b,c;
	while (scanf("%d%d", &a, &b) == 2)
	{
		c = a + b;
		printf("%d\n", c);
	}
	return 0;
}