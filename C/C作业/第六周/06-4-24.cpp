//用区间二分法求实根
#include <stdio.h>
#include <math.h>
double F(double x);
int main()
{
	double a = 0, b = 5, c=0;
	int count = 0;
	printf("方程x*x+x*sinx-5=0,用区间二分法求其在[0,5]内的一个实根.\n\n");

	while (1)
	{	
		c = (a + b) / 2;
		if (fabs(b - a) < 1e-5 || fabs(F(c)) < 1e-5 )
		{	
			break;
		}
		else if (F(a)*F(c)<0)
			b = c;
		else
			a = c;
		count++;
	}
	printf("root=%lf 迭代了%d次\n", c,count);
	return 0;
}
double F(double x)
{
	double y;
	y = x*x + x*sin(x) - 5;

	return y;
}