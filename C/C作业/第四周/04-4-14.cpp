//输出所有三位的"水仙花数"
#include <stdio.h>
int main()
{
	int num;
	int h, d, u;
	int h_, d_, u_;

	for (num = 100; num <= 999; num++)
	{	
		h = num / 100;
		d = (num % 100) / 10;
		u = num % 10;
		h_ = h*h*h;
		d_ = d*d*d;
		u_ = u*u*u;

		if (h_ + d_ + u_ == num)
			printf("%d\n", num);
	}
	printf("Done!\n");

	return 0;
}