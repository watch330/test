#include "main.h"
void process(struct student stu[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		stu[i].grade = (int)(stu[i].usual_grade*0.3) + (int)(stu[i].final_grade*0.7);
	}
}