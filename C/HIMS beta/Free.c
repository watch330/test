#include <stdlib.h>
#include "main.h"
void Free(Slist *pList) {
	Sroom *p, *i = pList->head;
	while (i) {
		p = i->next;
		free(i);
		i = NULL;
		i = p;
	}
}