#include<stdio.h>
#include<stdlib.h>
#include"main.h"

/*#include <stdio.h>
#include <stdlib.h>
#define FirstRoom 1000
#define LastRoom 3099
typedef struct Room {
int Number;
int Shoufeifangshi;
int Price_day, Price_hour;
int yyyy, mm, dd, hh;
struct Room *next;
}Sroom;
typedef struct list {
Sroom *head;
Sroom *tail;
}Slist; */
int judgeday(int n, int y)
{
	if (n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12)
		return 31;
	else if (n == 4 || n == 6 || n == 9 || n == 11)
		return 30;
	else
	{
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			return 29;
		else
			return 28;
	}
}
int judge_dayyear(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return 366;
	else
		return 365;
}
int jssj(Sroom *a, Sroom *b)
{
	int mo = 0;
	int i, j;
	if ((b->mm - a->mm) >= 0)
	{
		for (i = a->hh; i < b->hh; i++)
		{
			mo += judgeday(i, b->yyyy);
		}
	}
	if ((b->yyyy - a->yyyy) != 0)
	{
		for (j = a->yyyy; j<b->yyyy; j++)
		{
			mo += judge_dayyear(j);
		}
	}
	return mo;
}
void fin(Slist *plist)
{
	int flag = 0;
	double an = 0;
	Sroom *d = (Sroom *)malloc(sizeof(Sroom));
	printf("��ǰ���ڣ�\n");
	scanf("%d%d%d%d", &d->yyyy,
		&d->mm,
		&d->dd,
		&d->hh);
	while (1)
	{
		if (d->mm > 12 || d->dd >= 31 || d->hh >= 24)
		{
			printf("��������\n");
			scanf("%d%d%d%d", &d->yyyy,
				&d->mm,
				&d->dd,
				&d->hh);
		}
		else
			break;
	}
	Sroom *k = plist->head;
	while (k != NULL)
	{
		if (k->yyyyo < d->yyyy)
			flag = 1;
		else
		{
			if (k->mm < d->mmo)
				flag = 1;
			else
			{
				if (k->dd < d->ddo)
					flag = 1;
				else
				{
					if (k->hh < d->hho)
						flag = 1;
				}
			}
		}
		double ew;
		int m = 0;
		if (flag == 0)
		{
			printf("�޳�ʱ����\n");
		}
		if (flag == 1)
		{
			printf("%d���䳬ʱ\n", k->Number);
			printf("�Ƿ����ѣ�1��0��\n");
			scanf("%d\n", &m);
			if (m != 1)
			{
				if (k->Charge_mode == 1)
				{
					ew = jssj(k, d)*
						k->Price_day;
				}
				if (k->Charge_mode == 0)
				{
					ew = jssj(k, d) * 24 * k->Price_hour;
				}
				printf("%d����Ӧ��%lfԪ\n", k->Number, ew);
				free(k);
			}
			if (m == 1)
			{
				printf("�����������\n");

				printf("ѡ��������������\n");
				scanf("%d%d%d%d", &k->yyyyo,
					&k->mmo,
					&k->ddo,
					&k->hho);
				while (1)
				{
					if (k->mm > 12 || k->dd >= 31 || k->hh >= 24)
					{
						printf("��������\n");
						scanf("%d%d%d%d", &k->yyyy,
							&k->mm,
							&k->dd,
							&k->hh);
					}
					else
						break;
				}
				printf("��ѡ�񸶷ѷ�ʽ,1����0��Сʱ\n");
				scanf("%d", &k->Charge_mode);
				if (k->Charge_mode == 1)
				{
					an = jssj(d, k)*
						k->Price_day;
				}

				if (k->Charge_mode == 0)
				{
					an = jssj(d, k) * 24 *
						k->Price_hour;
				}
				printf("�밴ʱ����\n");
				printf("����븶%lfԪ\n", an);
			}
		}
	}
	free(d);
}
int money(int *total)
{
	int ftotal;
	printf("���������,�ܽ������\n");

	ftotal = *total;
	printf("%dԪ\n", ftotal);
	return 0;
}
int sw(void)
{
	int l;
	scanf("%d", &l);
	return l;
}
int Statement(int *total, Slist *plist)
{
	printf("���й���ѡ��1-������ʱ���䣬2-��ʾ���������3-�˳�");
	do {
		switch (sw())
		{
		case 1:fin(plist); break;
		case 2:money(total); break;
		case 3:return 0;
		default:printf("�����Կ�\n");
			break;
		}

	} while (1);
}