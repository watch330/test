#include <stdio.h>
#include <math.h>
int main()
{
	long int num, sum=0, t;

	printf("����һ�����Լ��,����q���˳�\n");
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
			printf("%ld�ǻ�����\n", t);
		}
		else
		{
			printf("%ld���ǻ�����\n", t);
		}
	}
	return 0;
}