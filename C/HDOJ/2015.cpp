#include <stdio.h>
#include <string.h>
int input(char a[], char b[],int d[][4],int *pA,int *pB)
{
	int i,j,temp;
	
	if(gets_s(a,50)==NULL)
		return 0;
	gets_s(b,50);
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &temp);
			d[i][j] = temp;
		}
	scanf("%d%d", pA, pB);
	return 1;
}
int sum_(char *pmin, char *pmax, int d[][4])
{
	int i, sum = 0;
	
	for (i = 0; *(pmin+i) != '\0'; i++)
		if (*(pmin + i) == 'A')
		{
			if (*(pmax + i) == 'A')
				sum += d[0][0];
			else
			{
				if (*(pmax + i) == 'T')
					sum += d[0][1];
				else
				{
					if (*(pmax + i) == 'G')
						sum += d[0][2];
					else
						sum += d[0][3];
				}
			}
		}
		else
		{
			if (*(pmin + i) == 'T')
			{
				if (*(pmax + i) == 'A')
					sum += d[1][0];
				else
				{
					if (*(pmax + i) == 'T')
						sum += d[1][1];
					else
					{
						if (*(pmax + i) == 'G')
							sum += d[1][2];
						else
							sum += d[1][3];
					}
				}
			}
			else
			{
				if (*(pmin + i) == 'G')
				{
					if (*(pmax + i) == 'A')
						sum += d[2][0];
					else
					{
						if (*(pmax + i) == 'T')
							sum += d[2][1];
						else
						{
							if (*(pmax + i) == 'G')
								sum += d[2][2];
							else
								sum += d[2][3];
						}
					}
				}
				else
				{
					if (*(pmax + i) == 'A')
						sum += d[3][0];
					else
					{
						if (*(pmax + i) == 'T')
							sum += d[3][1];
						else
						{
							if (*(pmax + i) == 'G')
								sum += d[3][2];
							else
								sum += d[3][3];
						}
					}
				}

			}
		}
	return sum;
}
int compare(char a[], char b[], int d[][4], int A, int B)
{
	int len_a, len_b,sum=0, len_max, len_min;
	char *pmin,*pmax;
	len_a = strlen(a);
	len_b = strlen(b);
	pmin = len_b >= len_a ? a : b;
	pmax = pmin == a ? b : a;
	len_max = len_b >= len_a ? len_b : len_a;
	len_min = len_max == len_b ? len_a : len_b;
	sum = sum_(pmin, pmax, d);
	if(len_max!=len_min)
	sum += (-A - (B * ( len_max- len_min - 1)));
	return sum;
}
void main()
{
	char a[50], b[50];
	int d[4][4], A, B,*pA = &A, *pB = &B,sum;
	while (input(a, b,d,pA,pB))
	{
		sum = compare(a, b, d, A, B);
		printf("%d\n", sum);
	}
}