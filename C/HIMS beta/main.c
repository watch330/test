#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "Save.h"
#include "Read.h"
#include "Free.h"

int main()
{
	Slist list;
	list.head = list.tail = NULL;
	system("mode con  cols=100 lines=40");

	Read(&list);

	menu(&list);

	Save(&list);

	{ //test code
		Sroom *i = list.head;
		while (i) {
			setColor(repeat, 0);
			printf("房间号		:	%d\n", i->Number);
			printf("用户		：	%s\n", i->username);
			printf("计费方式	:	");
			if (i->Charge_mode)
			{
				printf("按小时计费\n");
				printf("价格		:	%d 元/小时\n", i->Price_hour);
			}
			else
			{
				printf("按日计费\n");
				printf("价格		:	%d 元/天\n", i->Price_day);
			}
			printf("签入日期	:	%4d年%2d月%2d日%2d时\n", i->yyyy, i->mm, i->dd, i->hh);
			printf("预计签出日期	:	%4d年%2d月%2d日%2d时\n\n", i->yyyyo, i->mmo, i->ddo, i->hho);
			setColor(7, 0);
			i = i->next;
		}
	}
	Free(&list);
}