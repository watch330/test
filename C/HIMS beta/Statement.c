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
	printf("当前日期：\n");
	scanf("%d%d%d%d", &d->yyyy,
		&d->mm,
		&d->dd,
		&d->hh);
	while (1)
	{
		if (d->mm > 12 || d->dd >= 31 || d->hh >= 24)
		{
			printf("输入有误\n");
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
			printf("无超时房间\n");
		}
		if (flag == 1)
		{
			printf("%d房间超时\n", k->Number);
			printf("是否续费？1是0否\n");
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
				printf("%d房间应收%lf元\n", k->Number, ew);
				free(k);
			}
			if (m == 1)
			{
				printf("请先清算费用\n");

				printf("选择续费日期至？\n");
				scanf("%d%d%d%d", &k->yyyyo,
					&k->mmo,
					&k->ddo,
					&k->hho);
				while (1)
				{
					if (k->mm > 12 || k->dd >= 31 || k->hh >= 24)
					{
						printf("输入有误\n");
						scanf("%d%d%d%d", &k->yyyy,
							&k->mm,
							&k->dd,
							&k->hh);
					}
					else
						break;
				}
				printf("可选择付费方式,1按天0按小时\n");
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
				printf("请按时付款\n");
				printf("这次请付%lf元\n", an);
			}
		}
	}
	free(d);
}
int money(int *total)
{
	int ftotal;
	printf("结算已完成,总金额如下\n");

	ftotal = *total;
	printf("%d元\n", ftotal);
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
	printf("进行功能选择：1-检索超时房间，2-显示收入情况，3-退出");
	do {
		switch (sw())
		{
		case 1:fin(plist); break;
		case 2:money(total); break;
		case 3:return 0;
		default:printf("不可以空\n");
			break;
		}

	} while (1);
}