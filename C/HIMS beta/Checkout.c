#include"main.h"
#include<stdio.h>
#include<stdlib.h>
void record(Sroom *room)
{
	FILE *fp;
	char str[9] = "0000.txt";
	int a, b, c;

	a = room->Number / 1000;
	b = (room->Number % 100) / 10;
	c = room->Number % 10;
	str[0] = a + '0';
	str[2] = b + '0';
	str[3] = c + '0';
	if ((fp = fopen(str, "r")) == NULL)
	{
		setColor(ERR, 0);
		printf("房间记录不存在！");
		setColor(7, 0);
	}
	else
	{
		fp = fopen(str, "a");
		fprintf(fp, "\n\n\n\n");
		fprintf(fp, "用户名：%s\n", room->username);
		fprintf(fp, "签入：%d/%d/%d/%d\n", room->yyyy
			, room->mm
			, room->day
			, room->hh);
		fprintf(fp, "签出: %d/%d/%d/%d\n", room->yyyyr
			, room->mmr
			, room->ddr
			, room->hhr);
		fclose(fp);
	}
}
//计算该年某月的天数 
int judge_day(int n, int y)
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
//计算该年的天数 
int judge_day_year(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return 366;
	else
		return 365;
}
void calculate_day(Sroom *room, int *total, int day)
{
	room->day = day;
	room->sum = day * room->Price_day;
	total += room->sum;
}
void calculate_hour(Sroom *room, int *total, int hour)
{
	room->hour = hour;
	room->sum = hour * room->Price_hour;
	total += room->sum;
}
int process_price(Sroom *room, int *total)
{
	int sum_day = 0;
	int sum_hour = 0;
	int i;
	int j;
	int sum_day_extra_front = 0;
	int sum_day_extra_back = 0;

	if (room->yyyyr<room->yyyy)
	{
		setColor(ERR, 0);
		printf("数据错误！（签退日期小于入住日期）\n");
		printf("请重新输入！\n");
		printf("\n\n\n\n");
		setColor(7, 0);
		return 0;
	}
	//计算入住天数； 
	for (i = room->yyyy; i <= room->yyyyr; i++)
	{
		sum_day += judge_day_year(i);

	}
	for (j = 1; j<room->mm; j++)
	{
		sum_day_extra_front += judge_day(j, room->yyyy);
	}
	for (j = room->mmr; j <= 12; j++)
	{
		sum_day_extra_back += judge_day(j, room->yyyyr);
	}
	sum_day = sum_day - sum_day_extra_front - room->dd - sum_day_extra_back + room->ddr - 1;
	if (sum_day<0)
	{
		setColor(ERR, 0);
		printf("数据错误！（签退日期小于入住日期）");
		setColor(7, 0);
		printf("\n");
		return 0;
	}
	if (room->hhr >= 12)//若签退时间超过12点 sum_day增加一天 
		sum_day++;
	if (room->Charge_mode)
	{

		if (sum_day)
		{
			sum_day = sum_day - room->dd + room->ddr;
			sum_hour = sum_day * 24 - room->hh + room->hhr;
		}
		else
		{
			if (room->hhr - room->hh>0)
				sum_hour = (room->ddr - room->dd) * 24 + room->hhr - room->hh;
			else
				sum_hour = 24 - room->hh + room->hhr;
		}
	}
	else
	{
		if (sum_day == 0)
			sum_day = 1;
	}

	if (room->Charge_mode)
	{
		calculate_hour(room, total, sum_hour);
	}
	else
	{
		calculate_day(room, total, sum_day);
	}
	return 1;
}
void change_number(int change)
{
	int a, b, c, d, e, f;

	a = change / 100;
	change %= 100;
	b = change / 50;
	if (b)
		change -= 50;
	c = change / 20;
	if (c == 2)
		change -= 40;
	if (c == 1)
		change -= 20;
	d = change / 10;
	if (d)
		change -= 10;
	e = change / 5;
	if (e)
		change -= 5;
	f = change;
	setColor(sys_tip, 0);
	printf("\n");
	printf("100元:%d张\n50元 ：%d张\n20元 :%d张\n10元 :%d张\n5元 :%d张\n1元 :%d张", a, b, c, d, e, f);
	setColor(7, 0);

}
void change(Sroom *room)
{
	int a = 0;
	while (a == 0)
	{
		setColor(sys_tip, 0);
		printf("\n");
		printf("消费金额：%d元\n", room->sum);
		printf("请输入实收金额：");
		scanf("%d", &room->payment);
		if ((room->payment - room->sum)<0)
		{
			setColor(ERR, 0);
			printf("数据错误！（支付金额小于实际金额）\n");
			printf("请重新输入！");
			printf("\n\n\n\n");
			setColor(7, 0);
			a = 0;
		}
		else
			a = 1;
	}
	printf("\n找零：");
	room->change = room->payment - room->sum;
	printf("%d元", room->change);
	change_number(room->change);
}
void information_search(Sroom *p)
{
	setColor(repeat, 0);
	printf("您的房间信息\n");
	printf("***********************************************************************\n");
	printf("用户名：%s\n", p->username);
	printf("房间号：%d\n", p->Number);
	if (p->Charge_mode)
	{
		printf("收费方式：按小时收费，%d/小时\n", p->Price_hour);
	}
	else
	{
		printf("收费方式：按天收费，%d/天\n", p->Price_day);
	}
	printf("入住时间：%d年%d月%d日%d时\n", p->yyyy, p->mm, p->dd, p->hh);
	printf("预计迁出时间：%d年%d月%d日%d时\n", p->yyyyo, p->mmo, p->ddo, p->hho);
	printf("%d\n", p->deposit);
	printf("***********************************************************************\n");
	setColor(7, 0);
}
void information_checkout(Sroom *room)
{
	printf("\n");
	setColor(repeat, 0);
	printf("您的房间信息\n");
	printf("***********************************************************************\n");
	printf("用户名：%s\n", room->username);
	printf("房间号：%d\n", room->Number);
	if (room->Charge_mode)
	{
		printf("收费方式：按小时收费，%d/小时\n", room->Price_hour);
	}
	else
	{
		printf("收费方式：按天收费，%d/天\n", room->Price_day);
	}
	printf("入住时间：%d年%d月%d日%d时\n", room->yyyy, room->mm, room->dd, room->hh);
	printf("预计迁出时间：%d年%d月%d日%d时\n", room->yyyyo, room->mmo, room->mmo, room->hho);
	printf("实际签退日期：%d年%d月%d日%d时\n", room->yyyyr, room->mmr, room->ddr, room->hhr);
	if (room->Charge_mode)
		printf("入住小时：%d小时\n", room->hour);
	else
		printf("入住天数：%d天\n", room->day);
	printf("定金：%d\n", room->deposit);
	printf("消费金额：%d元\n", room->sum - room->deposit);
	printf("实收金额: %d元\n", room->payment);
	printf("找零:%d元\n", room->change);
	printf("**********************************************************************\n");
	setColor(7, 0);
}
int menu_checkout()
{
	int a;

	system("cls");
	setColor(sys_tip, 0);
	printf("*******************\n");
	printf("* 0.退出   1.签退 *\n");
	printf("*******************\n");
	setColor(7, 0);
	scanf("%d", &a);
	return a;
}
void Delete(Sroom *room, Sroom *temp, Slist *pList)
{
	if (room = temp)    //头节点 
	{
		pList->head = room->next;
		free(room);
	}
	else if (room->next == NULL)    //尾巴 
	{
		temp->next = NULL;
		free(room);
	}
	else     //中间 
	{
		temp->next = room->next;
		free(room);
	}
}
int judge_checkout()
{
	int a;
	setColor(sys_tip, 0);
	printf("0.退出     1.确认签退    2.重新查找\n");
	setColor(sys_tip, 0);
	scanf("%d", &a);
	return a;
}
int search(Slist *list, int *total)
{
	Sroom *p = list->head;
	int number;
	int a;
	int b;
	int c = 0;
	int d = 0;
	Sroom *temp = list->head;
	if (p == NULL)
	{
		setColor(ERR, 0);
		printf("酒店无房间入住！\n");
		printf("请重新选择！\n");
		printf("Press 1 to continue!\n");
		scanf("%d", &d);
		if (d == 1)
			system("cls");
		setColor(7, 0);
		switch (menu_checkout())
		{
		case 0: return 0;
		case 1: break;
		}
	}
	do
	{
		setColor(sys_tip, 0);
		printf("请输入需要签退的房间号：");
		setColor(7, 0);
		scanf("%d", &number);
		if (number<FirstRoom || number>LastRoom)
		{
			setColor(ERR, 0);
			printf("房间不存在！！！\n");
			printf("请重新选择！\n");
			printf("Press 1 to continue!\n");
			scanf("%d", &d);
			if (d == 1)
				system("cls");
			system("cls");
			setColor(7, 0);
			switch (menu_checkout())
			{
			case 0: return 0;
			case 1: break;
			}
		}
		while (p)
		{
			if (p->Number == number)
			{
				setColor(sys_tip, 0);
				printf("查找成功！！！\n");
				information_search(p);
				a = -1;
				break;
			}
			else
			{
				temp = p;
				p = p->next;
			}

			if (p == NULL)
			{
				setColor(ERR, 0);
				printf("未找到房间！！！\n");
				printf("请重新选择！\n");
				printf("Press 1 to continue!\n");
				scanf("%d", &d);
				if (d == 1)
					system("cls");
				system("cls");
				setColor(7, 0);
				switch (menu_checkout())
				{
				case 0: return 0;
				case 1: break;
				}
				switch (menu_checkout())
				{
				case 0: return 0;
				case 1: break;
				}
			}

		}
		if (p == NULL)
		{
			setColor(ERR, 0);
			printf("未找到房间！！！\n");
			setColor(7, 0);
			switch (menu_checkout())
			{
			case 0: return 0;
			case 1: break;
			}
		}
	} while (a != -1);
	b = judge_checkout();
	if (b == 0)
		return 0;
	if (b == 1)
	{
		setColor(sys_tip, 0);
		while (c == 0)
		{
			setColor(sys_tip, 0);
			printf("请输入签退时间（yyyy mm dd hh）：");
			setColor(7, 0);
			scanf("%d%d%d%d", &p->yyyyr, &p->mmr, &p->ddr, &p->hhr);
			c = process_price(p, total);
		}
		change(p);
		information_checkout(p);
		record(p);
		Delete(p, temp, list);
		printf("\n");
		setColor(7, 0);
		return 1;
	}
	if (b == 2)
	{
		return 2;
	}
}
int judge_checkout_success()
{
	int a;

	printf("*************************\n");
	printf("\n");
	printf("   0.退出   1.继续签退   \n");
	printf("\n");
	printf("*************************\n");
	scanf("%d", &a);
	return a;
}
int Checkout(int *total, Slist *list)
{
	int a = 1;
	int b;

	do
	{
		system("cls");
		switch (menu_checkout())
		{
		case 0:
			system("cls");
			return 0;
		case 1:
			b = search(list, total);
			if (b == 0)
			{
				system("cls");
				return 0;
			}

			else if (b == 1)
			{
				setColor(sys_tip, 0);
				printf("签退成功！！！\n");
				switch (judge_checkout_success())
				{
				case 0:
					system("cls");
					return 0;
				case 1: break;
				}
				setColor(7, 0);
			}
			else
				break;
		case 2:break;
		default:break;
		}
	} while (a);
	system("cls");
}