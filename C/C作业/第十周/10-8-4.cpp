#include <stdio.h>
void fun(char *str)
{	
	char *p;
	for (p = str; *p != '\0'; p++)
		if (*p >= 'a'&&*p <= 'z')
			*p -= 32;
}
int main()
{
	char str[50];

	printf("ÇëÊäÈë:\n");
	gets_s(str);
	fun(str);
	puts(str);
	return 0;
}