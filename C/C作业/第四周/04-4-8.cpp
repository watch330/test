#include <stdio.h>
int main()
{	
	int n,num,i=1, product=1,z=0;

	printf("������һ������:");
	scanf("%d", &n);
	printf("����������%d������:", n);
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
		printf("������������˻�Ϊ %d\n", product);
	}
	else
	{
		printf("û������!\n");
	}
	return 0;

}