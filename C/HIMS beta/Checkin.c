#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "main.h"

int Checkdate(int y, int m, int d, int h, int *m1, int *m2)
{
	if (y < min_yyyy)return 1;
	if (m < 1 || m>12)return 2;
	if (y % 4 == 0 && y % 100 || y % 400 == 0)
		if (d > m1[m] || d < 1)return 3;
		else
			if (d > m2[m] || d < 1)return 3;
	if (h < 1 || h>24)return 4;
	return 0;
}
int judge(int y, int yo, int m, int mo, int d, int doo, int h, int ho, int *m1, int *m2)
{
	if (Checkdate(yo, mo, doo, ho, m1, m2))return 1;
	if (y > yo)return 1;
	if (y == yo)
	{
		if (m > mo)return 2;
		if (m == mo)
		{
			if (d > doo)return 3;
			if (d == doo)
				if (ho - h < 12)return 4;
		}
	}
	if (yo >= y + 1)return 5;
	if (mo > m + 1)return 6;
	if (mo > m)
	{
		if (y % 4 == 0 && y % 100 || y % 400 == 0)
		{
			if (m2[m] - d + doo > 7)return 7;
			if (m2[m] - d + doo == 7)
				if (ho - h >= 12)return 8;
		}
		else
		{
			if (m1[m] - d + doo > 7)return 7;
			if (m1[m] - d + doo == 7)
				if (ho - h >= 12)return 8;
		}
	}
	else
		if (doo > d + 7)
			return 7;
	return 0;
}
void dlt(int x1, int y1, int x2, int y2)
{
	int i, j;
	for (i = x1; i <= x2; i++)
		for (j = y1; j <= y2; j++)
			tab(i, j, ' ');
}
void DLT_tip(void)
{
	dlt(0, 0, 19, 1);
	setPos(0, 0);
	setColor(sys_tip, 0);
}
void DLT_price(void)
{
	dlt(30, 8, 52, 8);
	setPos(30, 8);
}
void DLT_ERR(void)
{
	dlt(0, 14, 30, 16);
	setPos(0, 14);
	setColor(ERR, 0);
}
void DLT_date(int y)
{
	int i, j = 0;
	dlt(30, y, 45, y);
	setColor(sys_tip, 0);
	tab(78, y, '|');
	while (j = (j == 34 ? 38 : j == 38 ? 42 : j == 42 ? 46 : j == 46 ? 0 : 34))
	{
		for (i = 10; i < 13; i += 2)
		{
			setPos(j, i);
			if (j == 34)
				printf("年");
			if (j == 38)
				printf("月");
			if (j == 42)
				printf("日");
			if (j == 46)
				printf("时");
		}
	}
	setColor(7, 0);
	setPos(30, y);
}
void ChooseChargeMode(int *x, int dd, int hh)
{
	int y = 6;
	if (*x == 30)
	{
		DLT_ERR();
		setColor(repeat, 0);
		printf("您选择了：\n按日计费\n");
		setPos(54, y);
		setColor(7, 0);
		printf("按小时计费");
		DLT_price();
		printf("%-3d 元 / 天", dd);
		dlt(*x, y, 52, y);
		setPos(*x, y);
		setColor(0, 15);
		printf("按日计费");
		setColor(7, 0);
		*x = 54;
	}
	else
	{
		DLT_ERR();
		setColor(repeat, 0);
		printf("您选择了：\n按小时计费\n");
		setPos(30, y);
		setColor(7, 0);
		printf("按日计费");
		DLT_price();
		printf("%-3d 元 / 小时", hh);
		dlt(53, y, 77, y);
		setPos(*x, y);
		setColor(0, 15);
		printf("按小时计费");
		setColor(7, 0);
		*x = 30;
	}
}
void ShowRoom(Sroom *p)
{
	int i, j = 0;
	setColor(sys_tip, 0);
	while (j = (j == 20 ? 29 : j == 29 ? 78 : j == 78 ? 0 : 20))
	{
		i = 1;
		if (j == 29)
			i = 4;
		while (i < 14)
			tab(j, i++, '|');
	}
	for (j = 1; j < 14; j++, j++)
		for (i = 20; i < 79; i++)
			tab(i, j, '-');
	setPos(44, 2);
	printf("%4d号房间", p->Number);
	setPos(22, 4);
	printf("用户名");
	setPos(21, 6);
	printf("计费方式");
	setPos(23, 8);
	printf("价格");
	while (j = (j == 34 ? 38 : j == 38 ? 42 : j == 42 ? 46 : j == 46 ? 0 : 34))
	{
		for (i = 10; i < 13; i += 2)
		{
			setPos(j, i);
			if (j == 34)
				printf("年");
			if (j == 38)
				printf("月");
			if (j == 42)
				printf("日");
			if (j == 46)
				printf("时");
		}
	}
	setPos(21, 10);
	printf("签入日期");
	setPos(21, 12);
	printf("签出日期");
	setColor(7, 0);
}
void GetDate(Sroom *p, int y)
{
	int flag = 0, x = 30, c = 0, n = 0;
	char key;
	while (key = _getch())
	{
		if ('0' <= key && key <= '9'&& flag != 4 || key == '\b')
		{
			DLT_ERR();
			setColor(7, 0);
			setPos(x, y);
			if (flag == 0)
			{
				if (key == '\b') {
					if (c > 0)c--;
					if (x > 30) {
						x--;
						printf("\b \b");
					}
					n /= 10;
				}
				else
					if (c < 4)
					{
						n *= 10;
						n += key - '0';
						c++; x++;
						printf("%c", key);
					}
					else
					{
						if (y == 10)
							p->yyyy = n;
						else
							p->yyyyo = n;
						flag++;
						setPos(x = 36, y);
						n = c = 0;
					}
			}
			else if (flag == 1)
			{
				if (key == '\b') {
					if (c > 0)c--;
					if (x > 36) {
						x--;
						printf("\b \b");
					}
					n /= 10;
				}
				else
					if (c < 2)
					{
						n *= 10;
						n += key - '0';
						c++; x++;
						printf("%c", key);
					}
					else
					{
						if (y == 10)
							p->mm = n;
						else
							p->mmo = n;
						flag++;
						setPos(x = 40, y);
						n = c = 0;
					}
			}
			else if (flag == 2)
			{
				if (key == '\b') {
					if (c > 0)c--;
					if (x > 40) {
						x--;
						printf("\b \b");
					}
					n /= 10;
				}
				else
					if (c < 2)
					{
						n *= 10;
						n += key - '0';
						c++; x++;
						printf("%c", key);
					}
					else
					{
						if (y == 10)
							p->dd = n;
						else
							p->ddo = n;
						flag++;
						setPos(x = 44, y);
						n = c = 0;
					}
			}
			else if (flag == 3)
			{
				if (key == '\b') {
					if (c > 0)c--;
					if (x > 44) {
						x--;
						printf("\b \b");
					}
					n /= 10;
				}
				else
					if (c < 2)
					{
						n *= 10;
						n += key - '0';
						c++; x++;
						printf("%c", key);
					}
					else
					{
						if (y == 10)
							p->hh = n;
						else
							p->hho = n;
						flag++;
						setPos(x = 46, y);
						n = c = 0;
					}
			}

		}
		if (key == '\r' || key == ' ')
		{
			if (flag == 0)
				if (c == 0)
					setPos(x = 30, y);
				else
				{
					flag++;
					setPos(x = 36, y);
					if (y == 10)
						p->yyyy = n;
					else
						p->yyyyo = n;
					n = c = 0;
				}
			else if (flag == 1)
				if (c == 0)
					setPos(x = 36, y);
				else
				{
					flag++;
					setPos(x = 40, y);
					if (y == 10)
						p->mm = n;
					else
						p->mmo = n;
					n = c = 0;
				}
			else if (flag == 2)
				if (c == 0)
					setPos(x = 40, y);
				else
				{
					flag++;
					setPos(x = 44, y);
					if (y == 10)
						p->dd = n;
					else
						p->ddo = n;
					n = c = 0;
				}

			else if (flag == 3)
				if (c == 0)
					setPos(x = 44, y);
				else
				{
					flag++;
					setPos(x = 45, y);
					if (y == 10)
						p->hh = n;
					else
						p->hho = n;
					n = c = 0;
				}
			if (flag == 4)
				return;
		}
	}
}
void information(Sroom *p)
{
	int m1[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	int m2[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int dd, hh, c, flag = 0, x, y;
	char key, s[24];
	struct tm *pTime;
	time_t t;

	system("cls");
	ShowRoom(p);

	DLT_tip();
	printf("请输入用户名");
	setPos(x = 30, y = 4);
	setColor(7, 0);
	s[0] = '\0';
	flag = c = 0;   //用户名
	do
	{
		while (key = _getch(), 'a' <= key && key <= 'z' || 'A' <= key && key <= 'Z')
		{
			s[c] = key;
			x++;
			printf("%c", key);
			s[++c] = '\0';
			if (c > 20)
				break;
		}
		if (key < 0)
			_getch();
		if (key == '\b')
		{
			if (c)
			{
				if ('0' <= s[--c] && s[c] <= '9')
					flag--;
				s[c] = '\0';
				tab(--x, y, ' ');
				setPos(x, y);
			}
			else
				s[c] = '\0';
			if (c < 21)
				DLT_ERR();
			if (flag)
			{
				DLT_ERR();
				printf("ERROR:无效的用户名\n");
				printf("用户名不应包含数字");
				setColor(7, 0);
			}
			else
				DLT_ERR();
			setColor(7, 0);
			setPos(x, y);
		}

		if ('0' <= key && key <= '9')
		{
			s[c] = key;
			x++;
			printf("%c", key);
			s[++c] = '\0';
			if (c > 21)
				break;
			DLT_ERR();
			printf("ERROR:无效的用户名\n");
			printf("用户名不应包含数字");
			setPos(x, y);
			setColor(7, 0);
			flag++;
		}
		if (c > 20)
		{
			c--;
			s[c] = '\0';
			tab(--x, y, ' ');
			setPos(x, y);
			DLT_ERR();
			printf("ERROR:无效的用户名\n");
			printf("用户名的长度不应超过二十字节");
			setPos(x, y);
			setColor(7, 0);
		}
	} while (key != '\r' || !strlen(s) || flag);

	flag = 0;
	printf("\n");
	setColor(sys_tip, 0);
	setPos(20 + (51 - strlen(s)) / 2, 0);
	p->username = malloc(sizeof(strlen(s) + 1));
	strcpy(p->username, s);
	printf("欢迎您,%s", p->username);

	DLT_tip();
	printf("请选择计费方式");
	setPos(x = 30, y = 6);
	setColor(7, 0);

	srand((unsigned int)time(NULL));
	dd = 250 + rand() % 100; hh = dd / 24;
	setPos(30, y);
	setColor(7, 0);
	printf("按日计费");
	setPos(x = 54, y);
	printf("按小时计费");
	setColor(7, 0);
	DLT_price();
	printf("%-3d 元 / 天", dd);
	setPos(38, y);

	do
	{
		while (key = _getch(), key == 77 || key == 75)
			ChooseChargeMode(&x, dd, hh);
	} while (key != '\r');
	p->Charge_mode = x == 30 ? 1 : 0;
	dlt(30, y, 77, y);
	setPos(30, y);
	if (x == 54)
	{
		printf("按日计费");
		p->Price_day = dd;
	}
	else
	{
		printf("按小时计费");
		p->Price_hour = hh;
	}

	DLT_ERR();
	DLT_tip();

	/*
	printf("请输入签入日期\nyyyy mm dd hh");
	setColor(7, 0);
	do {
	if (flag)
	{
	DLT_ERR();
	printf("ERROR:无效的日期\n");
	switch (flag)
	{
	case 1:
	printf("不合理的年份\n");
	printf("年份应至少为2017\n");
	break;
	case 2:
	printf("不合理的月份\n");
	break;
	case 3:
	printf("不合理的日子\n");
	break;
	default:
	printf("不合理的小时\n");
	}
	DLT_tip();
	printf("请重新输入签入日期\nyyyy mm dd hh\n");
	DLT_date(y);
	}
	setPos(x = 30, y = 10);
	GetDate(p, y);
	} while (flag = Checkdate(p->yyyy, p->mm, p->dd, p->hh, m1, m2));
	*/

	t = time(NULL);
	pTime = localtime(&t);
	p->yyyy = pTime->tm_year + 1900;
	p->mm = pTime->tm_mon + 1;
	p->dd = pTime->tm_mday;
	p->hh = pTime->tm_hour;
	setPos(30, 10); printf("%d", p->yyyy);
	setPos(36, 10); printf("%d", p->mm);
	setPos(40, 10); printf("%d", p->dd);
	setPos(44, 10); printf("%d", p->hh);

	DLT_ERR();
	setColor(repeat, 0);
	printf("您的签入日期为\n%4d年%2d月%2d日%2d时\n", p->yyyy, p->mm, p->dd, p->hh);
	setColor(7, 0);


	flag = 0;
	p->next = NULL;

	DLT_tip();
	printf("请输入预计的签出日期\nyyyy mm dd hh:\n");
	setColor(7, 0);
	do
	{
		if (flag)
		{
			DLT_ERR();
			printf("ERROR:无效的日期\n");
			switch (flag)
			{
			case 1:
				printf("过小的年份\n");
				break;
			case 2:
				printf("过小的月份\n");
				break;
			case 3:
				printf("过小的日子\n");
				break;
			case 4:
				printf("过小的小时\n");
				printf("入住时长不应小于十二小时\n");
				break;
			case 5:
				printf("过大的年份\n");
				break;
			case 6:
				printf("过大的月份\n");
				break;
			case 7:
				printf("过大的日子\n");
				break;
			default:
				printf("过大的小时\n");
			}
			if (flag == 5 || flag == 6 || flag == 7)
				printf("入住时长不应超过七天\n");
			DLT_tip();
			printf("请重新输入签出日期\nyyyy mm dd hh");
			DLT_date(y);
		}
		setPos(x = 30, y = 12);
		GetDate(p, y);
	} while (flag = judge(p->yyyy, p->yyyyo, p->mm, p->mmo, p->dd, p->ddo, p->hh, p->hho, m1, m2));

	DLT_tip();
	printf("签入成功");
	DLT_ERR();
	setColor(repeat, 0);
	printf("您的房间信息:\n\n房间号		：	%d\n", p->Number);
	printf("用户		：	%s\n", p->username);
	printf("计费方式	：	");
	if (p->Charge_mode)
	{
		printf("按小时计费\n");
		printf("价格		：	%d 元 / 小时\n", p->Price_hour);
	}
	else
	{
		printf("按日计费\n");
		printf("价格		：	%d 元 / 天\n", p->Price_day);
	}
	printf("签入日期	：	%4d年%2d月%2d日%2d时\n", p->yyyy, p->mm, p->dd, p->hh);
	printf("预计签出日期	：	%4d年%2d月%2d日%2d时\n", p->yyyyo, p->mmo, p->ddo, p->hho);

	setColor(sys_tip, 0);
	printf("\n请输入0以返回菜单\n");
	setColor(7, 0);
	while (~scanf("%d", &c), c != 0);
	system("cls");
}
void ADD(Slist *pList, int n)
{
	//creat a room
	Sroom *p = (Sroom*)malloc(sizeof(Sroom));
	if (p == NULL)
	{
		setColor(ERR, 0);
		printf("ERROR:memory limit exceeded\n");
		setColor(7, 0);
		exit(0);
	}
	p->Number = n;
	//enter the information
	information(p);
	//attach
	if (pList->head)
	{
		if (pList->head == pList->tail)
		{
			pList->head->next = p;
		}
		pList->tail->next = p;
		pList->tail = p;
	}
	else
		pList->head = pList->tail = p;
	p->next = NULL;
}
int Checklist(Slist *pList, int n)
{
	//check the list
	Sroom *x;
	if (pList->head)
	{
		x = pList->head;
		while (x)
			if (x->Number == n)
			{
				setColor(sys_tip, 0);
				printf("该房间已被预定\n请选择其他房间\n");
				setColor(7, 0);
				return 1;
			}
			else
				x = x->next;
	}
	return 0;
}
void Prtlist(Slist *pList)
{
	Sroom *x = pList->head;
	int c = 0;
	if (x)
		printf("以下房间已被预定：\n");
	while (x)
	{
		printf("%-6d", x->Number);
		c++;
		if (c % 10 == 0)
			printf("\n");
		x = x->next;
	}
	if (c)
		printf("\n");
}
void Checkin(Slist *pList)
{
	int n, f;
	setColor(sys_tip, 0);
	Prtlist(pList);
	printf("请输入房间号（1000 ~ 3099）\n");
	setColor(7, 0);
	do
	{
		scanf("%d", &n);
		if (n >= FirstRoom && n <= LastRoom)
		{
			while (Checklist(pList, n))//reservation?
			{
				do
				{
					scanf("%d", &n);
					if (n < FirstRoom || n > LastRoom)
					{
						setColor(ERR, 0);
						printf("ERROR:无效的房间号，请重新选择\n");
						setColor(7, 0);
					}
				} while (n < FirstRoom || n > LastRoom);
			}
			setColor(repeat, 0);
			printf("您的房间号为\n%4d\n", n);
			setColor(7, 0);
			ADD(pList, n);
			f = 0;
		}
		else
		{
			setColor(ERR, 0);
			printf("ERROR:无效的房间号，请重新选择\n");
			setColor(7, 0);
			f = 1;
		}
	} while (f);
}