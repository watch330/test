#include <stdio.h>
int main()
{
	int num,i;
	double ave, score[103], min, max, sum;

	while (scanf("%d", &num) != EOF)
	{
		for (i = 1; i <= num; i++)
			scanf("%lf", &score[i]);
		min = score[1];
		max = score[1];
		for (i = 1; i <= num; i++)
		{
			if (max < score[i])
				max = score[i];
			else if (min > score[i])
				min = score[i];
		}
		sum = 0.0f;
		for (i = 1; i <= num; i++)
			sum += score[i];
		ave = (sum - min - max) / (num-2);
		printf("%.2lf\n", ave);
					
	}
	return 0;
}