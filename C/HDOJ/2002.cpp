#include <stdio.h>
#define PI 3.1415927
int main()
{
	double r, v,r_3;

	while (scanf("%lf",&r)!=EOF)
	{	
		r_3 = r*r*r;
		v = (4.0 / 3) * PI*r_3;
		printf("%.3lf\n", v);
	}
	return 0;
}