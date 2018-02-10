#include <stdio.h>
#include <math.h>
int main()
{
	float x1, y1, x2, y2,deta;
	float val;

	while (scanf("%f%f%f%f",&x1,&y1,&x2,&y2)!=EOF)
	{
		deta = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
		val = sqrt(deta);
			printf("%.2f\n", val);
	}
	return 0;
}