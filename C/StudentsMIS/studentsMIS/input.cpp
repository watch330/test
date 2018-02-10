#include "main.h"
int input(struct student stu[])
{
	int i = 0, n;
	FILE *fp;
	fp = fopen("students.txt", "r");
	if (fp == NULL)
	{
		printf("Error!File open failed!");
		exit(0);
	}
	while (fscanf(fp, "%s%s", stu[i].ID, stu[i].name) != EOF) i++;
	for (n = i, i = 0; i < n; i++)
	{
		printf("%s\t%s\t", stu[i].ID, stu[i].name);
		scanf("%d%d", &stu[i].usual_grade, &stu[i].final_grade);
	}
	fclose(fp);
	return n;
}