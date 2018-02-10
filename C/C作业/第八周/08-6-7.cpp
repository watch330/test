#include <stdio.h>
#define PEOPLE 51
void print(int a[], int num)
{	 
	int i;
	for (i = 1; i <= num; i++)
	{
		printf("%10d", a[i]);
		if (i == num)
			printf("\n");
	}
}
int main()
{
	int num,temp,a[PEOPLE],hun[PEOPLE],fifty[PEOPLE],twenty[PEOPLE],ten[PEOPLE],five[PEOPLE],one[PEOPLE],sum[PEOPLE];
	int i;

	printf("输入职工数量:\n");
	while (scanf("%d", &num) != EOF)
	{	
		a[0] = 0;
		sum[0] = 0;  //总和清零
		printf("输入每名职工的工资:\n");
		for (i = 1; i <= num; i++)	//存储工资数据
			scanf("%d", &a[i]);
		for (i = 1; i <= num; i++)	//计算工资总和
			a[0] += a[i];
		for (i = 1; i <= num; i++)
		{	
			temp = a[i];
			hun[i] = temp / 100;
			temp -= hun[i] * 100;
			fifty[i] = temp / 50;
			temp -= fifty[i] * 50;
			twenty[i] = temp / 20;		//计算每个职工工资的各面值纸币数量
			temp -= twenty[i] * 20;
			ten[i] = temp / 10;
			temp -= ten[i] * 10;
			five[i] = temp / 5;
			temp -= five[i] * 5;
			one[i] = temp;
			sum[i] = hun[i] + fifty[i] + twenty[i] + ten[i] + five[i] + one[i];
			sum[0] += sum[i];
		}
		printf("每个人的工资:", num);
		print(a, num);
		printf("百元纸币数量:");
		print(hun, num);
		printf("五十纸币数量:");
		print(fifty, num);
		printf("二十纸币数量:");
		print(twenty, num);
		printf("十元纸币数量:");
		print(ten, num);
		printf("五元纸币数量:");
		print(five, num);
		printf("一元纸币数量:");
		print(one, num);
		printf("每人纸币总数:");
		print(sum, num);
		printf("工 资 总 计 :");
		printf("%10d\n",a[0]);
		printf("纸 币 总 计 :");
		printf("%10d\n", sum[0]);
		printf("请再次输入员工人数:\n");
	}
	return 0;
}