#include <stdio.h>
#include <math.h>
int value(int n) //求表达式在[x,y]上所有的值
{
	int z;

	z = n*n + n + 41; 
	return z;
}
int prime(int z)  //判断值是否为素数
{
	int i;

	for (i = 2; (i*i) < z ; i++)
	{
		if (z%i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int x, y;
	int i;

	while (scanf("%d%d", &x, &y) != EOF)
	{	
		if (x == 0 && y == 0)  //如果输入为0不做处理
			continue;
		else
		{
			
			for (i = x; x <= y; x++)
			{
				if (prime(value(x)) == 0)
					break;
			}
			if (x==(y+1))  //判断值是否全为素数
				printf("OK\n");
			else printf("Sorry\n");
		}
	}
	return 0;
	
}