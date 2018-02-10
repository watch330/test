#include <stdio.h>
#include "main.h"
void Save(Slist *pList) {
	Sroom *p = pList->head;
	FILE *fp = fopen("List", "w");
	while (p) {
		fprintf(fp, "%d\n", p->Number);
		fprintf(fp, "%s\n", p->username);
		fprintf(fp, "%d\n", p->Charge_mode);
		if (p->Charge_mode)
			fprintf(fp, "%d\n", p->Price_hour);
		else
			fprintf(fp, "%d\n", p->Price_day);
		fprintf(fp, "%d %d %d %d\n", p->yyyy, p->mm, p->dd, p->hh);
		fprintf(fp, "%d %d %d %d\n\n", p->yyyyo, p->mmo, p->ddo, p->hho);
		p = p->next;
	}
}