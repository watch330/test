#include <stdio.h>

int main()
{
	int b[101],a[101];
	int i,people, count = 0,num,out;

	printf("请输入人数(100以内):\n");
	scanf("%d", &people);
	printf("现有%d个人组成环,请输入第几个人出圈:\n",people);
	for (i = 0; i <= people; i++)
		b[i] = i;
	while (scanf("%d", &num) != EOF)
	{	
		for (i = 0; i <= people; i++) //重新恢复各个位置
			a[i] = b[i];
		printf("依次出圈的是:");
		count = 0;
		out = 0;
		for (i = 1; 1 ; i++)
		{	
			if (a[i] != 0) //若这个位置为零就跳过
				count++;  //不为零就计数
				if (count == num) 
				{
					printf("%5d", a[i]);
					out++;
					a[i] = 0;  //符合规定的数就输出,并把这个位置归0
					count = 0;
				}
				if (i == people) //判断是否进行完第一轮出圈
					i = 0;
				if (out == people) //判断是否出圈完毕
				{	
					printf("\n");
					break;
				}
		}
		printf("请输入第几个人出圈:\n");
	}
	return 0;
}