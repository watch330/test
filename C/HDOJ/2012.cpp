#include <stdio.h>
#include <math.h>
int value(int n) //����ʽ��[x,y]�����е�ֵ
{
	int z;

	z = n*n + n + 41; 
	return z;
}
int prime(int z)  //�ж�ֵ�Ƿ�Ϊ����
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
		if (x == 0 && y == 0)  //�������Ϊ0��������
			continue;
		else
		{
			
			for (i = x; x <= y; x++)
			{
				if (prime(value(x)) == 0)
					break;
			}
			if (x==(y+1))  //�ж�ֵ�Ƿ�ȫΪ����
				printf("OK\n");
			else printf("Sorry\n");
		}
	}
	return 0;
	
}