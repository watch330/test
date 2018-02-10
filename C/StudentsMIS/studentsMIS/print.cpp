#include "main.h"
void print(struct student stu[], int n)
{
	int i;
	FILE *fp;
	fp = fopen("grades.txt", "w");
	for (i = 0; i < n; i++)
	{
		printf("%s\t%s\t%d\t%d\t%d\n", stu[i].ID, stu[i].name,
			stu[i].usual_grade, stu[i].final_grade, stu[i].grade);
		fprintf(fp, "%s\t%s\t%d\t%d\t%d\n", stu[i].ID, stu[i].name,
			stu[i].usual_grade, stu[i].final_grade, stu[i].grade);
	}
	fclose(fp);
}