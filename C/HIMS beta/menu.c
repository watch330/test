#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "main.h"
#include "Checkin.h"
#include "Search.h"
#include "Checkout.h"
#include "Statement.h"

void Showkuang(int flag) {
	int i;
	setColor(sys_tip, 0);
	for (i = 10; i < 34; i++)
		tab(i, 1, '*');
	printf("Hotel_Information_Manager_System");
	for (i = 66; i < 89; i++)
		tab(i, 1, '*');
	for (i = 10; i < 89; i++)
		tab(i, 9, '*');
	for (i = 2; i < 9; i++)
		tab(9, i, '#');
	for (i = 2; i < 9; i++)
		tab(89, i, '#');
	setColor(7, 0);
	if (flag)
		Sleep(delay);
	setPos(25 - 1, 3);
	printf(" 签入 ");
	setPos(65 - 1, 3);
	printf(" 查询 ");
	if (flag)
		Sleep(delay);
	setPos(25 - 1, 5);
	printf(" 签出 ");
	setPos(65 - 1, 5);
	printf(" 结算 ");
	if (flag)
		Sleep(delay);
	setPos(45 - 1, 7);
	printf(" 退出 ");
	setPos(29, 3);
}
void ShowMenu(char key, int *x, int *y) {
	Showkuang(0);
	switch (key)
	{
	case 72:
		if (*x + *y == 30) {
			setPos(*x = 25, *y = 3);
			break;
		}
		if (*x + *y == 70) {
			setPos(*x = 65, *y = 3);
			break;
		}
		if (*x + *y == 52) {
			setPos(*x = 25, *y = 5);
			break;
		}
		if (*x + *y == 28 || *x + *y == 68) {
			setPos(*x, *y);
			break;
		}
	case 80:
		if (*x + *y == 28) {
			setPos(*x = 25, *y = 5);
			break;
		}
		if (*x + *y == 68) {
			setPos(*x = 65, *y = 5);
			break;
		}
		if (*x + *y == 30 || *x + *y == 70) {
			setPos(*x = 45, *y = 7);
			break;
		}
		if (*x + *y == 52) {
			setPos(*x, *y);
			break;
		}
	case 75:
		if (*x + *y == 68) {
			setPos(*x = 25, *y = 3);
			break;
		}
		if (*x + *y == 70) {
			setPos(*x = 25, *y = 5);
			break;
		}
		if (*x + *y == 28 || *x + *y == 30) {
			setPos(*x, *y);
			break;
		}
		if (*x + *y == 52) {
			setPos(*x = 25, *y = 5);
			break;
		}
	case 77:
		if (*x + *y == 28) {
			setPos(*x = 65, *y = 3);
			break;
		}
		if (*x + *y == 30) {
			setPos(*x = 65, *y = 5);
			break;
		}
		if (*x + *y == 68 || *x + *y == 70) {
			setPos(*x, *y);
			break;
		}
		if (*x + *y == 52) {
			setPos(*x = 65, *y = 5);
			break;
		}
	}
	switch (*x + *y)
	{
	case 28:
		setPos(*x - 1, *y);
		setColor(0, 15);
		printf(" 签入 ");
		setColor(7, 0);
		break;
	case 68:
		setPos(*x - 1, *y);
		setColor(0, 15);
		printf(" 查询 ");
		setColor(7, 0);
		break;
	case 30:
		setPos(*x - 1, *y);
		setColor(0, 15);
		printf(" 签出 ");
		setColor(7, 0);
		break;
	case 70:
		setPos(*x - 1, *y);
		setColor(0, 15);
		printf(" 结算 ");
		setColor(7, 0);
		break;
	case 52:
		setPos(*x - 1, *y);
		setColor(0, 15);
		printf(" 退出 ");
		setColor(7, 0);
	}
	setColor(sys_tip, 0);
	tab(*x - 1, *y, '*');
	tab(*x + 4, *y, '*');
}

void PRT_END(void) {
	setPos(40, 7);
	setColor(sys_tip, 0);
	printf("*欢迎再次使用*\n");
}

void menu(Slist *pList)
{
	int x = 25, y = 3, TOTAL;
	char key;
	Showkuang(1);
	while (key = _getch())
		if (key == 72 || key == 80 || key == 75 || key == 77 || key == '\r')
			if (key == '\r') {
				system("cls");
				switch (x + y)
				{
				case 28:
					Checkin(pList);
					break;
				case 68:
					Search(pList);
					break;
				case 30:
					Checkout(&TOTAL, pList);
					break;
				case 70:
					Statement(&TOTAL,pList);
					break;
				case 52:
					PRT_END();
					setPos(40, 8);
					return;
				}
				Showkuang(1);
			}
			else
				ShowMenu(key, &x, &y);
}
/*
9************************Hotel_Information_Manager_System***********************
2#               25                                      65                      #
#             3 签入                                    查询                    #
#                                                                               #
#             5 签出                                    结算                    #
#                                   45                                          #
#                                  7退出                                        #
#                                                                               #
*******************************************************************************
*/