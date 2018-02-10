#include <stdio.h>
void yahuei(int a[][10], int num);
void print(int a[][10], int num);
int main()
{	
	int a[10][10];
	int num;

	printf("请输入10及以内的正整数():\n");
	while (scanf("%d", &num) != EOF&& num <= 10&&num>=1)
	{
		yahuei(a, num);
		print(a, num);
		printf("请再次输入:\n");
	}
	return 0;
}

void yahuei(int a[][10], int num)
{
	int i, j;
	a[0][0] = 1;
	for (i = 0; i < num; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}
	for (i = 2; i < num; i++)
		for (j = 1; j < i; j++)
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
}

void print(int a[][10], int num)
{
	int i, j,m;
	m = num*3;
	for (i = 0; i < num; i++)
	{   
		for (j = 0; j <= i; j++)
		{
			if (j == 0)
				printf("%*d",m,a[i][j]);
			else
			{
				if (j == 1)
					printf("%6d", a[i][j]);
				else
					printf("%6d", a[i][j]);
			}
			if (j == i)
				printf("\n\n");
		}
		m-=3;
	}
}
