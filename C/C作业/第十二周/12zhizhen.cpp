#include <stdio.h>
#include <stdlib.h>
struct student {
	char ID[10];
	char name[10];
	int grade;
};
void input(struct student *stu,int *n);
void sort(struct student **pstu, int num);
int main()
{	
	int i;
	int num=0,*n;
	n = &num;
	struct student stu[30],*pstu[30];
	printf("请输入分数\n");
	input(stu, n);
	for (i = 0; i<num; i++)
	{
		pstu[i] = stu+i;
	}
	sort(pstu, num);
	printf("排序后:\n");
	printf("指针数组输出:\t\t\t结构体数组输出:\n");
	for (i = 0; i < num; i++)
	{
		printf("%s\t%s\t%d\t",pstu[i]->ID, pstu[i]->name, pstu[i]->grade);
		printf("%s\t%s\t%d\n", stu[i].ID, stu[i].name, stu[i].grade);
	}
	return 0;
}
void input(struct student *stu,int *n)
{
	int i;
	int num=0;
	FILE *fp;
	fp = fopen("students.txt", "r");
	if (fp == NULL)
	{
		printf("Error!File open failed!");
		exit(1);
	}
	while (fscanf(fp, "%s%s", stu[num].ID, stu[num].name) != EOF) num++;
	fclose(fp);
	*n = num;
	for (i=0; i<num; i++)
	{
		printf("%s\t%s\t", stu[i].ID, stu[i].name);
		scanf("%d", &stu[i].grade);
	}
	printf("\n");
}
void sort(struct student **pstu, int num)
{	
	int i,j,k;
	struct student *t;
	for (i = 0; i < num - 1; i++)
	{
		k = i;
		for (j = i + 1; j < num; j++)
			if (pstu[j]->grade > pstu[k]->grade) k = j;
		t = pstu[k];
		pstu[k] = pstu[i];
		pstu[i] = t;
	}
}