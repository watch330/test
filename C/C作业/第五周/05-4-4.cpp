#include <stdio.h>
int main()
{

	int x, y;
	
	printf("������x,y��ֵ\n");

	while (scanf("%d%d", &x, &y) != EOF)
	{
		if (x >= 0)
			if (y >= 0)
				printf("����ֵΪ%d\n", x*x + y*y);
			else
				printf("����ֵΪ%d\n", x + y);
		else
			if (y >= 0)
				printf("����ֵΪ%d\n", x - y);
			else
				printf("����ֵΪ%d\n", x*x - y*y);
	}
	return 0;
}