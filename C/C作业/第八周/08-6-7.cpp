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

	printf("����ְ������:\n");
	while (scanf("%d", &num) != EOF)
	{	
		a[0] = 0;
		sum[0] = 0;  //�ܺ�����
		printf("����ÿ��ְ���Ĺ���:\n");
		for (i = 1; i <= num; i++)	//�洢��������
			scanf("%d", &a[i]);
		for (i = 1; i <= num; i++)	//���㹤���ܺ�
			a[0] += a[i];
		for (i = 1; i <= num; i++)
		{	
			temp = a[i];
			hun[i] = temp / 100;
			temp -= hun[i] * 100;
			fifty[i] = temp / 50;
			temp -= fifty[i] * 50;
			twenty[i] = temp / 20;		//����ÿ��ְ�����ʵĸ���ֵֽ������
			temp -= twenty[i] * 20;
			ten[i] = temp / 10;
			temp -= ten[i] * 10;
			five[i] = temp / 5;
			temp -= five[i] * 5;
			one[i] = temp;
			sum[i] = hun[i] + fifty[i] + twenty[i] + ten[i] + five[i] + one[i];
			sum[0] += sum[i];
		}
		printf("ÿ���˵Ĺ���:", num);
		print(a, num);
		printf("��Ԫֽ������:");
		print(hun, num);
		printf("��ʮֽ������:");
		print(fifty, num);
		printf("��ʮֽ������:");
		print(twenty, num);
		printf("ʮԪֽ������:");
		print(ten, num);
		printf("��Ԫֽ������:");
		print(five, num);
		printf("һԪֽ������:");
		print(one, num);
		printf("ÿ��ֽ������:");
		print(sum, num);
		printf("�� �� �� �� :");
		printf("%10d\n",a[0]);
		printf("ֽ �� �� �� :");
		printf("%10d\n", sum[0]);
		printf("���ٴ�����Ա������:\n");
	}
	return 0;
}