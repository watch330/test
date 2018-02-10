#include <stdio.h>
int main()
{
	char a[3];

	while (scanf("%s", &a) !=EOF)
	{
		if (a[0] >= a[1])
		{
			if (a[1] >= a[2])
			{
				printf("%c %c %c\n", a[2], a[1], a[0]);
				
			}
			else
			{
				if (a[0] >= a[2])
				{
					printf("%c %c %c\n", a[1], a[2], a[0]);
					
				}
				else
				{
					printf("%c %c %c\n", a[1], a[0], a[2]);
					
				}
			}
		}
		else
		{
			if (a[0] >= a[2])
			{
				printf("%c %c %c\n", a[2], a[0], a[1]);
				
			}
			else
			{
				if (a[2] >= a[1])
				{
					printf("%c %c %c\n", a[0], a[1], a[2]);
					
				}
				else
				{
					printf("%c %c %c\n", a[0], a[2], a[1]);
					
				}
			}
		}
	}

	return 0;
}