#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include "main.h"
void print_form()
{
	int i;
	//��ӡ�߿�
	for (i = 1; i <= 20; i++)
		tab(i, 33, '*');
	setPos(7, 33);
	printf("������֤");
	for (i = 1; i <= 20; i++)
		tab(i, 39, '*');
	for (i = 33; i <= 39; i++)
		tab(1, i, '*');
	for (i = 33; i <= 39; i++)
		tab(20, i, '*');

	setPos(3, 37);
	printf("����:");
	setPos(3, 35);
	printf("�˺�:");
}
int acc_enter(char _acc[])
{
	int i=0, count=0;
	char ch;

	setPos(8, 35);
	while (ch = _getch())
	{
		if (ch >= '0'&&ch <= '9')
		{
			_acc[i] = ch;
			printf("%c",ch);
			count++;
			i++;
		}
		if (ch == 75 || ch == 77 || ch == 72 || ch == 80)
			continue;
		if (ch >= 'A'&&ch <= 'Z')
		{
			_acc[i] = ch;
			printf("%c",ch);
			count++;
			i++;
		}
		if (ch >= 'a'&&ch <= 'z')
		{
			_acc[i] = ch;
			printf("%c",ch);
			count++;
			i++;
		}
		if (ch == '_')
		{
			_acc[i] = ch;
			printf("%c",ch);
			count++;
			i++;
		}
		if (ch == '\b')
		{
			if (count != 0)
			{
				printf("\b \b");
				count--;
			}
		}
		if (ch == 27)
			return 0;
		if (ch == '\r')
			break;
	}
	
	_acc[i] = '\0';

	return 1;
}
int pass_enter(char _pass[])
{
	int i = 0, count = 0;
	char ch;

	setPos(8, 37);
	while (ch = _getch())
	{
		if (ch >= '0'&&ch <= '9')
		{
			_pass[i] = ch;
			printf("*");
			count++;
			i++;
		}
		if (ch == 75 || ch == 77 || ch == 72 || ch == 80)
			continue;
		if (ch >= 'A'&&ch <= 'Z')
		{
			_pass[i] = ch;
			printf("*");
			count++;
			i++;
		}
		if (ch >= 'a'&&ch <= 'z')
		{
			_pass[i] = ch;
			printf("*");
			count++;
			i++;
		}
		if (ch == '_')
		{
			_pass[i] = ch;
			printf("*");
			count++;
			i++;
		}
		if (ch == '\b')
		{
			if (count != 0)
			{
				printf("\b \b");
				count--;
			}
		}
		if (ch == 27)
			return 0;
		if (ch == '\r')
			break;
	}

	_pass[i] = '\0';
	return 1;
}
void print_err()
{
	int i;
	print_form();
	setPos(2, 37);
	for (i = 0; i < 18; i++)
		printf(" ");
	setPos(2, 35);
	for (i = 0; i < 18; i++)
		printf(" ");
	setPos(7, 36);
	setColor(ERR, 0);
	printf("��֤ʧ��!");
	setColor(7, 0);
}
void print_cor()
{
	int i;
	print_form();
	setPos(2, 37);
	for (i = 0; i < 18; i++)
		printf(" ");
	setPos(2, 35);
	for (i = 0; i < 18; i++)
		printf(" ");
	setPos(7, 36);
	setColor(repeat, 0);
	printf("��֤�ɹ�!");
	setColor(7, 0);
}
int Password()
{
	char account[20] = "watch_330", password[20] = "330250";
	char _acc[20], _pass[20];

	print_form();
	if ((acc_enter(_acc)) == 0)
		return 0;
	if ((pass_enter(_pass)) == 0)
		return 0;
	if (strcmp(_pass, password) || strcmp(_acc, account))
	{
		print_err();
		setPos(7, 36);
		printf("         ");
		setPos(3, 35);
		setColor(ERR, 0);
		printf("�û������������!");
		setPos(7, 36);
		printf("��֤����!");
		setColor(7, 0);
		Sleep(5 * delay);
		return 0;
	}
	print_cor();
	Sleep(5 * delay);
	return 1;
}