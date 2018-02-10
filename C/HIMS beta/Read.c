#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
void Read(Slist *pList) {
	FILE *fp = fopen("List", "r");
	char s[24];
	int Number;

	if (fp) {
		while (~fscanf(fp, "%d", &Number)) {
			//creat a room
			Sroom *p = (Sroom*)malloc(sizeof(Sroom));
			if (p == NULL)
			{
				setColor(ERR, 0);
				printf("ERROR:memory limit exceeded\n");
				setColor(7, 0);
				exit(0);
			}
			//enter the information
			p->Number = Number;
			fscanf(fp, "%s", s);
			p->username = malloc(sizeof(strlen(s) + 1));
			strcpy(p->username, s);
			fscanf(fp, "%d", &p->Charge_mode);
			if (p->Charge_mode)
				fscanf(fp, "%d", &p->Price_hour);
			else
				fscanf(fp, "%d", &p->Price_day);
			fscanf(fp, "%d%d%d%d", &p->yyyy, &p->mm, &p->dd, &p->hh);
			fscanf(fp, "%d%d%d%d", &p->yyyyo, &p->mmo, &p->ddo, &p->hho);
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
	}
}