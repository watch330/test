#include <stdio.h>
double fx(int temp)
{
	double sum;
	int flag,i;

	for (sum = 0,flag=1,i = 1; i <= temp; i++)
	{	
		sum += flag*(1.0 / i);
		flag=-flag;
	}
	return sum;

}
int main()
{
	int num,i;
	int temp;

	while (scanf("%d", &num) != EOF)
	{	
		i = 1;
		while (i<=num)
		{
			scanf("%d", &temp);
			printf("%.2f\n", fx(temp));
			i++;
		}
	}
	return 0;
}