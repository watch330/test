#include "main.h"
#include "input.h"
#include "process.h"
#include "print.h"
int main()
{
	int numbers=0,choice,flag=0;
	struct student stu[50];
	printf("****************Students_Information_Manager_System****************\n");
	printf("*          1.Input                             2.Process          *\n");
	printf("*          3.Print                             0.EXIT             *\n");
	printf("*******************************************************************\n");
	while (scanf("%d", &choice) != -1&&choice!=0)
	{
		switch (choice)
		{
		case 1:
			numbers = input(stu);
			if (numbers == 0)
			{
				printf("Data input failed!\n");
				system("pause");
				exit(0);
			}
			printf("Date input completed!\n");
			break;
		case 2:
			if (numbers == 0)
			{
				printf("Please input data first!\n");
				continue;
			}
			process(stu, numbers);
			flag = 1;
			printf("Date process completed!\n");
			break;
		case 3:
			if (flag == 0)
			{
				printf("Please process data first!\n");
				continue;
			}
			print(stu, numbers);
			printf("File create sucecessfully!\n");
			break;
		default:
			printf("Wrong choise!Please enter 1,2,3,4 or 0!\n");
		}
	}
	system("pause");
	return 0;
}