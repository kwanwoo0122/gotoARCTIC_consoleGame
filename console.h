#pragma once
#include <stdio.h>
#include <windows.h>
#include "fullscreenConsole.h"

extern int WIDTH;
extern int HEIGHT;

void gotoxy(int x, int y) // 좌표이동 함수, gotoxy
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void clearCursor() //커서 제거
{
	CONSOLE_CURSOR_INFO c;
	c.bVisible = FALSE;
	c.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
}

void backgroundSetting() //기본 설정
{
	fullscreenConsole();
	WIDTH = bufSize.X;
	HEIGHT = bufSize.Y;
	clearCursor();
}