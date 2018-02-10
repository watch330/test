#include <stdio.h>
int main()
{	
	int n,num,i=1, product=1,z=0;

	printf("请输入一个数字:");
	scanf("%d", &n);
	printf("请依次输入%d个数字:", n);
	while (i <= n)
	{
		scanf("%d", &num);
		if (num % 2 == 1)
		{
			product *= num;
			z++;
		}
		i++;	
	}
	if (z != 0)
	{
		printf("所输入的奇数乘积为 %d\n", product);
	}
	else
	{
		printf("没有奇数!\n");
	}
	return 0;

}