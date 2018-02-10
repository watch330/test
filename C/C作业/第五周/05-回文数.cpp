#include <stdio.h>
#include <math.h>
int main()
{
	long int num, sum=0, t;

	printf("输入一个数以检测,输入q以退出\n");
	while (scanf("%ld", &num)==1)
	{	
		sum = 0;

		t = num;
		while (num != 0)
		{
			sum = sum * 10 + num % 10;
			num /= 10;
		}
		if (t == sum)
		{
			printf("%ld是回文数\n", t);
		}
		else
		{
			printf("%ld不是回文数\n", t);
		}
	}
	return 0;
}