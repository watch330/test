#include <stdio.h>

int main()
{
	int b[101],a[101];
	int i,people, count = 0,num,out;

	printf("����������(100����):\n");
	scanf("%d", &people);
	printf("����%d������ɻ�,������ڼ����˳�Ȧ:\n",people);
	for (i = 0; i <= people; i++)
		b[i] = i;
	while (scanf("%d", &num) != EOF)
	{	
		for (i = 0; i <= people; i++) //���»ָ�����λ��
			a[i] = b[i];
		printf("���γ�Ȧ����:");
		count = 0;
		out = 0;
		for (i = 1; 1 ; i++)
		{	
			if (a[i] != 0) //�����λ��Ϊ�������
				count++;  //��Ϊ��ͼ���
				if (count == num) 
				{
					printf("%5d", a[i]);
					out++;
					a[i] = 0;  //���Ϲ涨���������,�������λ�ù�0
					count = 0;
				}
				if (i == people) //�ж��Ƿ�������һ�ֳ�Ȧ
					i = 0;
				if (out == people) //�ж��Ƿ��Ȧ���
				{	
					printf("\n");
					break;
				}
		}
		printf("������ڼ����˳�Ȧ:\n");
	}
	return 0;
}