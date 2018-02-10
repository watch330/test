#include <stdio.h>
void swap(int *a, int num)
{
	int *q,*r,max,min;

	max = min = *a;
	for (q = a, r = a + num; q < r; q++)
		if (*q > max)
			max = *q;
		else if (*q < min)
			min = *q;
	for (q = a; q < r; q++)
		if (*q == max)
			*q = min;
		else if (*q == min)
			*q = max;
}
int main()
{
	int a[30], num,*p,*pn;

	printf("请输入待输入的值的数量(不大于30个)");
	printf("并输入这些值:\n");
	scanf("%d", &num);
	for (p = a, pn = a + num; p < pn; p++)
		scanf("%d", p);

	printf("最大值和最小值的位置未交换前:\n");
	for (p = a; p < pn; p++)
		printf("%3d", *p);
	printf("\n");

	swap(a, num);

	printf("最大值和最小值的位置交换后:\n");
	for (p = a; p < pn; p++)
		printf("%3d", *p);
	printf("\n");

	return 0;
}