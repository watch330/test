#include <windows.h>
#include <stdio.h>

void setPos(int x, int y)
{
	COORD pos;
	HANDLE handle;
	pos.X = x;
	pos.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void tab(int x, int y, char c)
{
	setPos(x, y);
	printf("%c", c);
}