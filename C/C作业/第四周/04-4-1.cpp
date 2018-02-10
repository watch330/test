#include <stdio.h>
#include <math.h>
int main()
{
	int num;
	float root;

	printf("Please enter a real number(>=0):");
	scanf("%d", &num);
	if (num >= 0)
	{
		root = sqrt(num);
		printf("The square root is %.2f\n", root);
	}
	else
		printf("The number is error!\n");

	return 0;
				
}