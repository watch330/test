/*调试出现问题 未修复*/
#include"main.h"
#include "Password.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <time.h>
int timejudge(int y, int m, int d, int h, int yo, int mo, int d_o, int ho,int yy,int mm,int dd,int hh)
{
	int i, flag = 0;
	int m1[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int m2[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int m3[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	/*判断输入的时间是否正确*/
	if (y % 4 == 0 && y % 100 || y % 400 == 0)
	{
		for (i = 0; i < 12; i++)
		{
			if (m == m3[i])
			{
				flag = 1;
				if (d > m2[i] || d < 0)
					return 0;
				return 1;
			}
		}
		if (flag != 1)
			return 0;
		
	}
	else
	{
		for (i = 0; i < 12; i++)
		{
			if (m == m3[i])
			{
				flag = 1;
				if (d > m1[i] || d < 0)
					return 0;
				return 1;
			}
		}
		if (flag!=1)
			return 0;
	}
	if (h > 24 || h < 0)
		return 0;
	if (y < yy)
		return 0;
	else
	{
		if (m < mm)
			return 0;
		else
		{
			if (d < dd)
				return 0;
			else
			{
				if (h < hh)
					return 0;
			}
		}
	}
	return 1;
}
int numberjudge(Slist *plist, int num)
{
	Sroom *proom = plist->head;

	if (num > LastRoom || num < FirstRoom)
	{	
		/*setPos(1, 1);
		setColor(ERR, 0);
		printf("错误!请输出"
			"正确的房间号!");
		setColor(7, 0);
		Sleep(2 * delay);
		system("cls");*/
		return 0;
	}
	if ((num / 10 / 10) % 10 != 0)
		return 0;
	while (proom != NULL && proom->Number != num  )
		proom = proom->next;
	if (proom == NULL)
	{
		/*setPos(1, 1);
		setColor(ERR, 0);
		printf("该房间未被使用");
		setColor(7, 0);*/
		return -1;
	}
	return num;
}
void check_print(Slist *plist, int num) //打印房间信息
{
	int i;
	Sroom *proom = plist->head;
	while (proom->Number != num)
		proom = proom->next;
	system("cls");
	setColor(repeat, 0);
	for (i = 10; i < 89; i++)
		tab(i, 1, '*');
	for (i = 10; i < 89; i++)
		tab(i, 16, '*');
	for (i = 2; i < 16; i++)
		tab(9, i, '#');//左右两条边
	for (i = 2; i < 16; i++)
		tab(89, i, '#');
	for (i = 11; i < 88; i++)
		tab(i, 5, '*');  //中间横线
	for (i = 11; i < 88; i++)
		tab(i, 9, '*');
	setColor(7, 0);

	setPos(25, 3);
	printf("房间号:");
	setPos(60, 3);
	printf("用户名:");

	setColor(sys_tip, 0);
	setPos(33, 3);
	printf("%4d", proom->Number);
	setPos(69, 3);
	printf("%s", proom->username);
	setColor(7, 0);
	setPos(25, 7);
	printf("计费方式:");
	if (proom->Charge_mode)
	{
		setPos(35, 7);
		setColor(sys_tip, 0);
		printf("按小时计费\n");
		setColor(7, 0);
	}
	else
	{
		setPos(35, 7);
		setColor(sys_tip, 0);
		printf("按日计费\n");
		setColor(7, 0);
	}
	if (proom->Charge_mode)
	{
		setPos(60, 7);
		printf("价格 :");
		setPos(70, 7);
		setColor(sys_tip, 0);
		printf("%d 元/小时", proom->Price_hour);
		setColor(7, 0);
	}
	else
	{
		setPos(60, 7);
		printf("价格:");
		setPos(70, 7);
		setColor(sys_tip, 0);
		printf("%d 元/天", proom->Price_day);
		setColor(7, 0);
	}
	setPos(25, 11);
	printf("签入时间:");
	setPos(25, 13);
	printf("预计签出时间:");
	setColor(sys_tip, 0);
	setPos(50, 11);
	printf("	%4d年%2d月%2d日%2d时", proom->yyyy, proom->mm, proom->dd, proom->hh);
	setPos(50, 13);
	printf("	%4d年%2d月%2d日%2d时", proom->yyyyo, proom->mmo, proom->ddo, proom->hho);
	setColor(7, 0);
}
int modif_time(Slist *plist)
{	
	int y, m, d, h,num;
	Sroom *proom = plist->head;

	system("cls");
	setColor(sys_tip, 0);
	printf("请输入房间号或输入0退出:\n");
	setColor(7, 0);
	scanf("%d", &num);
	if (num == 0)
		return 0;
	while (numberjudge(plist, num) == 0 || numberjudge(plist, num) == -1)
	{	
		system("cls");
		setColor(sys_tip, 0);
		printf("请重新输入或输入0退出:\n");
		setColor(7, 0);
		scanf("%d", &num);
		if (num == 0)
			return 0;
	}
	while (proom->Number != num)
		proom = proom->next;
	system("cls");
	check_print(plist, num);
	setPos(1, 38);
	setColor(sys_tip, 0);
	printf("请按yyyy/mm/dd/hh格式输入预计签出时间或输入0返回:");
	setColor(7, 0);
	setPos(1, 39);
	scanf("%d", &y);
	if (y == 0)
		return 0;
	scanf("/%d/%d/%d", &m, &d, &h);
	while (!timejudge(y, m, d, h, proom->yyyyo, proom->mmo, proom->ddo, proom->hho, proom->yyyy, proom->mm, proom->dd, proom->hh))
	{
		system("cls");
		check_print(plist, num);
		setPos(1, 38);
		setColor(ERR, 0);
		printf("日期错误!请按yyyy/mm/dd/hh格式重新输入预计签出时间或输入0返回");
		setColor(7, 0);
		setPos(1, 39);
		scanf("%d", &y);
		if (y == 0)
			return 0;
		scanf("/%d/%d/%d", &m, &d, &h);
	}
	proom->yyyyo = y, proom->mmo = m, proom->ddo = d, proom->hho = h;
	system("cls");
	check_print(plist, num);
	setColor(sys_tip, 0);
	setPos(50, 13);
	printf("	%4d年%2d月%2d日%2d时", proom->yyyyo, proom->mmo, proom->ddo, proom->hho);
	setPos(1, 38);
	printf("修改成功!");
	setColor(7, 0);
	Sleep(5 * delay);
	return 1;
}
int modif_price(Slist *plist)
{	
	FILE *fp = NULL;
	int price,num,y,m,d,h;
	Sroom *proom = plist->head;
	char s[24], account[20] = "watch_330";
	time_t t;
	t = time(NULL);
	struct tm *pTime;
	char nowtime[30];

	system("cls");
	setPos(0, 1); 
	setColor(sys_tip, 0);
	printf("请选择房间类型(1,2,3分别代表经济型,舒适型,豪华型房间)或输入0退出\n");
	setColor(7, 0);
	while (~scanf("%d", &num) && num == 0)
	{
		if (num == 0)
			return 0;
		if (num > 3 || num < 1)
		{	
			system("cls");
			setPos(0, 1);
			setColor(ERR, 0);
			printf("错误!请输出正确的数字或输入0退出!\n");
			setColor(7, 0);
			continue;
		}
	}
	system("cls");
	setPos(0, 1);
	switch (num)
	{
	case 1:
		setColor(sys_tip, 0);
		printf("该房间是经济型房间,修改的价格区间为100~250元/日\n");
		printf("请输入价格或0退出:\n");
		setColor(7, 0);
		while (~scanf("%d", &price)) 
		{
			if (price > 250 || price < 100)
			{
				if (price == 0)
					return 0;
				system("cls");
				setPos(0, 1);
				setColor(ERR, 0);
				printf("输入错误,该房间是经济型房间,修改的价格区间为100~250元/日\n");
				setColor(sys_tip, 0);
				printf("请输入价格或0退出:\n"); 
				setColor(7, 0);
			}
			else break;
		}
		break;
	case 2:
		setColor(sys_tip, 0);
		printf("该房间是舒适型房间,修改的价格区间为300~450元/日\n");
		printf("请输入价格或0退出:\n");
		setColor(7, 0);
		while (~scanf("%d", &price))
		{	
			if (price == 0)
				return 0;
			if (price > 450 || price < 300)
			{
				system("cls");
				setPos(0, 1);
				setColor(ERR, 0);
				printf("输入错误,该房间是舒适型房间,修改的价格区间为300~450元/日\n");
				setColor(sys_tip, 0);
				printf("请输入价格或0退出:\n");
				setColor(7, 0);
			}
			else break;
		}
		break;
	case 3:
		setColor(sys_tip, 0);
		printf("该房间是豪华型房间,修改的价格区间为600~750元/日\n");
		printf("请输入价格或0退出:\n");
		setColor(7, 0);
		while (~scanf("%d", &price))
		{
			if (price > 750 || price < 600)
			{
				if (price == 0)
					return 0;
				system("cls");
				setPos(0, 1);
				setColor(ERR, 0);
				printf("输入错误,该房间是豪华型房间,修改的价格区间为600~750元/日\n");
				setColor(sys_tip, 0);
				printf("请输入价格或0退出:\n");
				setColor(7, 0);
			}
			else break;
		}
	}
	if(num==1)
	fp = fopen("data\\Price\\1Price.txt","w");
	if(num==2)
		fp = fopen("data\\Price\\2Price.txt", "w");
	if(num==3)
		fp = fopen("data\\Price\\2Price.txt", "w");
	if (fp == NULL)
	{	
		system("cls");
		setPos(1, 1);
		setColor(ERR, 0);
		printf("文件打开失败!");
		Sleep(5 * delay);
		return 0;
	}
	fprintf(fp, "%d", price);
	setPos(1, 5);
	setColor(sys_tip, 0);
	printf("修改完成!");
	Sleep(5 * delay);
	fclose(fp);
	//时间
	pTime = localtime(&t);
	y = pTime->tm_year + 1900;
	m = pTime->tm_mon + 1;
	d = pTime->tm_mday;
	h = pTime->tm_hour;
	//创建记录
	sprintf(s, "data\\Log\\%dLog.txt", num);
	sprintf(nowtime, "%4d年%2d月%2d日%2d时", y, m, d, h);
	fp = fopen(s, "a+");
	fprintf(fp, "用户名\t:\t%s\n操作\t:\t修改房间价格为%d\n时间\t:\t%s\n\n", account, price, nowtime);
	fclose(fp);

	return 1;
}
void printform(Slist *plist,int num)
{	
	int i;
	system("cls");
	check_print(plist, num);
	setColor(sys_tip, 0);
	for (i = 20; i < 80; i++)
		tab(i, 18, '*');
	for (i = 20; i < 80; i++)
		tab(i, 26, '*');
	for (i = 19; i < 26; i++)
		tab(19, i, '#');
	for (i = 19; i < 26; i++)
		tab(80, i, '#');
	setColor(sys_tip, 0);
	setPos(45, 22);
	printf("2.修改房间价格(未入住房间!!)");
	setColor(7, 0);
	setPos(25, 22);
	setColor(1, 7);
	printf("1.修改签出时间");
}

int search_all(Slist *plist)
{
	Sroom *proom = plist->head;
	int i, flag = 1;

	setColor(repeat, 0);
	for (i = 1; i < 100; i++)
		tab(i, 1, '*');
	i = 3;
	setPos(1, 2);
	printf("房间号\t\t用户名\t\t收费方式   价格\t      签入时间\t\t\t预计签出时间");
	while (proom != NULL)
	{	
		flag = 0;
		setPos(1, i);
		printf("%4d\t\t%s", proom->Number, proom->username);
		if (!proom->Charge_mode)
			printf("\t\t按日收费   %3d ",proom->Price_day);
		else
			printf("\t\t按时收费   %3d ",proom->Price_hour);
		printf("   %4d年%2d月%2d日%2d时\t  ", proom->yyyy, proom->mm, proom->dd, proom->hh);
		printf("   %4d年%2d月%2d日%2d时", proom->yyyyo, proom->mmo, proom->ddo, proom->hho);
		proom = proom->next;
		i++;
	}
	printf("\n");
	if (flag)
	{	
		setPos(1, 2);
		for (i = 1; i <= 100; i++)
			tab(i, 2, ' ');
		setPos(20, 2);
		printf("目前还没有签入房间");
		Sleep(5 * delay);
		return 0;
	}
	for (i = 1; i <=100; i++)
		printf("*");
	setColor(7,0);
	printf("\n请输入任意键返回");
	_getch();

	return flag;
}
int search_number(Slist *plist)
{
	int num, numpr, choice2, i, flag,flag2;
	char ch;

	/*第一次查找成功后显示选项框*/
	setPos(1, 1);
	setColor(sys_tip, 0);
	printf("请输入你想要查询的房间号码或者输入0退出:");
	setColor(7, 0);
	setPos(1, 2);
	scanf("%d", &num);
	if (num == 0)
		return 0;
	flag2 = numberjudge(plist, num);
	while (flag2!=num)
	{	
		system("cls");
		setColor(ERR, 0);
		setPos(1, 1);
		if(flag2==-1)
			printf("房间还未签入,请重新输入你想要查询的房间号码或者输入0退出:");
		if (flag2 == 0)
			printf("房间号码错误,请重新输入(输入0退出):");
		setColor(7, 0);
		setPos(5, 2);
		scanf("%d", &num);
		if (num == 0)
			return 0;
		flag2 = numberjudge(plist, num);
	}
	check_print(plist, num);
	/*第一次查找成功后显示选项框*/
	setColor(sys_tip, 0);
	for (i = 20; i < 80; i++)
		tab(i, 18, '*');
	for (i = 20; i < 80; i++)
		tab(i, 26, '*');
	for (i = 19; i < 26; i++)
		tab(19, i, '#');
	for (i = 19; i < 26; i++)
		tab(80, i, '#');
	setColor(sys_tip, 0);
	setPos(65, 22);
	printf("2.退出");
	setColor(7, 0);
	setPos(25, 22);
	setColor(1, 7);
	printf("1.查询");
	setColor(7, 0);
	flag = 1;
	while (ch = _getch())  //72 80 75 77
	{
		if (ch == 75 || ch == 77 || ch == '\r')
		{
			switch (ch)			//setColor(1.0, 7);
			{
			case 75:
			case 77:
				if (flag == 1)
				{
					setPos(25, 22);
					printf("      ");
					setPos(25, 22);    //刷新1选项
					setColor(sys_tip, 0);
					printf("1.查询");

					setPos(65, 22);
					setColor(1, 7);
					printf("2.退出");  //打印3选项
					setColor(7, 0);
					flag = 2;
					break;
				}
				if (flag == 2)
				{
					setPos(65, 22);
					printf("      "); //刷新3选项
					setPos(65, 22);
					setColor(sys_tip, 0);
					printf("2.退出");

					setPos(25, 22);
					setColor(1, 7);
					printf("1.查询");  //打印2选项
					setColor(7, 0);
					flag = 1;
					break;
				}
			case '\r':
				switch (flag)
				{
				case 2:
					return 0;
				case 1:
					/*选项判断*/
					system("cls");
					check_print(plist, num);
					setColor(sys_tip, 0);
					setPos(1, 38);
					printf("输入待查询房间的号码,或者输入0退出查询");
					setColor(7, 0);
					setPos(1, 39);
					scanf("%d", &choice2);
					if (choice2 == 0)
						break;
					else
					{
							numpr = num;
							num = choice2;
					}
					/*判断房间号*/
					while (numberjudge(plist, num) == 0 || numberjudge(plist, num) == -1)
					{
						system("cls");
						check_print(plist, numpr);
						setColor(ERR, 0);
						setPos(1, 38);
						printf("该房间还未签入,请重新输入你想要查询的房间号码或输入0返回:");
						setColor(7, 0);
						setPos(1, 39);
						scanf("%d", &num);
						if (num == 0)
							break;

					}
					if (num != 0)
						check_print(plist, num);
					if (num == 0)
						num = numpr;
					break;
				case 3:
					system("cls");
					return 0;
				}
				/*再次显示选项框*/
				system("cls");
				check_print(plist, num);
				setColor(sys_tip, 0);
				for (i = 20; i < 80; i++)
					tab(i, 18, '*');
				for (i = 20; i < 80; i++)
					tab(i, 26, '*');
				for (i = 19; i < 26; i++)
					tab(19, i, '#');
				for (i = 19; i < 26; i++)
					tab(80, i, '#');
				setColor(sys_tip, 0);
				setPos(65, 22);
				printf("2.退出");
				setColor(7, 0);
				setPos(25, 22);
				setColor(1, 7);
				printf("1.查询");
				setColor(7, 0);
				flag = 1;
			default:
				break;
			}
		}
	}
	return 0;
}
int Search(Slist *plist)
{
	static pflag = 1;
	int i, flag;
	char ch;
	system("cls");
	setPos(20, 1);
	for (i = 0; i < 60; i++)
		printf("*");
	for (i = 20; i < 80; i++)
		tab(i, 12, '*');
	for (i = 2; i < 12; i++)
		tab(19, i, '#');
	for (i = 2; i < 12; i++)
		tab(80, i, '#');
	setColor(sys_tip, 0);
	setPos(1, 1);
	printf("Esc退出");
	setPos(55, 3);
	printf("2.按照房间号查询");
	setPos(55, 9);
	printf("4.修改房间价格");
	setPos(25, 9);
	printf("3.修改签出时间");
	setColor(7, 0);
	setPos(25, 3);
	setColor(1, 7);
	printf("1.查询所有已签入的房间");
	setColor(7, 0);
	flag = 1;

	while (ch = _getch())  //72 80 75 77
	{
		if (ch == 72 || ch == 80 || ch == 27 || ch == 75 || ch == 77 || ch == '\r')
		{
			switch (ch)
			{
			case 75:
				if (flag == 1)
				{
					setPos(25, 3);
					printf("                     ");
					setPos(25, 3);    //刷新1选项
					setColor(sys_tip, 0);
					printf("1.查询所有已签入的房间");

					setPos(55, 9);
					setColor(1, 7);
					printf("4.修改房间价格");
					setColor(7, 0);
					flag = 4;
					break;


				}
				if (flag == 2)
				{
					setPos(55, 3);
					printf("                ");  //刷新2选项
					setColor(sys_tip, 0);
					setPos(55, 3);
					printf("2.按照房间号查询");

					setPos(25, 3);
					setColor(1, 7);
					printf("1.查询所有已签入的房间");
					setColor(7, 0);
					flag = 1;
					break;


				}
				if (flag == 3)
				{
					setPos(25, 9);
					printf("              ");
					setPos(25, 9);
					setColor(sys_tip, 0);
					printf("3.修改签出时间");

					setPos(55, 3);
					setColor(1, 7);
					printf("2.按照房间号查询");  //打印2选项
					setColor(7, 0);
					flag = 2;
					break;
				}
				if (flag == 4)
				{
					setPos(55, 9);
					printf("              ");
					setPos(55, 9);
					setColor(sys_tip, 0);
					printf("4.修改房间价格");

					setPos(25, 9);
					setColor(1, 7);
					printf("3.修改签出时间");  //打印3选项;
					setColor(7, 0);
					flag = 3;
					break;
				}
			case 77:
				if (flag == 1)
				{
					setPos(25, 3);
					printf("                     ");
					setPos(25, 3);    //刷新1选项
					setColor(sys_tip, 0);
					printf("1.查询所有已签入的房间");

					setPos(55, 3);
					setColor(1, 7);
					printf("2.按照房间号查询");  //打印2选项
					setColor(7, 0);
					flag = 2;
					break;
				}
				if (flag == 2)
				{
					setPos(55, 3);
					printf("                ");  //刷新2选项
					setColor(sys_tip, 0);
					setPos(55, 3);
					printf("2.按照房间号查询");

					setPos(25, 9);
					setColor(1, 7);
					printf("3.修改签出时间");  //打印3选项;
					setColor(7, 0);
					flag = 3;
					break;
				}
				if (flag == 3)
				{
					setPos(25, 9);
					printf("              ");
					setPos(25, 9);
					setColor(sys_tip, 0);
					printf("3.修改签出时间");

					setPos(55, 9);
					setColor(1, 7);
					printf("4.修改房间价格");
					setColor(7, 0);
					flag = 4;
					break;
				}
				if (flag == 4)
				{
					setPos(55, 9);
					printf("              ");
					setPos(55, 9);
					setColor(sys_tip, 0);
					printf("4.修改房间价格");

					setPos(25, 3);
					setColor(1, 7);
					printf("1.查询所有已签入的房间");
					setColor(7, 0);
					flag = 1;
					break;
				}
			case '\r':
				switch (flag)
				{
				case 1:
					system("cls");
					search_all(plist);
					break;
				case 2:
					system("cls");
					search_number(plist);
					break;
				case 3:
					modif_time(plist);
					break;
				case 4:
					if (pflag) 
					{
						if (Password() == 1)
							pflag = 0;
					}
					if (!pflag)
						modif_price(plist);
					break;
				default:
					break;
				}
				system("cls");
				setColor(sys_tip, 0);
				setPos(20, 1);
				for (i = 0; i < 60; i++)
					printf("*");
				for (i = 20; i < 80; i++)
					tab(i, 12, '*');
				for (i = 2; i < 12; i++)
					tab(19, i, '#');
				for (i = 2; i < 12; i++)
					tab(80, i, '#');
				setPos(1, 1);
				printf("Esc退出");
				setPos(55, 3);
				printf("2.按照房间号查询");
				setPos(55, 9);
				printf("4.修改房间价格");
				setPos(25, 9);
				printf("3.修改签出时间");
				setColor(7, 0);
				setPos(25, 3);
				setColor(1, 7);
				printf("1.查询所有已签入的房间");
				setColor(7, 0);
				flag = 1;
				setColor(7, 0);
				break;
			case 27:
				system("cls");
				return 0;
			default:
				break;
			}
		}

	}
	return 0;
}

