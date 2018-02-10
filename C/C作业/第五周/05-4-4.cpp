#include <stdio.h>
int main()
{

	int x, y;
	
	printf("请输入x,y的值\n");

	while (scanf("%d%d", &x, &y) != EOF)
	{
		if (x >= 0)
			if (y >= 0)
				printf("函数值为%d\n", x*x + y*y);
			else
				printf("函数值为%d\n", x + y);
		else
			if (y >= 0)
				printf("函数值为%d\n", x - y);
			else
				printf("函数值为%d\n", x*x - y*y);
	}
	return 0;
}