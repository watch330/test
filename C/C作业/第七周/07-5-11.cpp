#include <stdio.h>
int digit(int n, int k);
int main(void)
{	
	int num,x,n;
	
	printf("������һ����,������λ��:\n");
	while (scanf("%d%d", &num,&n) != EOF)
	{
		x = digit(num, n);
		printf("%d�ĵ�%dλ��Ϊ%d\n", num, n, x);

	}
	return 0;
}
int digit(int n, int k)
{
	int i,a;
	for (i = 1; i <= k; i++)
	{
		a = n % 10;
		n /= 10;
	}
	return a;
}