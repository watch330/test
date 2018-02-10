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

	printf("������������ֵ������(������30��)");
	printf("��������Щֵ:\n");
	scanf("%d", &num);
	for (p = a, pn = a + num; p < pn; p++)
		scanf("%d", p);

	printf("���ֵ����Сֵ��λ��δ����ǰ:\n");
	for (p = a; p < pn; p++)
		printf("%3d", *p);
	printf("\n");

	swap(a, num);

	printf("���ֵ����Сֵ��λ�ý�����:\n");
	for (p = a; p < pn; p++)
		printf("%3d", *p);
	printf("\n");

	return 0;
}