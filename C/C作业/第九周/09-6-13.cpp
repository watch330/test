#include <stdio.h>
void word_count(char a[]);
void word_get(char a[],char w[][16]);
void word_upper(char a[]);
void word_print(char w[][16]);
static int count = 0;
int main()
{	
	char a[121], words[20][16];

	printf("ÇëÊäÈë:\n");
	gets_s(a);
	word_count(a);
	word_get(a,words);
	word_upper(a);
	puts(a);
	word_print(words);
	return 0;
}

void word_count(char a[])
{	
	int i;
	if (a[0] >= 'a' && a[0] <= 'z')
		count++;
	for (i = 1; a[i] != '\0'; i++)
		if (a[i] >= 'a'&&a[i] <= 'z'
			&&a[i - 1] == ' '||a[i - 1] == ','||a[i - 1] == '.'
			||a[i - 1] == '?'||a[i - 1] == '!')
			count++;
}

void word_get(char a[],char w[][16])
{
	int i,j,k;
	k = 0;
	for (i = 0; i < count; i++) 
	{	

		for (j = 0; 1; j++)
		{
			if (a[k] != ' ' && a[k] != ',' && a[k] != '!' && a[k] != '?')
			{
				w[i][j] = a[k];
				k++;
			}
			else
			{
				k++;
				break;
			}
		}
		w[i][j] = '\0';
	}
}

void word_upper(char a[])
{	
	int i;
	if (a[0] >= 'a'&&a[0] <= 'z')
		a[0] -= 32;
	for (i = 1; a[i] != '\0'; i++)
		if (a[i] >= 'a'&&a[i] <= 'z'&&a[i - 1] == ' ')
			a[i] -= 32;
}

void word_print(char w[][16])
{
	int i,j;
	
	for (i = 0; i < count; i++)
	{
		for (j = 0; w[i][j] != '\0'; j++)
			printf("%c", w[i][j]);
		printf("\n");
	}
}
